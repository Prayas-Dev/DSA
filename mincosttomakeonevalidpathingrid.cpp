#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

class SolutionOne{
    public:

    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int cost){
        if(i==m-1 && j==n-1){
            return cost;
        }
        visited[i][j] = true;

        int minCost = INT_MAX;
        for(int dir_i=0;dir_i<=3;dir_i++){
            int i_ = i + dir[dir_i][0];
            int j_ = j + dir[dir_i][1];

            if(i_>=0 && i_ < m &&
               j_>=0 && j_ < n &&
               !visited[i_][j_]){
                int nextCost = cost + ((grid[i][j]-1 !=dir_i) ? 1 : 0);
                minCost=min(minCost, dfs(i_, j_, grid, visited, nextCost));
            }
        }

        visited[i][j]=false;
        return minCost;
    }

    int minCost(vector<vector<int>>& grid){
        
        m=grid.size();      // row
        n=grid[0].size();       // column

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0,0,grid,visited,0);
    }
};

class SolutionTwo{                      // Using Dijkstra's Algorithm
    public:
    
    vector<vector<int>>dir={ {1,0},{} };
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0,0,0});
        result[0][0]=0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int i=curr[1];
            int j=curr[2];

            for(int dir_i=0;dir_i<=3;dir_i++){
                int i_=i+dir[dir_i][0];
                int j_=j+dir[dir_i][1];

                if(i_>=0 && j_>=0 && i_<m && j_<n){
                    int gridDir=grid[i][j];
                    int dirCost = (gridDir-1 != dir_i) ? 1 : 0;

                    int newCost = currCost + dirCost;

                    if(newCost < result[i_][j_]) {
                        result[i_][j_] = newCost;
                        pq.push({newCost, i_,j_});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};

int main(){
    SolutionOne sol1;
    vector<vector<int>>grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout<<sol1.minCost(grid);

    return 0;
}