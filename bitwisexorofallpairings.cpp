#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class SolutionOne{
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {        // O(n*m) Not applicable
        
        int x = 0;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                x ^= (nums1[i] ^ nums2[j]);
            }
        }
        return x;
    }
};

class SolutionTwo{
    public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2){
        int m=nums1.size();
        int n=nums2.size();

        unordered_map<int, long>mp;

        for(int &num:nums1){
            mp[num]+=n;
        }
        for(int &num:nums2){
            mp[num]+=m;
        }

        int result=0;
        for(auto &it:mp){
            int num=it.first;
            int freq=it.second;

            if(freq%2!=0){
                result ^= num;
            }
        }
        return result;
    }
};

class SolutionThree{
    public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2){
        int xor1=0,xor2=0,result=0;
        for(auto &ele:nums1){
            xor1^=ele;
        }
        for(auto &ele:nums2){
            xor2^=ele;
        }
        int m=nums1.size();
        int n=nums2.size();

        if(m%2!=0){
            result^=xor2;
        }
        if(n%2!=0){
            result^=xor1;
        }
        return result;
    }
};

int main(){
    // SolutionOne sol1;
    // SolutionTwo sol2;
    SolutionThree sol3;
    vector<int>nums1={2,1,3};
    vector<int>nums2={10,2,5,0};
    // cout<<sol1.xorAllNums(nums1, nums2);
    // cout<<sol2.xorAllNums(nums1, nums2);
    cout<<sol3.xorAllNums(nums1, nums2);

    return 0;
}