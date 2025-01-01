#include<iostream>

using namespace std;

int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    if(a==0){
        return b;
    }
    return a;
}

int main(){

    int a=20,b=30;
    cout<<"Gcd of 20 & 30 is "<<gcd(a,b)<<endl;
    cout<<"Lcm of 20 & 30 is "<<(a*b)/gcd(a,b)<<endl;
    return 0;
}