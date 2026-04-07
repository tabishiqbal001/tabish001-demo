#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
    return x * sin(x) + cos(x);
}

double deriv(double x) {
    return x * cos(x);
}

int main() {
    double x0, x1, e = 0.001;
    int i = 1, max_iter = 20;

    cout << "\nEnter initial guess (x0): ";
    cin >> x0;

    cout << fixed << setprecision(4);
    cout << "\nIter\t x0\t\t f(x0)\t\t f'(x0)\t\t x1" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    do {
        if (deriv(x0) == 0.0) {
            cout << "Mathematical Error: Derivative is zero." << endl;
            return 1;
        }

        x1 = x0 - func(x0) / deriv(x0);

        cout << i << "\t" << x0 << "\t\t" << func(x0) << "\t\t" << deriv(x0) << "\t\t" << x1 << endl;

        if (fabs(x1 - x0) < e)
            break;

        x0 = x1;
        i++;
    } while (i <= max_iter);

    cout << "\nApproximate Root = " << setprecision(3) << x1 << endl;

    return 0;
}