#include "filtre.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>

#define PI 3.1415926535
#define SIZE 100
#define FS 1000
#define k 9 /*------------nécessairement impair------------*/

void convert_log(double *y, double *y_log, int size)
{
    for(int i = 0; i < size; i++) 
    {
        y_log[i] = 10*log(y[i]);
    }
}


void spectral_density_welch(double *signal, int signal_length, int fs, double *spectral_density) {
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
}

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

void filtre(double *input) {
    double data[SIZE];
    double fs = 1000; //frequence d echantillonnage
    double k1 = 101; //largeur fenetre 1
    double k2 = 501; //largeur fenetre 2
    double k3 = 1001; //largeur fenetre 3

    //Dc et detrend

    //Filtrer
    double dps[SIZE];
    spectral_density_welch(data, SIZE, fs, dps)
    
    double log[SIZE];
    convert_log(data, SIZE, log);

    double fc_low = fs/5;// À modifier après tester matlab
    double fc_high = 20;

    double data_highpass[SIZE];
    butterworth_highpass(log, SIZE, fc_high , fs, data_highpass);

    double data_bandpass[SIZE];
    butterworth_lowpass(data_highpass, SIZE, fc_low, fs, data_bandpass);


    //Rectifier

    //Analyser

}