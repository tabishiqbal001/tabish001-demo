#include <stdio.h>
#include <math.h>

double func(double x) {
    return x * sin(x) + cos(x);
}

double deriv(double x) {
    return x * cos(x);
}

int main() {
    double x0, x1, e = 0.001;
    int i = 1, max_iter = 20;

    printf("\nEnter initial guess (x0): ");
    scanf("%lf", &x0);

    printf("\nIter\t x0\t\t f(x0)\t\t f'(x0)\t\t x1\n");
    printf("--------------------------------------------------------------------------\n");

    do {
        if (deriv(x0) == 0.0) {
            printf("Mathematical Error: Derivative is zero.\n");
            return 1;
        }

        x1 = x0 - func(x0) / deriv(x0);

        printf("%d\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n", i, x0, func(x0), deriv(x0), x1);

        if (fabs(x1 - x0) < e)
            break;

        x0 = x1;
        i++;
    } while (i <= max_iter);

    printf("\nApproximate Root = %.3lf\n", x1);
    return 0;
}