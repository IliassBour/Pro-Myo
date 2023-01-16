/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.h
 *
 * Code generation for function 'eml_setop'
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
void do_vectors(const emlrtStack *sp, const emxArray_int32_T *a, const
                emxArray_int32_T *b, emxArray_int32_T *c, emxArray_int32_T *ia,
                emxArray_int32_T *ib);

/* End of code generation (eml_setop.h) */
