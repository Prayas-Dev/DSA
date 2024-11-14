#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public :
		int jump(vector<int>& nums) {
			int destination = nums.size()-1;
			int jumps = 0, coverage = 0, lastjmpindex = 0;

			if(nums.size()==1){
				return 0;
			}
			for(int i = 0;i<nums.size()-1;i++){
				coverage = max(coverage , i + nums[i]);

				if(i == lastjmpindex){
					lastjmpindex = coverage;
					jumps++;
				}
				if(coverage>=destination){
					return jumps;
				}
			}
			return jumps;
		}
};

int main(){
	Solution solution;
	
	vector<int> nums = {2,3,1,1,4};
	int minjumps = solution.jump(nums);
	
	for(int num:nums){
		cout<<num<<" ";
	}
	cout<<endl;
	
	cout<<"Minimum jumps required : "<<minjumps<<endl;
	
	return 0;
}