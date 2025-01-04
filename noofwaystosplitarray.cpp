#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        int waysToSplitArray(vector<int> &nums){
            int ans=0,sum=0,leftSum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
            }
            for(int i=0;i<nums.size()-1;i++){
                leftSum+=nums[i];
                int rightSum=sum-leftSum;
                if(leftSum>=rightSum){
                    ans++;
                }
            }
            return ans;
        }
};

int main(){
    Solution sol;
    vector<int>nums={10,4,-8,7};
    cout<<sol.waysToSplitArray(nums);
    return 0;
}