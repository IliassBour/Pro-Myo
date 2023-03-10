#ifndef CS_COMPLEX
#define CS_COMPLEX
#endif
#include "cs.h"
static CS_INT cs_tol(CS_INT i, CS_INT j, CS_ENTRY aij, void* tol) {
    (void) i;
    (void) j;
    return (CS_ABS(aij) > *((double*)tol));
}
CS_INT cs_droptol(cs* A, double tol) {
    return (cs_fkeep(A, &cs_tol, &tol)); /* keep all large entries */
}
