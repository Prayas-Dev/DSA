#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public :
		int jump(vector<int>& nums) {
			int jumps =0, farthest = 0, currentEnd = 0; 
			
			for(int i= 0;i<nums.size()-1;i++){
				farthest = max(farthest , i + nums[i]); 
				
				if(i==currentEnd){
					jumps++;
					currentEnd=farthest;
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