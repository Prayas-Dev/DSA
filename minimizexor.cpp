#include<iostream>

using namespace std;

class SolutionOne{
    public:

    bool isSet(int &x, int bit){
        return x & (1<<bit);
    }

    bool setBit(int &x, int bit){
        return x |= (1<<bit);
    }

    bool unsetBit(int &x, int bit){
        return x &= ~(1<<bit);  
    }

    int minimizeXOR(int num1, int num2){
        int x=num1;

        int requiredSetBitCount=__builtin_popcount(num2);
        int currSetBitCount=__builtin_popcount(x);

        int bit=0;
        if(currSetBitCount<requiredSetBitCount){
            while(currSetBitCount<requiredSetBitCount){
                if(!isSet(x, bit)){
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        }
        else if(currSetBitCount>requiredSetBitCount){
            while(currSetBitCount>requiredSetBitCount){
                if(isSet(x, bit)){
                    unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }
        return x;
    }
};

class SolutionTwo :public SolutionOne{
    public:

    bool isUnset(int x, int bit){
        return (x & (1 << bit))==0;
    }

    int minimizeXOR(int num1, int num2){
        int x=0;
        int requiredSetBitCount=__builtin_popcount(num2);

        for(int bit=31;bit>=0 && requiredSetBitCount>0;bit--){
            if(isSet(num1, bit)){
                setBit(x, bit);
                requiredSetBitCount--;
            }
        }
        for(int bit=0;bit<32 && requiredSetBitCount>0;bit++){
            if(isUnset(num1, bit)){
                setBit(x, bit);
                requiredSetBitCount--;
            }
        }
        return x;
    }
};

int main() {
    SolutionOne sol1;
    SolutionTwo sol2;
    int num1=3;
    int num2=5;
    // cout<<sol1.minimizeXOR(num1,num2);
    cout<<sol2.minimizeXOR(num1,num2);

    return 0;

}