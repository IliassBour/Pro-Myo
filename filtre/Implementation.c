#include <stdio.h>
#include <math.h>

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


void rectify(double *y, int n, double *rectified) {
    for (int i = 0; i < n; i++)
        rectified[i] = fabs(y[i]);
}

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

int main() {
    int n, window_size;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the window size: ");
    scanf("%d", &window_size); 
    double y[n];
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
//
    double smoothed[n];
    centered_moving_average(y, n, window_size, smoothed);
    printf("The smoothed data is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", smoothed[i]);
//
    double residualsMean[n];
    mean_detrend(y, n, residualsMean);
    printf("The residualsMean are: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", residualsMean[i]);
//
    double trend[n], residualsLinear[n];
    linear_detrend(y, n, trend, residualsLinear);
    printf("The linear trend is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", trend[i]);
    printf("The residualsLinear are: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", residualsLinear[i]);
//
    double rectified[n];
    rectify(y, n, rectified);
    printf("The rectified data is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", rectified[i]);
//
    double smoothed_residualsMean[n];
    mean_detrend(smoothed, n, smoothed_residualsMean);
    printf("The smoothed and residualsMean are: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", smoothed_residualsMean[i]);
//
    double smoothed_residualsMean_trend[n], smoothed_residualsMean_residualsLinear[n];
    linear_detrend(smoothed_residualsMean, n, smoothed_residualsMean_trend, smoothed_residualsMean_residualsLinear);
    printf("The smoothed,residualsMean and linear trend is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", smoothed_residualsMean_trend[i]);
    printf("The smoothed residualsMean and residualsLinear are: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", smoothed_residualsMean_residualsLinear[i]);
//
    double smoothed_residualsMean_residualsLinear_rectified[n];
    rectify(smoothed_residualsMean_residualsLinear, n, smoothed_residualsMean_residualsLinear_rectified);
    printf("The smoothed, residulsMean, residualsLinear and rectified data is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", smoothed_residualsMean_residualsLinear_rectified[i]);
//

    printf("Enter any letters to end ");
    scanf("%d", &n);    
    return 0;
}
