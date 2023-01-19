/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TraitementEMGV1.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "TraitementEMGV1.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_initialize.h"
#include "TraitementEMGV1_types.h"
#include "butter.h"
#include "detrend.h"
#include "filtfilt.h"
#include "movSumProdOrMean.h"
#include "pwelch.h"
#include "rt_nonfinite.h"
#include "useConstantDim.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * %% 1-Donn�es
 * P = load('Course400mPiste.mat');
 * Arguments    : const struct0_T *P
 *                double Rect[60501]
 *                double MAW1[60501]
 *                double MAW2[60501]
 *                double MAW3[60501]
 *                double *TempsPousse
 *                double *TempsRecov
 * Return Type  : void
 */
void TraitementEMGV1(const struct0_T *P, double Rect[60501], double MAW1[60501],
                     double MAW2[60501], double MAW3[60501], double *TempsPousse,
                     double *TempsRecov)
{
  static double X[60501];
  static double b_P[60501];
  emxArray_real_T *F;
  emxArray_real_T *PSD;
  emxArray_real_T *b_PSD;
  emxArray_real_T *y;
  double a[5];
  double b[5];
  double dv[2];
  double Fc_data[1];
  double Seuil;
  double apnd;
  double cdiff;
  int i;
  int idx;
  int k;
  int nx;
  int x_size_idx_1;
  short ii_data[1];
  boolean_T x_data[16384];
  boolean_T exitg1;
  if (!isInitialized_TraitementEMGV1) {
    TraitementEMGV1_initialize();
  }

  /*  Fr�quence d'�chantillonage (Hz) */
  /*  Vecteur temps de l'�chantillon */
  /*  Largeur de fen�tre #1 */
  /*  Largeur de fen�tre #2 */
  /*  Largeur de fen�tre #3 */
  /*     %% 2-�liminer DC et tendance lin�aire */
  Seuil = P->EMG[181503];
  for (k = 0; k < 60500; k++) {
    Seuil += P->EMG[k + 181504];
  }
  
  Seuil /= 60501.0;
  printf("seuil: %f", Seuil);
  /*  eliminer le DC */
  for (i = 0; i < 60501; i++) {
    b_P[i] = P->EMG[i + 181503] - Seuil;
  }

  emxInit_real_T(&PSD, 2);
  emxInit_real_T(&F, 1);
  detrend(b_P, X);

  /*  �lminier la tendance lin�aire */
  /*     %% 3-Filtrer */
  pwelch(X, PSD, F);

  /*  Estimation de la densit� spectrale de puissance du signal */
  nx = PSD->size[0] * PSD->size[1];
  for (k = 0; k < nx; k++) {
    PSD->data[k] = log10(PSD->data[k]);
  }

  nx = PSD->size[0] * PSD->size[1];
  for (i = 0; i < nx; i++) {
    PSD->data[i] *= 10.0;
  }

  /*  Conversion en dB/Hz */
  if ((PSD->size[0] == 0) || (PSD->size[1] == 0)) {
    nx = 0;
  } else {
    nx = PSD->size[0];
    if (nx <= 1) {
      nx = 1;
    }
  }

  i = (int)rt_roundd_snf(0.9 * (double)nx);
  if (i > PSD->size[0]) {
    i = -1;
    nx = -1;
  } else {
    i -= 2;
    nx = PSD->size[0] - 1;
  }

  nx -= i;
  if (nx == 0) {
    Seuil = 0.0;
  } else {
    Seuil = PSD->data[i + 1];
    for (k = 2; k <= nx; k++) {
      Seuil += PSD->data[i + k];
    }
  }

  emxInit_real_T(&b_PSD, 1);
  Seuil /= (double)nx;
  nx = PSD->size[0] - 1;
  i = b_PSD->size[0];
  b_PSD->size[0] = PSD->size[0];
  emxEnsureCapacity_real_T(b_PSD, i);
  for (i = 0; i <= nx; i++) {
    b_PSD->data[i] = PSD->data[i] - Seuil;
  }

  nx = b_PSD->size[0];
  for (i = 0; i < nx; i++) {
    PSD->data[i] = b_PSD->data[i];
  }

  emxFree_real_T(&b_PSD);

  /*  �liminer le bruit */
  nx = 2;
  if (PSD->size[0] != 1) {
    nx = 1;
  }

  useConstantDim(PSD, nx);

  /*  Somme cumul�e du PSD */
  if ((PSD->size[0] == 0) || (PSD->size[1] == 0)) {
    nx = 0;
  } else {
    nx = PSD->size[0];
    if (nx <= 1) {
      nx = 1;
    }
  }

  emxInit_real_T(&y, 2);
  Seuil = 0.9 * (double)nx;
  if (PSD->size[0] < Seuil) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (floor(Seuil) == Seuil) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)floor((double)PSD->size[0] - Seuil) + 1;
    emxEnsureCapacity_real_T(y, i);
    nx = (int)floor((double)PSD->size[0] - Seuil);
    for (i = 0; i <= nx; i++) {
      y->data[i] = Seuil + (double)i;
    }
  } else {
    nx = (int)floor(((double)PSD->size[0] - Seuil) + 0.5);
    apnd = Seuil + (double)nx;
    cdiff = apnd - (double)PSD->size[0];
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(Seuil, PSD->size[0])) {
      nx++;
      apnd = PSD->size[0];
    } else if (cdiff > 0.0) {
      apnd = Seuil + ((double)nx - 1.0);
    } else {
      nx++;
    }

    if (nx >= 0) {
      idx = nx;
    } else {
      idx = 0;
    }

    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = idx;
    emxEnsureCapacity_real_T(y, i);
    if (idx > 0) {
      y->data[0] = Seuil;
      if (idx > 1) {
        y->data[idx - 1] = apnd;
        nx = (idx - 1) / 2;
        for (k = 0; k <= nx - 2; k++) {
          y->data[k + 1] = Seuil + ((double)k + 1.0);
          y->data[(idx - k) - 2] = apnd - ((double)k + 1.0);
        }

        if (nx << 1 == idx - 1) {
          y->data[nx] = (Seuil + apnd) / 2.0;
        } else {
          y->data[nx] = Seuil + (double)nx;
          y->data[nx + 1] = apnd - (double)nx;
        }
      }
    }
  }

  nx = y->size[1];
  for (k = 0; k < nx; k++) {
    y->data[k] = rt_roundd_snf(y->data[k]);
  }

  nx = y->size[1];
  if (y->size[1] == 0) {
    Seuil = 0.0;
  } else {
    Seuil = PSD->data[(int)y->data[0] - 1];
    for (k = 2; k <= nx; k++) {
      Seuil += PSD->data[(int)y->data[k - 1] - 1];
    }
  }

  /*  Moyenne des derniers 10% de la somme cumul�e */
  idx = PSD->size[0];
  x_size_idx_1 = PSD->size[1];
  Seuil = 0.95 * (Seuil / (double)y->size[1]);
  nx = PSD->size[0] * PSD->size[1];
  emxFree_real_T(&y);
  for (i = 0; i < nx; i++) {
    x_data[i] = (PSD->data[i] >= Seuil);
  }

  emxFree_real_T(&PSD);
  nx = idx * x_size_idx_1;
  k = (1 <= nx);
  idx = 0;
  x_size_idx_1 = 0;
  exitg1 = false;
  while ((!exitg1) && (x_size_idx_1 <= nx - 1)) {
    if (x_data[x_size_idx_1]) {
      idx = 1;
      ii_data[0] = (short)(x_size_idx_1 + 1);
      exitg1 = true;
    } else {
      x_size_idx_1++;
    }
  }

  if (k == 1) {
    if (idx == 0) {
      k = 0;
    }
  } else {
    k = (1 <= idx);
  }

  /*  Identification de l'index correspondant � la fr�quence de coupure */
  if (0 <= k - 1) {
    Fc_data[0] = F->data[ii_data[0] - 1];
  }

  emxFree_real_T(&F);
  for (nx = 0; nx < k; nx++) {
    Fc_data[0] = rt_roundd_snf(Fc_data[0]);
  }

  /*  Fr�quence de coupure */
  dv[0] = 0.04;
  if (0 <= k - 1) {
    dv[1] = Fc_data[0] / 500.0;
  }

  butter(dv, b, a);

  /*  Filtre passe-bande (20 Hz � Fc) */
  filtfilt(b, a, X);

  /*  Filtre d'ordre 2 */
  /*     %% 4-Rectifier */
  for (k = 0; k < 60501; k++) {
    Rect[k] = fabs(X[k]);
  }

  /*  Rectification par valeur absolue */
  vmovfun(Rect, MAW1);

  /*  Moyenne mobile centr�e #1 */
  b_vmovfun(Rect, MAW2);

  /*  Moyenne mobile centr�e #2 */
  c_vmovfun(Rect, MAW3);

  /*  Moyenne mobile centr�e #3 */
  /*     %% 5-Analyser */
  /*  Identifier les pics */
  cdiff = 0.0;
  apnd = 0.0;
  Seuil = Rect[0];
  for (k = 0; k < 60500; k++) {
    Seuil += Rect[k + 1];
  }

  Seuil /= 60501.0;
  for (nx = 0; nx < 56211; nx++) {
    if (MAW1[nx] < Seuil) {
      cdiff += 0.001;
    } else {
      apnd += 0.001;
    }
  }

  *TempsPousse = apnd / 128.0;
  *TempsRecov = cdiff / 128.0;
}

/*
 * File trailer for TraitementEMGV1.c
 *
 * [EOF]
 */
