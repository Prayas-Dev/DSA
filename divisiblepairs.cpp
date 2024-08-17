#include<iostream>
#include<vector>

using std::cout;
using std::vector;
using std::endl;

int divisibleSumPairs(int n, int k, const vector<int>& arr){
    vector<int> remainder_count(k,0);                    // Initialize remainder_count vector with 0
    int pairs=0;

    for(int i=0;i<n;i++){
        int remainder=arr[i]%k;

        // If remainder is 0, then the pair (r,0) is valid
        if(remainder==0){
            pairs+=remainder_count[0];
        }
        else{
            // Count pairs where remainder + (k - remainder) = k
            pairs += remainder_count[k - remainder];
        }
        remainder_count[remainder]++;
    }
    return pairs;
}

int main(){
    vector<int> arr={1,3,2,6,1,2};              
    int n = arr.size();
    int k=3;

    int result=divisibleSumPairs(n,k,arr);
    cout<<"Number of pairs : "<<result<<endl;

    return 0;
}