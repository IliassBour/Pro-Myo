/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filtfilt.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "filtfilt.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_internal_types.h"
#include "TraitementEMGV1_types.h"
#include "filter.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "rt_nonfinite.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double b[5]
 *                const double a[5]
 *                double x[60501]
 * Return Type  : void
 */
void filtfilt(const double b[5], const double a[5], double x[60501])
{
  static double yc2[60501];
  static double yc5[60501];
  static const signed char cidxInt[10] = { 1, 1, 1, 1, 2, 3, 4, 2, 3, 4 };

  static const signed char ridxInt[10] = { 1, 2, 3, 4, 2, 3, 4, 1, 2, 3 };

  cs_di* cxA;
  cs_din * N;
  cs_dis * S;
  cell_wrap_38 this_tunableEnvironment[2];
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  double unusedU0[12];
  double xt[12];
  double yc3[12];
  double vals[10];
  double a_data[5];
  double b_data[5];
  double outBuff[4];
  double outBuff_data[4];
  double zo_data[4];
  double a1;
  double b_a1;
  double d;
  double tol;
  int sortedIndices[10];
  int zo_size[1];
  int cptr;
  int currRowIdx;
  int k;
  int ridx;
  signed char b_cidxInt[10];
  signed char b_ridxInt[10];
  boolean_T b1;
  boolean_T b_b;
  emxInit_real_T(&y_d, 1);
  emxInit_int32_T(&y_colidx, 1);
  emxInit_int32_T(&y_rowidx, 1);
  vals[0] = a[1] + 1.0;
  vals[1] = a[2];
  vals[4] = 1.0;
  vals[7] = -1.0;
  vals[2] = a[3];
  vals[5] = 1.0;
  vals[8] = -1.0;
  vals[3] = a[4];
  vals[6] = 1.0;
  vals[9] = -1.0;
  outBuff[0] = b[1] - b[0] * a[1];
  outBuff[1] = b[2] - b[0] * a[2];
  outBuff[2] = b[3] - b[0] * a[3];
  outBuff[3] = b[4] - b[0] * a[4];
  for (k = 0; k < 10; k++) {
    sortedIndices[k] = k + 1;
    this_tunableEnvironment[0].f1[k] = cidxInt[k];
    this_tunableEnvironment[1].f1[k] = ridxInt[k];
  }

  introsort(sortedIndices, this_tunableEnvironment);
  cptr = y_d->size[0];
  y_d->size[0] = 10;
  emxEnsureCapacity_real_T(y_d, cptr);
  cptr = y_colidx->size[0];
  y_colidx->size[0] = 5;
  emxEnsureCapacity_int32_T(y_colidx, cptr);
  y_colidx->data[0] = 1;
  cptr = y_rowidx->size[0];
  y_rowidx->size[0] = 10;
  emxEnsureCapacity_int32_T(y_rowidx, cptr);
  for (k = 0; k < 10; k++) {
    cptr = sortedIndices[k];
    b_cidxInt[k] = cidxInt[cptr - 1];
    b_ridxInt[k] = ridxInt[cptr - 1];
    y_d->data[k] = 0.0;
    y_rowidx->data[k] = 0;
  }

  cptr = 0;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 1)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[1] = cptr + 1;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 2)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[2] = cptr + 1;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 3)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[3] = cptr + 1;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 4)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[4] = cptr + 1;
  for (k = 0; k < 10; k++) {
    y_d->data[k] = vals[sortedIndices[k] - 1];
  }

  cptr = 1;
  ridx = y_colidx->data[0];
  y_colidx->data[0] = 1;
  while (ridx < y_colidx->data[1]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[1]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[1];
  y_colidx->data[1] = cptr;
  while (ridx < y_colidx->data[2]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[2]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[2];
  y_colidx->data[2] = cptr;
  while (ridx < y_colidx->data[3]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[3]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[3];
  y_colidx->data[3] = cptr;
  while (ridx < y_colidx->data[4]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[4]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  y_colidx->data[4] = cptr;
  cxA = makeCXSparseMatrix(y_colidx->data[4] - 1, 4, 4, &y_colidx->data[0],
    &y_rowidx->data[0], &y_d->data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(y_colidx->data[4] - 1, 4, 4, &y_colidx->data[0],
      &y_rowidx->data[0], &y_d->data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&outBuff[0], 4, 4);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 4);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }

  emxFree_int32_T(&y_rowidx);
  emxFree_int32_T(&y_colidx);
  emxFree_real_T(&y_d);
  tol = a[0];
  a1 = a[0];
  b_a1 = a[0];
  d = 2.0 * x[0];
  for (cptr = 0; cptr < 12; cptr++) {
    xt[cptr] = -x[12 - cptr] + d;
  }

  for (cptr = 0; cptr < 5; cptr++) {
    b_data[cptr] = b[cptr];
    a_data[cptr] = a[cptr];
  }

  outBuff_data[0] = outBuff[0] * xt[0];
  outBuff_data[1] = outBuff[1] * xt[0];
  outBuff_data[2] = outBuff[2] * xt[0];
  outBuff_data[3] = outBuff[3] * xt[0];
  filter(b_data, a_data, xt, outBuff_data, unusedU0, zo_data, zo_size);
  for (cptr = 0; cptr < 5; cptr++) {
    b_data[cptr] = b[cptr];
    a_data[cptr] = a[cptr];
  }

  b_b = rtIsInf(a[0]);
  b1 = rtIsNaN(a[0]);
  if ((!b_b) && (!b1) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
    for (k = 0; k < 5; k++) {
      b_data[k] /= tol;
    }

    a_data[1] /= a[0];
    a_data[2] /= a[0];
    a_data[3] /= a[0];
    a_data[4] /= a[0];
    a_data[0] = 1.0;
  }

  outBuff_data[0] = 0.0;
  yc2[0] = zo_data[0];
  outBuff_data[1] = 0.0;
  yc2[1] = zo_data[1];
  outBuff_data[2] = 0.0;
  yc2[2] = zo_data[2];
  outBuff_data[3] = 0.0;
  yc2[3] = zo_data[3];
  memset(&yc2[4], 0, 60497U * sizeof(double));
  for (k = 0; k < 60501; k++) {
    if (60501 - k < 5) {
      ridx = 60500 - k;
    } else {
      ridx = 4;
    }

    for (currRowIdx = 0; currRowIdx <= ridx; currRowIdx++) {
      cptr = k + currRowIdx;
      yc2[cptr] += x[k] * b_data[currRowIdx];
    }

    if (60500 - k < 4) {
      ridx = 60499 - k;
    } else {
      ridx = 3;
    }

    tol = -yc2[k];
    for (currRowIdx = 0; currRowIdx <= ridx; currRowIdx++) {
      cptr = (k + currRowIdx) + 1;
      yc2[cptr] += tol * a_data[currRowIdx + 1];
    }
  }

  for (currRowIdx = 0; currRowIdx < 1; currRowIdx++) {
    outBuff_data[0] += x[60497] * b_data[4];
  }

  for (currRowIdx = 0; currRowIdx < 2; currRowIdx++) {
    outBuff_data[currRowIdx] += x[60498] * b_data[currRowIdx + 3];
  }

  for (currRowIdx = 0; currRowIdx < 3; currRowIdx++) {
    outBuff_data[currRowIdx] += x[60499] * b_data[currRowIdx + 2];
  }

  for (currRowIdx = 0; currRowIdx < 4; currRowIdx++) {
    outBuff_data[currRowIdx] += x[60500] * b_data[currRowIdx + 1];
  }

  for (currRowIdx = 0; currRowIdx < 1; currRowIdx++) {
    outBuff_data[0] += -yc2[60497] * a_data[4];
  }

  for (currRowIdx = 0; currRowIdx < 2; currRowIdx++) {
    outBuff_data[currRowIdx] += -yc2[60498] * a_data[currRowIdx + 3];
  }

  for (currRowIdx = 0; currRowIdx < 3; currRowIdx++) {
    outBuff_data[currRowIdx] += -yc2[60499] * a_data[currRowIdx + 2];
  }

  for (currRowIdx = 0; currRowIdx < 4; currRowIdx++) {
    outBuff_data[currRowIdx] += -yc2[60500] * a_data[currRowIdx + 1];
  }

  d = 2.0 * x[60500];
  for (cptr = 0; cptr < 12; cptr++) {
    xt[cptr] = -x[60499 - cptr] + d;
  }

  for (cptr = 0; cptr < 5; cptr++) {
    b_data[cptr] = b[cptr];
    a_data[cptr] = a[cptr];
  }

  if ((!b_b) && (!b1) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
    for (k = 0; k < 5; k++) {
      b_data[k] /= a1;
    }

    a_data[1] /= a[0];
    a_data[2] /= a[0];
    a_data[3] /= a[0];
    a_data[4] /= a[0];
    a_data[0] = 1.0;
  }

  yc3[0] = outBuff_data[0];
  yc3[1] = outBuff_data[1];
  yc3[2] = outBuff_data[2];
  yc3[3] = outBuff_data[3];
  memset(&yc3[4], 0, 8U * sizeof(double));
  for (k = 0; k < 12; k++) {
    if (12 - k < 5) {
      ridx = 11 - k;
    } else {
      ridx = 4;
    }

    for (currRowIdx = 0; currRowIdx <= ridx; currRowIdx++) {
      cptr = k + currRowIdx;
      yc3[cptr] += xt[k] * b_data[currRowIdx];
    }

    if (11 - k < 4) {
      ridx = 10 - k;
    } else {
      ridx = 3;
    }

    tol = -yc3[k];
    for (currRowIdx = 0; currRowIdx <= ridx; currRowIdx++) {
      cptr = (k + currRowIdx) + 1;
      yc3[cptr] += tol * a_data[currRowIdx + 1];
    }
  }

  tol = yc3[11];
  for (cptr = 0; cptr < 5; cptr++) {
    b_data[cptr] = b[cptr];
    a_data[cptr] = a[cptr];
  }

  for (cptr = 0; cptr < 12; cptr++) {
    xt[cptr] = yc3[11 - cptr];
  }

  memcpy(&yc3[0], &xt[0], 12U * sizeof(double));
  outBuff_data[0] = outBuff[0] * tol;
  outBuff_data[1] = outBuff[1] * tol;
  outBuff_data[2] = outBuff[2] * tol;
  outBuff_data[3] = outBuff[3] * tol;
  filter(b_data, a_data, yc3, outBuff_data, unusedU0, zo_data, zo_size);
  for (cptr = 0; cptr < 5; cptr++) {
    b_data[cptr] = b[cptr];
    a_data[cptr] = a[cptr];
  }

  if ((!b_b) && (!b1) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
    for (k = 0; k < 5; k++) {
      b_data[k] /= b_a1;
    }

    a_data[1] /= a[0];
    a_data[2] /= a[0];
    a_data[3] /= a[0];
    a_data[4] /= a[0];
    a_data[0] = 1.0;
  }

  yc5[0] = zo_data[0];
  yc5[1] = zo_data[1];
  yc5[2] = zo_data[2];
  yc5[3] = zo_data[3];
  memset(&yc5[4], 0, 60497U * sizeof(double));
  for (k = 0; k < 60501; k++) {
    if (60501 - k < 5) {
      ridx = 60500 - k;
    } else {
      ridx = 4;
    }

    for (currRowIdx = 0; currRowIdx <= ridx; currRowIdx++) {
      cptr = k + currRowIdx;
      yc5[cptr] += yc2[60500 - k] * b_data[currRowIdx];
    }

    if (60500 - k < 4) {
      ridx = 60499 - k;
    } else {
      ridx = 3;
    }

    tol = -yc5[k];
    for (currRowIdx = 0; currRowIdx <= ridx; currRowIdx++) {
      cptr = (k + currRowIdx) + 1;
      yc5[cptr] += tol * a_data[currRowIdx + 1];
    }
  }

  for (cptr = 0; cptr < 60501; cptr++) {
    x[cptr] = yc5[60500 - cptr];
  }
}

/*
 * File trailer for filtfilt.c
 *
 * [EOF]
 */
