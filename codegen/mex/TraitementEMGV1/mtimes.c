/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_mtimes(const real_T A[121002], const real_T B[2], real_T C[60501])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)60501;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)2;
  lda_t = (ptrdiff_t)60501;
  ldb_t = (ptrdiff_t)2;
  ldc_t = (ptrdiff_t)60501;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t, &beta1, &C[0], &ldc_t);
}

void mtimes(const real_T A[121002], const real_T B[60501], real_T C[2])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  TRANSB1 = 'N';
  TRANSA1 = 'T';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)2;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)60501;
  lda_t = (ptrdiff_t)60501;
  ldb_t = (ptrdiff_t)60501;
  ldc_t = (ptrdiff_t)2;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t, &beta1, &C[0], &ldc_t);
}

/* End of code generation (mtimes.c) */
