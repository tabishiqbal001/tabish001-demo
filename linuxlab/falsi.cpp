#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return tan(x) + tanh(x);
}

int main() {
    double a, b, x, tolerance;
    int step = 1, maxSteps;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter max iterations: ";
    cin >> maxSteps;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval!" << endl;
        return 0;
    }

    cout << fixed << setprecision(4);
    cout << "\nStep\t a \t\t b \t\t x \t\t f(x)" << endl;


    do {
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << step << "\t " << a << "\t " << b << "\t " << x << "\t " << f(x) << endl;

        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }

        step++;
        if (step > maxSteps) break;

    } while (abs(f(x)) > tolerance);

    cout << "Final Root: " << setprecision(3) << x << endl;

    return 0;
}