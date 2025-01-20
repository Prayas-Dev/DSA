#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

class Solution{
    public:
    long long minCost(vector<int>& arr, vector<int>& brr,long long k){
        int n=arr.size();

        long long directAdjustmentCost = 0;
        for(int i=0;i<n;i++){
            directAdjustmentCost += abs(arr[i] - brr[i]);
        }

        vector<int>sortedArr = arr;
        vector<int>sortedBrr = brr;

        sort(sortedArr.begin(), sortedArr.end());
        sort(sortedBrr.begin(), sortedBrr.end());

        long long rearrangementAdjustmentCost = 0;

        for(int i=0;i<n;i++){
            rearrangementAdjustmentCost += abs(sortedArr[i] - sortedBrr[i]);
        }

        rearrangementAdjustmentCost+=k;

        return min(directAdjustmentCost, rearrangementAdjustmentCost) ;
    }
};