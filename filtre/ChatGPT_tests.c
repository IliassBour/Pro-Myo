/*#include <stdio.h>
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
    double smoothed[n];
    centered_moving_average(y, n, window_size, smoothed);
    printf("The smoothed data is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", smoothed[i]);
    return 0;
}/**/

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

#include <complex.h>
#include <math.h>
#include <stdio.h>

void fft(double complex *x, int N) {
    if (N == 1)
        return;

    double complex even[N / 2], odd[N / 2];
    for (int i = 0; i < N / 2; i++) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    fft(even, N / 2);
    fft(odd, N / 2);

    for (int k = 0; k < N / 2; k++) {
        double complex t = cexp(-2 * M_PI * I * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}

int main() {
    int N;
    printf("Enter the number of data points: ");
    scanf("%d", &N);

    double complex x[N];
    printf("Enter the data: ");
    for (int i = 0; i < N; i++) {
        double real, imag;
        scanf("%lf %lf", &real, &imag);
        x[i] = real + I * imag;
    }
    
    fft(x, N);

    printf("The FFT result is: \n");
    for (int i = 0; i < N; i++)
        printf("%lf + %lfi\n", creal(x[i]), cimag(x[i]));

    return 0;
}/**/

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

/*#include <stdio.h>
#include <math.h>
//Fonction mais rajoute un offset
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
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double y[n];
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);

    double trend[n], residuals[n];
    linear_detrend(y, n, trend, residuals);

    printf("The linear trend is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", trend[i]);

    printf("The residuals are: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", residuals[i]);

    return 0;
}/**/

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

/*#include <stdio.h>
#include <math.h>

void mean_detrend(double *y, int n, double *residuals) {
    double mean = 0;
    for (int i = 0; i < n; i++)
        mean += y[i];
    mean /= n;

    for (int i = 0; i < n; i++)
        residuals[i] = y[i] - mean;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double y[n];
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);

    double residuals[n];
    mean_detrend(y, n, residuals);

    printf("The residuals are: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", residuals[i]);

    return 0;
}/**/

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*#include <stdio.h>
#include <math.h>

void rectify(double *y, int n, double *rectified) {
    for (int i = 0; i < n; i++)
        rectified[i] = fabs(y[i]);
}
int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double y[n];
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
    double rectified[n];
    rectify(y, n, rectified);
    printf("The rectified data is: \n");
    for (int i = 0; i < n; i++)
        printf("%lf\n", rectified[i]);
    return 0;
}/**/