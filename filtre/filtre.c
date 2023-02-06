#include "filtre.h"
#include "detrend.c"
#include <stdlib.h>
#include <stdio.h>

#define SIZE 100
#define k 9 /*------------nécessairement impair------------*/
void dcTrend(double &table, float out[]){
    //Eliminer Dc
    /*double mean, sum, index = 0;
    for(int i = 0; i < SIZE; i++){
        sum += table[0][i];
        index++;
    }
    mean = sum/index;
    for(int i = 0; i < SIZE; i++) {
        table[0][i] -= mean;
    }*/
    DetrendMean(&table, out);
    //Élimener tendance lineaire
    DetrendLinear(&table, out);
}

void rect(double &table, float out[]) {
    for(int i = 0; i < SIZE; i++){
        if(table[0][i]<0){
            table[0][i]= -table[0][i];
        }
    }
}

void lise(double &table, float out[]) {
    for(int i = 0; i < SIZE; i++){
        double mean, sum, index, meanind = 0;
        double bid = (k-1)/2;
        if(index < k;){
            if((i-bid>=0) && (i - bid <= SIZE)){
                sum += table[0][i - bid];
                meanind++;
            }
            index++;
            bid--;
        }
        mean = sum/meanind;
        out[0][i] = mean;
    }
}

void filtre(double &input[]) {
    double data[5][SIZE];
    double fs = 1000; //frequence d echantillonnage
    double k1 = 101; //largeur fenetre 1
    double k2 = 501; //largeur fenetre 2
    double k3 = 1001; //largeur fenetre 3
    float out[:] = input[:];

    //Filtrer
    dcTrend(&input, out);
    printf("test");

    //Rectifier

    //Analyser

}