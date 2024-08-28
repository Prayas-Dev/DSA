#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>&nums){
        int i=0;
        for(auto ele:nums){
            if(i==0 || i==1 || nums[i-2]!=ele){
                nums[i]=ele;
                i++;
            }
        }
        return i;
    }

};

int main(){
    Solution solution;
    vector<int> nums={1,1,1,2,2,3};
    solution.removeDuplicates(nums);
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}