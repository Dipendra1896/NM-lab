#include<iostream>
#include<iomanip>
#define EPS 0.0001
using namespace std;
double func(double x){
    return x*x-4*x-10;
}
double retAbsValue(double x){
    if(x<0){
        return -1*x;
    }
    return x;
}
void falsePosition(double a, double b){
    double funcA,funcB,nextValue,funcNextValue, error;
    funcA = func(a);
    funcB = func(b);
    if(funcA*funcB<0){
        nextValue = a-(funcA*(b-a))/(funcB-funcA);
        error=retAbsValue(b-a);
        funcNextValue=func(nextValue);
        cout<<fixed<<setprecision(4);
        cout<<a<<"\t\t"<<b<<"\t\t"<<nextValue<<"\t\t"<<funcNextValue<<"\t\t"<<error<<endl;
        if(error<=EPS||retAbsValue(funcNextValue)<=EPS){
            cout<<"The required root of this equation is:"<<nextValue<<endl;
            return; 
        }
        else if(funcA*funcNextValue<0){
            b=nextValue;
            falsePosition(a,b); //recursion call of function
        }
        else if(funcB*funcNextValue<0){
            a=nextValue;
            falsePosition(a,b);
        }else{
            cout<<"Unknown Error Occurred"<<endl;
            return;
        }
    }
    else{
        cout<<"Plz choose valid  value for a and b!!!"<<endl;

    }    
}
int main(){
    double firstValue,secondValue;
    cout<<"Enter two initial guesses(a & b):"<<endl;
    cin>>firstValue>>secondValue;
    cout<<"firstValue\t"<<"secondValue\t"<<"f(A)\t\t"<<"f(B)\t\t"<<"Error\t"<<endl;
    falsePosition(firstValue,secondValue);
    return 0;

}