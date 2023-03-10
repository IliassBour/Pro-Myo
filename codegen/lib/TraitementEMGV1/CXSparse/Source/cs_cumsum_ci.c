#ifndef CS_COMPLEX
#define CS_COMPLEX
#endif
#include "cs.h"
/* p [0..n] = cumulative sum of c [0..n-1], and then copy p [0..n-1] into c */
double cs_cumsum(CS_INT* p, CS_INT* c, CS_INT n) {
    CS_INT i, nz = 0;
    double nz2 = 0;
    if (!p || !c) {
        return (-1);
    } /* check inputs */
    for (i = 0; i < n; i++) {
        p[i] = nz;
        nz += c[i];
        nz2 += c[i]; /* also in double to avoid CS_INT overflow */
        c[i] = p[i]; /* also copy p[0..n-1] back into c[0..n-1]*/
    }
    p[n] = nz;
    return (nz2); /* return sum (c [0..n-1]) */
}
