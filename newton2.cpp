#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * sin(x) + cos(x);
}

double df(double x) {
    return x * cos(x);
}

int main() {
    double x0, x1, tol;
    int maxIter, i = 1;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    cout << fixed << setprecision(4);
    while (i <= maxIter) {
        if (df(x0) == 0.0) {
            cout << "Mathematical Error (Derivative = 0)" << endl;
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);
        cout << "Iteration " << i << ": x = " << x1 << endl;

        if (fabs(x1 - x0) < tol) {
            cout << "Root = " << setprecision(3) << x1 << endl;
            return 0;
        }

        x0 = x1;
        i++;
    }

    cout << "Root = " << setprecision(3) << x1 << endl;
    return 0;
}