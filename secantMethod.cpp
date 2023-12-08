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
    cout << fixed << setprecision(4);
    cout<<"     Iteration\t\tA\t\tB\t\tf(A)\t\tf(B)\t\tNextValue"<<endl;

    do {
        nextValue = b - (funcB * (b - a) / (funcB - funcA));
        error = abs(nextValue - b);  
        //setting fixed space to print output data with proper alignment   
        cout<<setw(9)<< iteration+1;
        cout<<setw(18)<<a;
        cout<<setw(16)<<b;
        cout<<setw(18)<<funcA;
        cout<<setw(16)<<funcB;
        cout<<setw(18)<<nextValue<<endl;
                                                                          
        a = b;
        b = nextValue;
        funcA = func(a);
        funcB = func(b);
        iteration++;
    } while (error >= EPS); //when the  error becomes less or equal to the tolerance(EPS) the 
    //codition becomes false and execution goes to out of the loop
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Required root is: " << nextValue << endl;
    return nextValue;
}

int main() {
    double a = 4.0000, b = 2.0000;
    secantMethod(a, b);
    return 0;
}
