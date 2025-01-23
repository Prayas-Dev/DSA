#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int pivotElement(vector<int>& arr, int s, int e){

        if(s>=e){
            return s;
        }

        int mid=s+(e-s)/2;

        if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
            return mid;
        }
        else{
            pivotElement(arr,s, mid);
            pivotElement(arr,mid+1, e);
        }
        
    }

    int findMin(vector<int>&nums){

        int ans=pivotElement(nums, 0, nums.size()-1);

        return ans;
    }
};

int main(){
    Solution sol;

    vector<int>nums={4,5,6,7,1,2,3};

    cout<<sol.findMin(nums);

    return 0;
}