#include<iostream>
#include<vector>

using namespace std;

class Solution {
	public:
		bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};

int main(){
	Solution solution;
	
	vector<int> nums1 = {3,2,1,0,4};
	cout <<"Can Jump (Test case 1) : " <<(solution.canJump(nums1) ? "True":"False")<<endl;
	
	vector<int> nums2 = {2,3,1,1,4};
	cout <<"Can Jump (Test case 2) : " <<(solution.canJump(nums2) ? "True":"False")<<endl;
	
	vector<int> nums3 = {0};
	cout <<"Can Jump (Test case 3) : " <<(solution.canJump(nums3) ? "True":"False");
	
	return 0;
}