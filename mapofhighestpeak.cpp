#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:

    typedef pair<int, int>P;
    vector<vector<int>> direction={{0,1},{0,-1},{-1,0},{1,0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m=isWater.size();
        int n=isWater[0].size();

        vector<vector<int>>ans(m, vector<int>(n,-1));

        queue<P>qu;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    qu.push({i, j});
                }
            }
        }

        while(!qu.empty()){
            int N = qu.size();

            while(N--){
                P curr = qu.front();
                qu.pop();

                int i=curr.first;
                int j=curr.second;

                for(auto &dir:direction){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >=0 && j_ <n && ans[i_][j_]==-1){
                        ans[i_][j_] = ans[i][j] + 1;
                        qu.push({i_, j_});
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<int>>isWater={{0,1},{0,0}};
    vector<vector<int>>ans=sol.highestPeak(isWater);

    for(auto row:ans){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}