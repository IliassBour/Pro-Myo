#include <stdio.h>
#define MAX_LEN 100

float moving_average(float arr[], int n, int k) {
    int i;
    float sum = 0;
    for (i = 0; i < k; i++)
        sum += arr[i];
    float avg = sum / k;
    for (i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        avg = sum / k;
    }
    return avg;
}

int main() {
    float arr[MAX_LEN];
    int n, k, i;

    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    for (i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    printf("Enter the number of points to average: ");
    scanf("%d", &k);
    printf("The moving average is: %f\n", moving_average(arr, n, k));

    return 0;
}

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
}

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

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
}

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

#include <stdio.h>
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
}

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
