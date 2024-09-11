#include<iostream>

using namespace std;

int decToBinary(int decNum){
    int ans=0;
    int pow=1;

    while(decNum>0){
        int rem=decNum%2;
        decNum/=2;

        ans+=(rem*pow);
        pow*=10;
    }
    return ans;
}

int main(){
    cout<<"Enter your number to convert in binary : ";
    int decNum;
    cin>>decNum;
    cout<<decToBinary(decNum);

    return 0;
}