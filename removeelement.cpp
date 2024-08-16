#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int removeElement(vector<int>&nums, int val){
        int k = 0;                  // Pointer to track the position of non-val elements

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){               // check if the current value is not equal to val
                nums[k]=nums[i];                // if not equal then move it in front
                k++;                            
            }
        }
        return k;                       // return the size of the array
    }
};

int main(){
    Solution solution;

    vector<int> nums = {3,2,2,3};
    int val = 3;

    int result = solution.removeElement(nums, val);

    cout<<"New length : "<<result<<endl;
    cout<<"New array : ";
    for(int i=0;i<result;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}