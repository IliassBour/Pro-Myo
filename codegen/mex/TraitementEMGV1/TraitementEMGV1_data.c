/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1_data.c
 *
 * Code generation for function 'TraitementEMGV1_data'
 *
 */

/* Include files */
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "TraitementEMGV1",                   /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 497312255U, 2566552405U, 2553285182U, 2715458501U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo gb_emlrtRSI = { 71,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 64,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 37,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 45,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 45,        /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 15,        /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 41,        /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 54,        /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 76,        /* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 102,       /* lineNo */
  "cat_impl",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 28,        /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

emlrtRSInfo lf_emlrtRSI = { 90,        /* lineNo */
  "warn_singular",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

emlrtRSInfo sf_emlrtRSI = { 67,        /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

emlrtRSInfo uf_emlrtRSI = { 112,       /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

emlrtRTEInfo d_emlrtRTEI = { 283,      /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

emlrtRTEInfo f_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

emlrtRTEInfo g_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

emlrtRTEInfo p_emlrtRTEI = { 47,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtRTEInfo q_emlrtRTEI = { 44,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtRTEInfo r_emlrtRTEI = { 146,      /* lineNo */
  5,                                   /* colNo */
  "filter",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m"/* pName */
};

emlrtRTEInfo s_emlrtRTEI = { 144,      /* lineNo */
  5,                                   /* colNo */
  "filter",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m"/* pName */
};

covrtInstance emlrtCoverageInstance;

/* End of code generation (TraitementEMGV1_data.c) */
