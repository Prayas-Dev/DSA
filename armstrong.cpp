#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

bool isArmstrong(int n){

    if(n<0){
        return false;
    }
    int num=n;
    int digit,sum=0,x=0;

    while(n!=0){
        n/=10;
        x++;
    }
    n=num;
    while(n!=0){
        digit=n%10;
        n/=10;
        sum+=pow(digit,x);
    }
    if(num==sum){
        return true;
    }
    return false;
}

int main(){

    cout<<"Enter your Number : ";
    int n;
    cin>>n;
    cout<<isArmstrong(n);

    return 0;
}