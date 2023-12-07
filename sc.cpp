#include <iostream>
#include <iomanip>
#define EPS 0.0001
using namespace std;

double func(double x) {
    return x * x - 4 * x - 10;
}

double secantMethod(double x1, double x2) {
    double x0, error;
    int iteration = 0;

    do {
        x0 = x1 - (func(x1) * (x2 - x1)) / (func(x2) - func(x1));
        error = abs(x0 - x1);
        
        cout << fixed << setprecision(6);
        cout << "Iteration " << iteration + 1 << ": x0 = " << x0 << ", Error = " << error << endl;

        x1 = x2;
        x2 = x0;
        iteration++;
    } while (error <= EPS);

    cout << "Root of the equation is: " << x0 << endl;
    return x0;
}

int main() {
    double x1 = 4, x2 = 2;

    cout << "Initial values: x1 = " << x1 << ", x2 = " << x2 << endl;
    secantMethod(x1, x2);

    return 0;
}
