#include<iostream>
#include<vector>

using namespace std;

class Solution {
	public :
		void rotate(vector<int>& nums,int k){
			vector<int> temp(nums.size());
			for(int i=0;i<nums.size();i++){
				temp[(i+k)%nums.size()]=nums[i];
			}
			nums = temp;
		}
};

int main(){
	Solution solution;
	
	// Test case 1
	vector<int> nums1 = {1,2,3,4,5};
	int k1=2;
	cout<<"Original Array : ";
	for(int num:nums1){
		cout<<num<<" ";
	}
	solution.rotate(nums1,k1);
	cout<<"\nRotated array (k="<<k1<<") : ";
	for(int num:nums1) {
		cout<<num<<" ";
	}
	cout<<endl;
	
	// Test case 2
	vector<int> nums2 = {10,20,30,40,50,60};
	int k2=4;
	cout<<"Original Array : ";
	for(int num:nums2){
		cout<<num<<" ";
	}
	solution.rotate(nums2,k2);
	cout<<"\nRotated array (k="<<k2<<") : ";
	for(int num:nums2){
		cout<<num<<" ";
	}
	cout<<endl;
	
	return 0;
}