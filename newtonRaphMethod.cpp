#include<iostream>
#include<iomanip>
#define EPS 0.0001
using namespace std;
double func(double x){
    return x*x-3*x+2;
}
double derivative_of_func(double x){
    return 2*x-3;
}
double retAbsValue(double x){
    if(x<0){
        return -1*x;
    }
    return x;
}
double newtonRaphMethod(double a){
    double funcA,derivtA,nextValue,funcNextValue,error;
    funcA=func(a);
    derivtA = derivative_of_func(a);
    if(derivtA!=0){
        nextValue = a-(funcA/derivtA);
        funcNextValue = func(nextValue);
        error = retAbsValue(nextValue-a);
        cout<<fixed<<setprecision(4);
        cout<<a<<"\t\t"<<nextValue<<"\t\t"<<funcA<<"\t\t"<<funcNextValue<<"\t\t"<<error<<endl;
        if(error<=EPS||retAbsValue(funcNextValue)<=EPS){
            cout<<"The required root is:"<<nextValue<<endl;
            return nextValue ;
        }
        else{
            a = nextValue;
            newtonRaphMethod(a);
        }
    }
    else{
        cout<<"Choose another initial value!!!"<<endl;
    }
}    
int main(){
    double initialValue;
    cout<<"Enter initial approximation value:"<<endl;
    cin>>initialValue;
    cout<<"InitialValue\t"<<"NextValue\t"<<"f(a)\t\t"<<"f(nextValue)\t"<<"error"<<endl;
    newtonRaphMethod(initialValue);
    return 0; 
}