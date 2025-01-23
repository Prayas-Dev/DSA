#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>row(m,0);
        vector<int>col(n,0);

        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (row[i]>1 || col[j]>1) ){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>grid={{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout<<sol.countServers(grid);

    return 0;
}