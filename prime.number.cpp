#include<iostream>

using namespace std;

string isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return "Not Prime";
        }
    }
    return "Prime";
}

int main(){
    cout<<"Enter your number: ";
    int n;
    cin>>n;

    cout<<endl<<isPrime(n);

    return 0;
}