#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution{
    public:
        vector<int>twoSum(vector<int>&nums,int target){
            map<int,int> mpp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                int num=nums[i];
                int more=target-num;
                if(mpp.find(more)!=mpp.end()){
                    return {mpp[more],i};
                }
                mpp[num]=i;
            }
            return {-1,-1};
        }
};

int main(){
    Solution sol;
    vector<int>nums={2,7,11,15};
    vector<int>ans=sol.twoSum(nums,9);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}