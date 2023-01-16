/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pwelch.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "pwelch.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include "welch.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[60501]
 *                emxArray_real_T *varargout_1
 *                emxArray_real_T *varargout_2
 * Return Type  : void
 */
void pwelch(const double x[60501], emxArray_real_T *varargout_1, emxArray_real_T
            *varargout_2)
{
  static const char t0_range[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  int units_size[2];
  char units_data[10];
  localComputeSpectra(x, t0_range, varargout_1, varargout_2, units_data,
                      units_size);
}

/*
 * File trailer for pwelch.c
 *
 * [EOF]
 */
