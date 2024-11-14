#include<iostream>

using namespace std;

int binaryToDecimal(int num){
    int ans=0,pow=1;
    while(num>0){
        int remainder=num%10;
        num/=10;
        ans+=remainder*pow;
        pow*=2;
    }
    return ans;
}

int main(){
    cout<<"Enter your binary Number to convert it into decimal : ";
    int num;
    cin>>num;
    cout<<binaryToDecimal(num);

    return 0;
}