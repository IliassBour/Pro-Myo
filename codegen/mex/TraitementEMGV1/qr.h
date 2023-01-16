/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qr.h
 *
 * Code generation for function 'qr'
 *
 */

#pragma once

/* Include files */
#include "TraitementEMGV1_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void qr(TraitementEMGV1StackData *SD, const emlrtStack *sp, const real_T A
        [121002], real_T Q[121002], real_T R[4]);

/* End of code generation (qr.h) */
