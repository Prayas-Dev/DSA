#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
	public:
		int trappedWater(vector<int>&nums){
			int n=nums.size();
			
			vector<int>leftMax(n);
			vector<int>rightMax(n);
			
			leftMax[0]=nums[0];
			rightMax[n-1]=nums[n-1];
			
			for(int i=1;i<n;i++){
				if(nums[i]>leftMax[i-1]){
					leftMax[i]=nums[i];
				}
				else{
					leftMax[i]=leftMax[i-1];
				}
			}
			for(int i=n-2;i>=0;i--){
				if(nums[i]>rightMax[i+1]){
					rightMax[i]=nums[i];
				}
				else{
					rightMax[i]=rightMax[i+1];
				}
			}
			
			int trappedWater=0;
			for(int i=0;i<n;i++){
				trappedWater+=min(leftMax[i],rightMax[i])-nums[i];
			}
			return trappedWater;
		}
};

int main(){
	
	Solution sol;
	vector<int>nums={4,2,0,3,5,6};
	cout<<sol.trappedWater(nums)<<endl;
	
	return 0;
}