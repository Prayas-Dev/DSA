#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
   
    void merge(vector<int>&arr, int l, int m, int r){
        int n1=m-l+1;
        int n2=r-m;

        vector<int>L(n1,0);
        vector<int>R(n2,0);

        int k=l;

        for(int i=0;i<n1;i++){
            L[i]=arr[k++];
        }

        for(int j=0;j<n2;j++){
            R[j]=arr[k++];
        }

        int i=0,j=0;
        k=l;

        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i++];
            }
            else{
                arr[k]=R[j++];
            }
            k++;
        }

        while(i<n1){
            arr[k++]=L[i++];
        }

        while(j<n2){
            arr[k++]=R[j++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r){
      if(l>=r){
        return ;
      }
      
      int mid=l + (r-l)/2;

      mergeSort(arr, l, mid);
      mergeSort(arr,mid+1, r);

      merge(arr, l, mid, r);
    }
};

int main(){

    Solution sol;

    vector<int>arr={1,4,2,11};
    sol.mergeSort(arr, 0, arr.size()-1);

    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}