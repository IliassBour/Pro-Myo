#include "filtre.h"
#include <stdlib.h>
#include <stdio.h>

#define SIZE 100
void dcTrend(){
    //Eliminer Dc et tendance lineaire
    double mean, sum, index = 0;
    for(int i = 0; i < SIZE; i++){
        sum += data[0][i];
        index++;
    }
    mean = sum/index;
    for(int i = 0; i < SIZE; i++) {
        data[0][i] -= mean;
    }
}

void filtre() {
    double data[5][SIZE];
    double fs = 1000; //frequence d echantillonnage
    double k1 = 101; //largeur fenetre 1
    double k2 = 501; //largeur fenetre 2
    double k3 = 1001; //largeur fenetre 3

    

    //Filtrer
    printf("test");

    //Rectifier

    //Analyser

}