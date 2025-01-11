#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<string> stringMatching(vector<string>&words){
            vector<string>ans;
            int n=words.size();
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j!=i && words[j].find(words[i]) != string::npos){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
            return ans;
        }
};

int main(){
    Solution sol;
    vector<string>words={"mass","as","hero","superhero"};
    vector<string>ans=sol.stringMatching(words);

    for (auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}