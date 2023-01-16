/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1_types.h
 *
 * Code generation for function 'TraitementEMGV1'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T position[285];
  real_T vitesse[285];
  real_T EMG[242004];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_uint16_T
#define struct_emxArray_uint16_T

struct emxArray_uint16_T
{
  uint16_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint16_T*/

#ifndef typedef_emxArray_uint16_T
#define typedef_emxArray_uint16_T

typedef struct emxArray_uint16_T emxArray_uint16_T;

#endif                                 /*typedef_emxArray_uint16_T*/

#ifndef typedef_TraitementEMGV1StackData
#define typedef_TraitementEMGV1StackData

typedef struct {
  union
  {
    struct {
      real_T yc2[60501];
      real_T yc5[60501];
    } f0;

    struct {
      real_T A[121002];
    } f1;
  } u1;

  struct {
    real_T W[121002];
    real_T Q[121002];
    real_T z1[60501];
  } f2;

  struct {
    real_T s[60501];
    int32_T y[60501];
  } f3;

  struct {
    real_T Y[60501];
    real_T X[60501];
  } f4;

  struct {
    struct0_T P;
  } f5;
} TraitementEMGV1StackData;

#endif                                 /*typedef_TraitementEMGV1StackData*/

/* End of code generation (TraitementEMGV1_types.h) */
