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

    int binarySearch(vector<int>&arr, int s, int e, int target){
        if(s>=e){
            return 0;
        }
        int pi=pivotElement(arr, s, e);

        if(arr[pi]==target){
            return pi;
        }
        if(arr[pi]<target){
            binarySearch(arr, s, pi-1, target);
        }
        else{
            binarySearch(arr, pi+1, e, target);
        }
    }
};

int main(){
    Solution sol;

    vector<int>arr={4,5,6,1,2,3};

    cout<<sol.binarySearch(arr, 0, arr.size()-1, 4);

    return 0;
}