#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int partitioning(vector<int>& arr, int low, int high){
        int pi=low;
        int Pivot=arr[high];

        for(int i=low;i<high;i++){
            if(arr[i]<Pivot){
                swap(arr[i],arr[pi++]);
            }
        }
        swap(arr[pi],arr[high]);
        return pi;
    }

    void quickSort(vector<int>& arr, int low, int high){
        if(low>=high){
            return ;
        }
        int pi=partitioning(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);

    }
};

int main(){
    Solution sol;
    vector<int>arr={4,5,2,1,3};
    sol.quickSort(arr, 0, arr.size()-1);

    for(auto ele:arr){
        cout<<ele<<" ";
    }

    return 0;
}