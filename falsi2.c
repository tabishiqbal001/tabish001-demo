#include <stdio.h>
#include <math.h>

double f(double x) {
    return tan(x) + tanh(x);
}

int main() {
    double x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    printf("Enter two initial guesses: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter tolerance: ");
    scanf("%lf", &e);

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0) {
        printf("Incorrect initial guesses.\n");
        return 0;
    }

    printf("\nStep\t x0\t\t x1\t\t x2\t\t f(x2)\n");

    do {
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t %.4f\t %.4f\t %.4f\t %.4f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }
        step++;
    } while (fabs(f2) > e);
    printf("\nFinal Root: %.3f\n", x2);

    return 0;
}