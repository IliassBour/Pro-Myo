/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1_initialize.c
 *
 * Code generation for function 'TraitementEMGV1_initialize'
 *
 */

/* Include files */
#include "TraitementEMGV1_initialize.h"
#include "TraitementEMGV1_data.h"
#include "_coder_TraitementEMGV1_mex.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void TraitementEMGV1_once(void);

/* Function Definitions */
static void TraitementEMGV1_once(void)
{
  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance, "D:\\TESTEMG\\TraitementEMGV1.m", 0U,
                  1U, 3U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "TraitementEMGV1", 0, -1, 2105);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1998, -1, 2019);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1952, -1, 1975);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 139, -1, 1887);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1923, 1941, 1983, 2030);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1903, 1917, 2045);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void TraitementEMGV1_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "signal_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    TraitementEMGV1_once();
  }
}

/* End of code generation (TraitementEMGV1_initialize.c) */
