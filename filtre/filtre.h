#ifndef FILTRE_H
#define FILTRE_H
void mean_detrend(double *y, int n, double *residuals);
void linear_detrend(double *y, int n, double *trend, double *residuals);
void rectify(double *y, int n, double *rectified);
void convert_log(double *y, double *y_log, int size);
void butterworth_highpass(double *y, int n, double cutoff_frequency, double sample_rate, double *filtered);
void butterworth_lowpass(double *y, int n, double cutoff_frequency, double sample_rate, double *filtered);
void centered_moving_average(double *y, int n, int window_size, double *smoothed);
void filtre(double *input);

#endif