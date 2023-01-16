/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_TraitementEMGV1_mex.c
 *
 * Code generation for function '_coder_TraitementEMGV1_mex'
 *
 */

/* Include files */
#include "_coder_TraitementEMGV1_mex.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_initialize.h"
#include "TraitementEMGV1_terminate.h"
#include "TraitementEMGV1_types.h"
#include "_coder_TraitementEMGV1_api.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void TraitementEMGV1_mexFunction(TraitementEMGV1StackData *SD, int32_T nlhs,
  mxArray *plhs[6], int32_T nrhs, const mxArray *prhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[6];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        15, "TraitementEMGV1");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "TraitementEMGV1");
  }

  /* Call the function. */
  TraitementEMGV1_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  TraitementEMGV1StackData *TraitementEMGV1StackDataGlobal = NULL;
  TraitementEMGV1StackDataGlobal = (TraitementEMGV1StackData *)emlrtMxCalloc(1,
    (size_t)1U * sizeof(TraitementEMGV1StackData));
  mexAtExit(&TraitementEMGV1_atexit);

  /* Module initialization. */
  TraitementEMGV1_initialize();

  /* Dispatch the entry-point. */
  TraitementEMGV1_mexFunction(TraitementEMGV1StackDataGlobal, nlhs, plhs, nrhs,
    prhs);

  /* Module termination. */
  TraitementEMGV1_terminate();
  emlrtMxFree(TraitementEMGV1StackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_TraitementEMGV1_mex.c) */
