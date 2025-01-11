#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        int prefixCount(vector<string>&words, string prefix){
            int count=0;
            for(int i=0;i<words.size();i++){
                if(words[i].find(prefix)==0){
                    count++;
                }
            }
            return count;
        }
};

int main(){
    Solution sol;
    vector<string>words={"pay","attention","practice","attend"};
    string prefix="at";
    cout<<sol.prefixCount(words,prefix)<<endl;

    return 0;
}