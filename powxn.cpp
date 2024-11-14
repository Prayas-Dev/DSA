#include<iostream>

using namespace std;

class Solution{
public:
    double myPow(double x,int n){
        long binForm=x;
        double ans=1;

        while(binForm>0){
            if(binForm % 2 ==1){
                ans*=x;
            }
            x+=x;
            binForm/=2;
        }
        return ans;
    }
};

int main(){


    return 0;
}