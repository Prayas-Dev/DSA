#include<iostream>

using namespace std;

int sumOfDigit(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main(){
    cout<<"Enter your number to find out the sum of digit : ";
    int num;
    cin>>num;
    cout<<sumOfDigit(num);

    return 0;
}
