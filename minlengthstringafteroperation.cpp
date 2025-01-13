#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
    public:
    int minimumLength(string s){
        unordered_map<char, int> mp;
        for(auto c:s){
            mp[c]++;
        }

        int ans=0;
        for(auto p:mp){
            int count=p.second;
            while(count>=3){
            count-=2;
            }
            ans+=count;
        }
        return ans;
    }
};  

int main(){
    Solution sol;
    string s="abaacbcbb";
    cout<<sol.minimumLength(s);

    return 0;
}