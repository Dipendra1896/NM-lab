#include <iostream>
#include <iomanip>
#define EPS 0.0001
using namespace std;

double func(double x) {
    return x * x - 4 * x - 10;
}

double secantMethod(double a, double b) {
    double funcA, funcB, nextValue, error;
    int iteration = 0;
    funcA = func(a);
    funcB = func(b);

    do {
        nextValue = b - (funcB * (b - a) / (funcB - funcA));
        error = abs(nextValue - b);                                         
                                                                                                         
        cout << fixed << setprecision(4);
        cout << "Iteration " << iteration + 1<<":\t"<<a<<"\t\t"<<b<<"\t\t"<<funcA<<"\t\t"<<funcB<<"\t\t"<<nextValue<<endl;
        a = b;
        b = nextValue;
        funcA = func(a);
        funcB = func(b);
        iteration++;
    } while (error >= EPS);

    cout << "Required root is: " << nextValue << endl;
    cout << "Number of iterations: " << iteration << endl;
    return nextValue;
}

int main() {
    double a = 4.0000, b = 2.0000;
    cout << "\t\tA\t\t" << "B\t\t" << "f(A)\t\t\t" << "f(B)\t\t" << "nextValue" << endl;
    secantMethod(a, b);
    return 0;
}
