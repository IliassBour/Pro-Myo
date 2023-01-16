/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eigStandard.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "eigStandard.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_rtwutil.h"
#include "rt_nonfinite.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[16]
 *                creal_T V[4]
 * Return Type  : void
 */
void eigStandard(const double A[16], creal_T V[4])
{
  creal_T At[16];
  creal_T beta1[4];
  creal_T atmp;
  double a;
  double absxk;
  double anrm;
  double anrmto;
  double cto1;
  double ctoc;
  double stemp_im;
  int At_tmp;
  int exitg2;
  int exitg3;
  int i;
  int ihi;
  int ii;
  int ilo;
  int j;
  int jcol;
  int jcolp1;
  int jrow;
  int nzcount;
  boolean_T exitg1;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T ilascl;
  boolean_T notdone;
  for (ii = 0; ii < 16; ii++) {
    At[ii].re = A[ii];
    At[ii].im = 0.0;
  }

  anrm = 0.0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 16)) {
    absxk = rt_hypotd_snf(At[ii].re, At[ii].im);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      ii++;
    }
  }

  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    beta1[0].re = rtNaN;
    beta1[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
    beta1[1].re = rtNaN;
    beta1[1].im = 0.0;
    V[2].re = rtNaN;
    V[2].im = 0.0;
    beta1[2].re = rtNaN;
    beta1[2].im = 0.0;
    V[3].re = rtNaN;
    V[3].im = 0.0;
    beta1[3].re = rtNaN;
    beta1[3].im = 0.0;
  } else {
    ilascl = false;
    anrmto = anrm;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
      guard1 = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
        guard1 = true;
      }
    }

    if (guard1) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        stemp_im = absxk * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((stemp_im > ctoc) && (ctoc != 0.0)) {
          a = 2.0041683600089728E-292;
          absxk = stemp_im;
        } else if (cto1 > absxk) {
          a = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          a = ctoc / absxk;
          notdone = false;
        }

        for (ii = 0; ii < 16; ii++) {
          At[ii].re *= a;
          At[ii].im *= a;
        }
      }
    }

    ilo = 1;
    ihi = 4;
    do {
      exitg3 = 0;
      i = 0;
      j = 0;
      notdone = false;
      ii = ihi;
      exitg1 = false;
      while ((!exitg1) && (ii > 0)) {
        nzcount = 0;
        i = ii;
        j = ihi;
        jcol = 0;
        exitg4 = false;
        while ((!exitg4) && (jcol <= ihi - 1)) {
          At_tmp = (ii + (jcol << 2)) - 1;
          if ((At[At_tmp].re != 0.0) || (At[At_tmp].im != 0.0) || (ii == jcol +
               1)) {
            if (nzcount == 0) {
              j = jcol + 1;
              nzcount = 1;
              jcol++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            jcol++;
          }
        }

        if (nzcount < 2) {
          notdone = true;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (!notdone) {
        exitg3 = 2;
      } else {
        if (i != ihi) {
          atmp = At[i - 1];
          At[i - 1] = At[ihi - 1];
          At[ihi - 1] = atmp;
          atmp = At[i + 3];
          At[i + 3] = At[ihi + 3];
          At[ihi + 3] = atmp;
          atmp = At[i + 7];
          At[i + 7] = At[ihi + 7];
          At[ihi + 7] = atmp;
          atmp = At[i + 11];
          At[i + 11] = At[ihi + 11];
          At[ihi + 11] = atmp;
        }

        if (j != ihi) {
          for (ii = 0; ii < ihi; ii++) {
            nzcount = ii + ((j - 1) << 2);
            atmp = At[nzcount];
            At_tmp = ii + ((ihi - 1) << 2);
            At[nzcount] = At[At_tmp];
            At[At_tmp] = atmp;
          }
        }

        ihi--;
        if (ihi == 1) {
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);

    if (exitg3 != 1) {
      do {
        exitg2 = 0;
        i = 0;
        j = 0;
        notdone = false;
        jcol = ilo;
        exitg1 = false;
        while ((!exitg1) && (jcol <= ihi)) {
          nzcount = 0;
          i = ihi;
          j = jcol;
          ii = ilo;
          exitg4 = false;
          while ((!exitg4) && (ii <= ihi)) {
            At_tmp = (ii + ((jcol - 1) << 2)) - 1;
            if ((At[At_tmp].re != 0.0) || (At[At_tmp].im != 0.0) || (ii == jcol))
            {
              if (nzcount == 0) {
                i = ii;
                nzcount = 1;
                ii++;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              ii++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            jcol++;
          }
        }

        if (!notdone) {
          exitg2 = 1;
        } else {
          if (i != ilo) {
            for (ii = ilo; ii < 5; ii++) {
              nzcount = (ii - 1) << 2;
              jcol = (i + nzcount) - 1;
              atmp = At[jcol];
              At_tmp = (ilo + nzcount) - 1;
              At[jcol] = At[At_tmp];
              At[At_tmp] = atmp;
            }
          }

          if (j != ilo) {
            for (ii = 0; ii < ihi; ii++) {
              nzcount = ii + ((j - 1) << 2);
              atmp = At[nzcount];
              At_tmp = ii + ((ilo - 1) << 2);
              At[nzcount] = At[At_tmp];
              At[At_tmp] = atmp;
            }
          }

          ilo++;
          if (ilo == ihi) {
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
    }

    if (ihi >= ilo + 2) {
      for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
        jcolp1 = jcol + 2;
        for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
          At_tmp = jrow + (jcol << 2);
          xzlartg(At[At_tmp - 1], At[At_tmp], &absxk, &atmp, &At[(jrow + (jcol <<
                    2)) - 1]);
          At[At_tmp].re = 0.0;
          At[At_tmp].im = 0.0;
          for (j = jcolp1; j < 5; j++) {
            nzcount = jrow + ((j - 1) << 2);
            ctoc = absxk * At[nzcount - 1].re + (atmp.re * At[nzcount].re -
              atmp.im * At[nzcount].im);
            stemp_im = absxk * At[nzcount - 1].im + (atmp.re * At[nzcount].im +
              atmp.im * At[nzcount].re);
            cto1 = At[nzcount - 1].re;
            At[nzcount].re = absxk * At[nzcount].re - (atmp.re * At[nzcount - 1]
              .re + atmp.im * At[nzcount - 1].im);
            At[nzcount].im = absxk * At[nzcount].im - (atmp.re * At[nzcount - 1]
              .im - atmp.im * cto1);
            At[nzcount - 1].re = ctoc;
            At[nzcount - 1].im = stemp_im;
          }

          atmp.re = -atmp.re;
          atmp.im = -atmp.im;
          for (i = 1; i <= ihi; i++) {
            nzcount = (i + ((jrow - 1) << 2)) - 1;
            ii = (i + (jrow << 2)) - 1;
            ctoc = absxk * At[ii].re + (atmp.re * At[nzcount].re - atmp.im *
              At[nzcount].im);
            stemp_im = absxk * At[ii].im + (atmp.re * At[nzcount].im + atmp.im *
              At[nzcount].re);
            cto1 = At[ii].re;
            At[nzcount].re = absxk * At[nzcount].re - (atmp.re * At[ii].re +
              atmp.im * At[ii].im);
            At[nzcount].im = absxk * At[nzcount].im - (atmp.re * At[ii].im -
              atmp.im * cto1);
            At[ii].re = ctoc;
            At[ii].im = stemp_im;
          }
        }
      }
    }

    xzhgeqz(At, ilo, ihi, &ii, V, beta1);
    if ((ii == 0) && ilascl) {
      notdone = true;
      while (notdone) {
        stemp_im = anrmto * 2.0041683600089728E-292;
        cto1 = anrm / 4.9896007738368E+291;
        if ((stemp_im > anrm) && (anrm != 0.0)) {
          a = 2.0041683600089728E-292;
          anrmto = stemp_im;
        } else if (cto1 > anrmto) {
          a = 4.9896007738368E+291;
          anrm = cto1;
        } else {
          a = anrm / anrmto;
          notdone = false;
        }

        V[0].re *= a;
        V[0].im *= a;
        V[1].re *= a;
        V[1].im *= a;
        V[2].re *= a;
        V[2].im *= a;
        V[3].re *= a;
        V[3].im *= a;
      }
    }
  }

  if (beta1[0].im == 0.0) {
    if (V[0].im == 0.0) {
      cto1 = V[0].re / beta1[0].re;
      absxk = 0.0;
    } else if (V[0].re == 0.0) {
      cto1 = 0.0;
      absxk = V[0].im / beta1[0].re;
    } else {
      cto1 = V[0].re / beta1[0].re;
      absxk = V[0].im / beta1[0].re;
    }
  } else if (beta1[0].re == 0.0) {
    if (V[0].re == 0.0) {
      cto1 = V[0].im / beta1[0].im;
      absxk = 0.0;
    } else if (V[0].im == 0.0) {
      cto1 = 0.0;
      absxk = -(V[0].re / beta1[0].im);
    } else {
      cto1 = V[0].im / beta1[0].im;
      absxk = -(V[0].re / beta1[0].im);
    }
  } else {
    stemp_im = fabs(beta1[0].re);
    absxk = fabs(beta1[0].im);
    if (stemp_im > absxk) {
      absxk = beta1[0].im / beta1[0].re;
      ctoc = beta1[0].re + absxk * beta1[0].im;
      cto1 = (V[0].re + absxk * V[0].im) / ctoc;
      absxk = (V[0].im - absxk * V[0].re) / ctoc;
    } else if (absxk == stemp_im) {
      if (beta1[0].re > 0.0) {
        absxk = 0.5;
      } else {
        absxk = -0.5;
      }

      if (beta1[0].im > 0.0) {
        ctoc = 0.5;
      } else {
        ctoc = -0.5;
      }

      cto1 = (V[0].re * absxk + V[0].im * ctoc) / stemp_im;
      absxk = (V[0].im * absxk - V[0].re * ctoc) / stemp_im;
    } else {
      absxk = beta1[0].re / beta1[0].im;
      ctoc = beta1[0].im + absxk * beta1[0].re;
      cto1 = (absxk * V[0].re + V[0].im) / ctoc;
      absxk = (absxk * V[0].im - V[0].re) / ctoc;
    }
  }

  V[0].re = cto1;
  V[0].im = absxk;
  if (beta1[1].im == 0.0) {
    if (V[1].im == 0.0) {
      cto1 = V[1].re / beta1[1].re;
      absxk = 0.0;
    } else if (V[1].re == 0.0) {
      cto1 = 0.0;
      absxk = V[1].im / beta1[1].re;
    } else {
      cto1 = V[1].re / beta1[1].re;
      absxk = V[1].im / beta1[1].re;
    }
  } else if (beta1[1].re == 0.0) {
    if (V[1].re == 0.0) {
      cto1 = V[1].im / beta1[1].im;
      absxk = 0.0;
    } else if (V[1].im == 0.0) {
      cto1 = 0.0;
      absxk = -(V[1].re / beta1[1].im);
    } else {
      cto1 = V[1].im / beta1[1].im;
      absxk = -(V[1].re / beta1[1].im);
    }
  } else {
    stemp_im = fabs(beta1[1].re);
    absxk = fabs(beta1[1].im);
    if (stemp_im > absxk) {
      absxk = beta1[1].im / beta1[1].re;
      ctoc = beta1[1].re + absxk * beta1[1].im;
      cto1 = (V[1].re + absxk * V[1].im) / ctoc;
      absxk = (V[1].im - absxk * V[1].re) / ctoc;
    } else if (absxk == stemp_im) {
      if (beta1[1].re > 0.0) {
        absxk = 0.5;
      } else {
        absxk = -0.5;
      }

      if (beta1[1].im > 0.0) {
        ctoc = 0.5;
      } else {
        ctoc = -0.5;
      }

      cto1 = (V[1].re * absxk + V[1].im * ctoc) / stemp_im;
      absxk = (V[1].im * absxk - V[1].re * ctoc) / stemp_im;
    } else {
      absxk = beta1[1].re / beta1[1].im;
      ctoc = beta1[1].im + absxk * beta1[1].re;
      cto1 = (absxk * V[1].re + V[1].im) / ctoc;
      absxk = (absxk * V[1].im - V[1].re) / ctoc;
    }
  }

  V[1].re = cto1;
  V[1].im = absxk;
  if (beta1[2].im == 0.0) {
    if (V[2].im == 0.0) {
      cto1 = V[2].re / beta1[2].re;
      absxk = 0.0;
    } else if (V[2].re == 0.0) {
      cto1 = 0.0;
      absxk = V[2].im / beta1[2].re;
    } else {
      cto1 = V[2].re / beta1[2].re;
      absxk = V[2].im / beta1[2].re;
    }
  } else if (beta1[2].re == 0.0) {
    if (V[2].re == 0.0) {
      cto1 = V[2].im / beta1[2].im;
      absxk = 0.0;
    } else if (V[2].im == 0.0) {
      cto1 = 0.0;
      absxk = -(V[2].re / beta1[2].im);
    } else {
      cto1 = V[2].im / beta1[2].im;
      absxk = -(V[2].re / beta1[2].im);
    }
  } else {
    stemp_im = fabs(beta1[2].re);
    absxk = fabs(beta1[2].im);
    if (stemp_im > absxk) {
      absxk = beta1[2].im / beta1[2].re;
      ctoc = beta1[2].re + absxk * beta1[2].im;
      cto1 = (V[2].re + absxk * V[2].im) / ctoc;
      absxk = (V[2].im - absxk * V[2].re) / ctoc;
    } else if (absxk == stemp_im) {
      if (beta1[2].re > 0.0) {
        absxk = 0.5;
      } else {
        absxk = -0.5;
      }

      if (beta1[2].im > 0.0) {
        ctoc = 0.5;
      } else {
        ctoc = -0.5;
      }

      cto1 = (V[2].re * absxk + V[2].im * ctoc) / stemp_im;
      absxk = (V[2].im * absxk - V[2].re * ctoc) / stemp_im;
    } else {
      absxk = beta1[2].re / beta1[2].im;
      ctoc = beta1[2].im + absxk * beta1[2].re;
      cto1 = (absxk * V[2].re + V[2].im) / ctoc;
      absxk = (absxk * V[2].im - V[2].re) / ctoc;
    }
  }

  V[2].re = cto1;
  V[2].im = absxk;
  if (beta1[3].im == 0.0) {
    if (V[3].im == 0.0) {
      cto1 = V[3].re / beta1[3].re;
      absxk = 0.0;
    } else if (V[3].re == 0.0) {
      cto1 = 0.0;
      absxk = V[3].im / beta1[3].re;
    } else {
      cto1 = V[3].re / beta1[3].re;
      absxk = V[3].im / beta1[3].re;
    }
  } else if (beta1[3].re == 0.0) {
    if (V[3].re == 0.0) {
      cto1 = V[3].im / beta1[3].im;
      absxk = 0.0;
    } else if (V[3].im == 0.0) {
      cto1 = 0.0;
      absxk = -(V[3].re / beta1[3].im);
    } else {
      cto1 = V[3].im / beta1[3].im;
      absxk = -(V[3].re / beta1[3].im);
    }
  } else {
    stemp_im = fabs(beta1[3].re);
    absxk = fabs(beta1[3].im);
    if (stemp_im > absxk) {
      absxk = beta1[3].im / beta1[3].re;
      ctoc = beta1[3].re + absxk * beta1[3].im;
      cto1 = (V[3].re + absxk * V[3].im) / ctoc;
      absxk = (V[3].im - absxk * V[3].re) / ctoc;
    } else if (absxk == stemp_im) {
      if (beta1[3].re > 0.0) {
        absxk = 0.5;
      } else {
        absxk = -0.5;
      }

      if (beta1[3].im > 0.0) {
        ctoc = 0.5;
      } else {
        ctoc = -0.5;
      }

      cto1 = (V[3].re * absxk + V[3].im * ctoc) / stemp_im;
      absxk = (V[3].im * absxk - V[3].re * ctoc) / stemp_im;
    } else {
      absxk = beta1[3].re / beta1[3].im;
      ctoc = beta1[3].im + absxk * beta1[3].re;
      cto1 = (absxk * V[3].re + V[3].im) / ctoc;
      absxk = (absxk * V[3].im - V[3].re) / ctoc;
    }
  }

  V[3].re = cto1;
  V[3].im = absxk;
}

/*
 * File trailer for eigStandard.c
 *
 * [EOF]
 */
