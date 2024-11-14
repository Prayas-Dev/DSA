#include<iostream>

using namespace std;

void display(int n){
    cout<<"Number : "<<n<<endl;
}

int add(int a,int b){
    return a+b;
}

int main(){
    // int i=5;

    // int &j=i;

    // cout<<i<<endl;

    void(*funcPtr)(int);

    funcPtr=&display;

    (*funcPtr)(5);

    int(*funcPtr1)(int,int);

    funcPtr1=&add;

    cout<<(*funcPtr1)(10,20);

    return 0;
}