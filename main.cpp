#include <bits/stdc++.h>
#include "BigInt\main.hpp"
using namespace std;

int main(){
    BigInt num1("12323224244234422364654565543224");
    BigInt num2 = 1234567891011121314151617181920;
    BigInt sum = num1 + num2;
    BigInt multiply = num1*num2;
    BigInt squareRoot = sqrt(multiply);
    cout<<"Num 1: "<<num1<<" Num2: "<<num2<<endl;
    cout<<"Sum of Num1 and Num2 : "<<sum<<endl;
    cout<<"Multiplication of Both Numbers : "<<multiply<<endl;
    cout<<"Square Root of multiply: "<<squareRoot<<endl;
    return 0;
}
