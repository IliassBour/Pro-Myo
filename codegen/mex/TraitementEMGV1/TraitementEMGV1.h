/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1.h
 *
 * Code generation for function 'TraitementEMGV1'
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
void TraitementEMGV1(TraitementEMGV1StackData *SD, const emlrtStack *sp, const
                     struct0_T *P, real_T Rect[60501], real_T MAW1[60501],
                     real_T MAW2[60501], real_T MAW3[60501], real_T *TempsPousse,
                     real_T *TempsRecov);

/* End of code generation (TraitementEMGV1.h) */
