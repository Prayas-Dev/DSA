#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
    public:

        bool isSubset(vector<int>& freq2, vector<int>& temp){
            for(int i=0;i<26;i++){
                if(temp[i]<freq2[i]){
                    return false;
                }
            }
            return true;
        }

        vector<string> wordSubsets(vector<string>& words1, vector<string> & words2) {
            vector<string>result;

            vector<int>freq2(26);
            for(string &words:words2){
                int temp[26]={0};

                for(char &ch:words){
                    temp[ch-'a']++;

                    freq2[ch-'a'] = max(freq2[ch-'a'], temp[ch-'a']);
                }
            }
            
            for(string &word: words1){
                vector<int> temp(26,0);

                for(char &ch : word){
                    temp[ch-'a']++;
                }

                if(isSubset(freq2, temp)==true){
                    result.push_back(word);
                }
            }
            return result;

        }
};

int main(){
    Solution sol;
    vector<string>words1={"amazon","apple","facebook","google","leetcode"};
    vector<string>words2={"e","o"};

    vector<string>ans=sol.wordSubsets(words1,words2);

    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}