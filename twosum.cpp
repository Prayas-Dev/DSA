#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            vector<int>ans(2);
            for(int i=0;i<nums.size();i++){
                int x=target-nums[i];
                int j=0;
                while(j<nums.size() && j!=i){
                    if(x==nums[j]){
                        ans[0]=i;
                        ans[1]=j;
                        return ans;
                    }
                    j++;
                }
            }
        }
};

int main(){
    Solution sol;
    vector<int>nums={2,7,11,15};
    vector<int>ans=sol.twoSum(nums,26);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}