#include<iostream>
#include<cmath>

using namespace std;

int reverseNumber(int n){
    int revNum=0;
    while(n!=0){
        int dig=n%10;
        revNum=revNum*10+dig;
        n/=10;
    }
    return revNum;
    
}

int main(){
    cout<<"Enter your number to reverse it : ";
    int n;
    cin>>n;
    cout<<reverseNumber(n);

    return 0;
}