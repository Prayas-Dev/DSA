#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int countPrimes(int n){

        if(n<=2){
            return 0;
        }

        vector<bool>isPrime(n, true);
        int count=0;

        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;

                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout<<"Enter your range: ";
    int n;
    cin>>n;
    cout<<"Number of Primes less than "<<n<<": "<<sol.countPrimes(n)<<endl;

    return 0;
}