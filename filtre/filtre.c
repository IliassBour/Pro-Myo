#include "filtre.h"
//#include "detrend.c"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 100
#define k 9 /*------------nécessairement impair------------*/
/*void dcTrend(double &table, float out[]){
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
    /*DetrendMean(&table, out);
    //Élimener tendance lineaire
    DetrendLinear(&table, out);
}
*/

void mean_detrend(double *y, int n, double *residuals) {
    double mean = 0;
    for (int i = 0; i < n; i++)
        mean += y[i];
    mean /= n;

    for (int i = 0; i < n; i++)
        residuals[i] = y[i] - mean;
}

void linear_detrend(double *y, int n, double *trend, double *residuals) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < n; i++) {
        double x = i;
        sum_x += x;
        sum_y += y[i];
        sum_xy += x * y[i];
        sum_x2 += x * x;
    }

    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double b = (sum_y - m * sum_x) / n;
    for (int i = 0; i < n; i++) {
        double x = i;
        trend[i] = m * x + b;
        residuals[i] = y[i] - trend[i];
    }
}

/*void rect(double &table, float out[]) {
    for(int i = 0; i < SIZE; i++){
        if(table[0][i]<0){
            table[0][i]= -table[0][i];
        }
    }
}*/

void rectify(double *y, int n, double *rectified) {
    for (int i = 0; i < n; i++)
        rectified[i] = fabs(y[i]);
}

/*void lise(double &table, float out[]) {
    for(int i = 0; i < SIZE; i++){
        double mean, sum, index, meanind = 0;
        double bid = (k-1)/2;
        for(index < k;){
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
}*/

void centered_moving_average(double *y, int n, int window_size, double *smoothed) {
    int half_window = window_size / 2;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        int count = 0;
        for (int j = i - half_window; j <= i + half_window; j++) {
            if (j >= 0 && j < n) {
                sum += y[j];
                count++;
            }
        }
        smoothed[i] = sum / count;
    }
}

void filtre(double *input) {
    /*double data[5][SIZE];
    double fs = 1000; //frequence d echantillonnage
    double k1 = 101; //largeur fenetre 1
    double k2 = 501; //largeur fenetre 2
    double k3 = 1001; //largeur fenetre 3
    float out[:] = input[:];*/

    int nbDataPoints = 16;
    double residualsMean[nbDataPoints];
    double trendLinear[nbDataPoints];
    double residualsLin[nbDataPoints];
    double afterFilter[8];
    double rectified[8];
    double smoothed[8];

    //Filtrer
    //dcTrend(&input, out);
    mean_detrend(input, nbDataPoints, residualsMean);
    linear_detrend(residualsMean, nbDataPoints, trendLinear, residualsLin);
    
    //insert filter function
    printf("test");

    //Rectifier
    rectify(afterFilter, 8, rectified);

    //Analyser
    centered_moving_average(rectified, 8, 1000, smoothed);
}