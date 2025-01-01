#include<iostream>

using namespace std;

int fibonacciTerm(int num){
    int first =0,second=1,next;
    for(int i=0;i<num;i++){
        if(i<=1){
            next=i;
        }
        else{
            next=first+second;
            first=second;
            second=next;
        }
    }
    return next;
}

void fibonacciSeries(int num){
    int first=0,second=1,next;
    for(int i=0;i<num;i++){
        if(i<=1){
            next=i;
        }
        else{
            next=first+second;
            first=second;
            second=next;
        }
        cout<<next<<" ";
    }
}

int main(){
    int n,x;
    cout<<"Enter your number : ";
    cin>>n;
    cout<<"Enter 1 to get fibonacci series till nth term"<<endl;
    cout<<"Enter 2 to get nth fibonacci term"<<endl;
    cin>>x;
    switch(x){
        case 1:
            cout<<"Fibonacci series: ";
            fibonacciSeries(n);
            break;
        case 2:
            cout<<"Fibonacci term : "<<fibonacciTerm(n)<<endl;
            break;
        default:
            cout<<"Enter 1 or 2<<endl";
    }

    return 0;

}