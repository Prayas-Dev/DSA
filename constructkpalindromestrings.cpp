#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
    bool canConstruct(string s, int k){
        if(k>s.size()){
            return false;
        }
        if(k==s.size()){
            return true;
        }
        vector<int>charCount(26,0);
        for(char &ch:s){
            charCount[ch-'a']++;
        }
        int oddNum=0;
        for(int i=0;i<26;i++){
            if(charCount[i]%2!=0){
                oddNum++;
            }
        }
        if(oddNum<=k){
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s="leetcode";
    int k=3;
    int ans=sol.canConstruct(s,k);

    if(ans==0){
        cout<<"False";
    }
    else{
        cout<<"True";
    }

    return 0;

}