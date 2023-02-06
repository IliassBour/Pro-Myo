#include "filtre.h"
//#include "detrend.c"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 100
#define PI 3.14159265359
//#define k 9 /*------------nécessairement impair------------*/
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

// Fonction pour concevoir les coefficients du filtre
void design_filter(double *b, double *a, int n, double fc, double fs, char type)
{
    double wc = 2 * PI * fc / fs;
    double wc2 = wc * wc;
    double wc4 = wc2 * wc2;
    double k = wc / tan(wc / 2);
    double k2 = k * k;
    double k4 = k2 * k2;
    double sqrt2 = sqrt(2);
    switch (type)
    {
    case 'h':
        b[0] = k2 / (1 + sqrt2 * k + k2);
        b[1] = -2 * b[0];
        b[2] = b[0];
        a[0] = 1;
        a[1] = -2 * (k2 - 1) / (1 + sqrt2 * k + k2);
        a[2] = (1 - sqrt2 * k + k2) / (1 + sqrt2 * k + k2);
        break;
    case 'l':
        b[0] = 1 / (1 + sqrt2 * k + k2);
        b[1] = 2 * b[0];
        b[2] = b[0];
        a[0] = 1;
        a[1] = 2 * (k2 - 1) / (1 + sqrt2 * k + k2);
        a[2] = (1 - sqrt2 * k + k2) / (1 + sqrt2 * k + k2);
        break;
    }
}

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
    double data[5][SIZE];
    double fs = 1000; //frequence d echantillonnage
    /*double k1 = 101; //largeur fenetre 1
    double k2 = 501; //largeur fenetre 2
    double k3 = 1001; //largeur fenetre 3
    float out[:] = input[:];*/

    int nbDataPoints = 8;
    double residualsMean[nbDataPoints];
    double trendLinear[nbDataPoints];
    double residualsLin[nbDataPoints];
    double afterFilter[nbDataPoints];
    double rectified[nbDataPoints];
    double smoothed[nbDataPoints];
    int N = 1000;
    double fc = 5000;
    double a_high[3];
    double b_high[3];
    double a_low[3];
    double b_low[3];
    char filter_type = 'h';

    //Filtrer
    //dcTrend(&input, out);
    mean_detrend(input, nbDataPoints, residualsMean);
    /*for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", residualsMean[i]);*/
    linear_detrend(residualsMean, nbDataPoints, trendLinear, residualsLin);
    /*for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", residualsLin[i]);*/
    design_filter(b_high, a_high, N, fc, fs, filter_type);
    /*for (int i = 0; i < 3; i++)
        printf("%lf\n", a_high[i]);
    for (int i = 0; i < 3; i++)
        printf("%lf\n", b_high[i]);*/
    //insert filter function
    

    //Rectifier
    /*rectify(afterFilter, nbDataPoints, rectified);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", rectified[i]);*/

    //Analyser
    //centered_moving_average(rectified, nbDataPoints, 1000, smoothed);
    centered_moving_average(residualsLin, nbDataPoints, 10, smoothed);
    /*for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", smoothed[i]);*/
    printf("test");
}