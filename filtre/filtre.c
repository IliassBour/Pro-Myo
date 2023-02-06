#include "filtre.h"
//#include "detrend.c"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <math.h>
#include <complex.h>
//#include <fftw3.h>

#define SIZE 8
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

void convert_log(double *y, double *y_log, int size)
{
    for(int i = 0; i < size; i++) 
    {
        y_log[i] = 10*log(y[i]);
    }
}


/*void spectral_density_welch(double *signal, int signal_length, int fs, double *spectral_density) {
    int i, j;
    int window_length = signal_length / 2;
    int overlap = window_length / 2;
    int n = (signal_length - overlap) / (window_length - overlap);
    double avg = 0;
    double window[window_length];

    for (i = 0; i < window_length; i++) {
        window[i] = 0.5 * (1 - cos(2 * M_PI * i / (window_length - 1)));
    }

    for (i = 0; i < n; i++) {
        fftw_complex *out;
        fftw_plan plan;
        out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * window_length);
        plan = fftw_plan_dft_r2c_1d(window_length, signal + i * (window_length - overlap), out, FFTW_ESTIMATE);
        fftw_execute(plan);

        for (j = 0; j < window_length / 2 + 1; j++) {
            spectral_density[j] += pow(cabs(out[j]), 2) / window_length * window[j];
        }

        fftw_destroy_plan(plan);
        fftw_free(out);
    }

    for (i = 0; i < window_length / 2 + 1; i++) {
        spectral_density[i] /= n;
        avg += spectral_density[i];
    }

    avg /= window_length / 2 + 1;

    for (i = 0; i < window_length / 2 + 1; i++) {
        spectral_density[i] /= avg;
    }
}*/

void butterworth_highpass(double *y, int n, double cutoff_frequency, double sample_rate, double *filtered) {
    double alpha = tan(PI * cutoff_frequency / sample_rate);
    double a0 = 1 / (1 + alpha);
    double a1 = -a0;
    double b1 = a0 * (1 - alpha);
    double x_prev = y[0];
    double y_prev = x_prev;
    filtered[0] = y_prev;
    for (int i = 1; i < n; i++) {
        double x = y[i];
        double y = a0 * x + a1 * x_prev + b1 * y_prev;
        filtered[i] = y;
        x_prev = x;
        y_prev = y;
    }
}

void butterworth_lowpass(double *y, int n, double cutoff_frequency, double sample_rate, double *filtered) {
    double alpha = tan(PI * cutoff_frequency / sample_rate);
    double a0 = 1 / (1 + alpha);
    double a1 = a0 * alpha;
    double b1 = a0 * (1 - alpha);
    double x_prev = y[0];
    double y_prev = x_prev;
    filtered[0] = y_prev;
    for (int i = 1; i < n; i++) {
        double x = y[i];
        double y = a0 * x + a1 * x_prev + b1 * y_prev;
        filtered[i] = y;
        x_prev = x;
        y_prev = y;
    }
}

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
/*void design_filter(double *b, double *a, int n, double fc, double fs, char type)
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
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", residualsMean[i]);
    linear_detrend(residualsMean, nbDataPoints, trendLinear, residualsLin);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", residualsLin[i]);
    //double dps[SIZE];
    //spectral_density_welch(residualsLin, SIZE, fs, dps);
    double log[nbDataPoints];
    convert_log(residualsLin, log, nbDataPoints);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", log[i]);

    double fc_low = fs/5;// À modifier après tester matlab
    double fc_high = 20;
    double data_highpass[nbDataPoints];
    butterworth_highpass(residualsLin, nbDataPoints, fc_high , fs, data_highpass);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", data_highpass[i]);

    double data_bandpass[nbDataPoints];
    butterworth_lowpass(data_highpass, nbDataPoints, fc_low, fs, data_bandpass);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", data_bandpass[i]);
    

    //Rectifier
    rectify(data_bandpass, nbDataPoints, rectified);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", rectified[i]);

    //Analyser
    //centered_moving_average(rectified, nbDataPoints, 1000, smoothed);
    centered_moving_average(data_bandpass, nbDataPoints, 10, smoothed);
    for (int i = 0; i < nbDataPoints; i++)
        printf("%lf\n", smoothed[i]);
    printf("test");
}