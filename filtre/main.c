#include <stdlib.h>
#include <stdio.h>
#include "filtre.h"

int main() {
    double input[8];
    input[0] = 1;
    input[1] = 3;
    input[2] = 1;
    input[3] = -1;
    input[4] = 1;
    input[5] = 3;
    input[6] = 1;
    input[7] = -1;
    filtre(input);

    return 0;
}