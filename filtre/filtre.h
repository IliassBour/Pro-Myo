#ifndef FILTRE_H
#define FILTRE_H
void mean_detrend(double *y, int n, double *residuals);
void linear_detrend(double *y, int n, double *trend, double *residuals);
void rectify(double *y, int n, double *rectified);
void design_filter(double *b, double *a, int n, double fc, double fs, char type);
void centered_moving_average(double *y, int n, int window_size, double *smoothed);
void filtre(double *input);

#endif