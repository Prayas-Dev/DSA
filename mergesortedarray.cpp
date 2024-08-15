#include<iostream>
#include<vector>

using namespace std;

class Solution {
	public :
		void merge(vector<int>& nums1, int m, vector<int>&nums2, int n){
			int i = m-1;
			int j = n-1;
			int k = m + n -1;
			
			while(i>=0 && j>=0){
				if(nums1[i]>nums2[j]){
					nums1[k]=nums1[i];
					i--;
				}
				else{
					nums1[k]=nums2[j];
					j--;
				}
				k--;
			}
			while(j>=0){
				nums1[k]=nums2[j];
				j--;
				k--;
			}
		}
};

int main(){
	Solution solution;
	
	vector<int> nums1={4,6,8,0,0,0};
	vector<int> nums2={2,5,6};
	
	solution.merge(nums1,3,nums2,3);
	
	for(int num:nums1){
		cout<<num<<" ";
	}
	cout<<endl;
	
	return 0;
}