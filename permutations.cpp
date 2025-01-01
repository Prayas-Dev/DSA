#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:

    void getPerms(vector<int>&nums, int idx, vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            getPerms(nums, idx+1, ans);

            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>>permute(vector<int>&nums){
        vector<vector<int>>ans;
        getPerms(nums,0,ans);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,2,3};

    vector<vector<int>>permutations=sol.permute(nums);

    for(const auto& perm: permutations){
        cout<<"[";
        for(size_t i=0;i<perm.size();i++){
            cout<<perm[i];
            if(i<perm.size()-1) cout<<", ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}