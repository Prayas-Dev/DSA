#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    bool isVowel(char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    public:
        vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
            int Q=queries.size();
            int N=words.size();

            vector<int>result(Q);

            vector<int>cumSum(N);
            int sum=0;

            for(int i=0;i<N;i++){
                if(isVowel(words[i][0]) && isVowel(words[i].back())){
                    sum++;
                }
                cumSum[i]=sum;
            }
            for(int i=0;i<Q;i++){
                int l=queries[i][0];
                int r=queries[i][1];

                result[i]=cumSum[r] - ((l>0) ? cumSum[l-1]:0);
            }
            return result;
        }
};

int main(){
    Solution sol;
    vector<string> words={"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries= {{0,2},{1,4},{1,1}};
    vector<int>ans=sol.vowelStrings(words,queries);

    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}