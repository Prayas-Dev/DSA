#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    vector<vector<int>>prerequisites={{1,0},{2,0},{2,1},{3,1}};
    unordered_map<int, vector<int>>adj;
    
    for(vector<int> &vec : prerequisites){
        int v=vec[1];
        int u=vec[0];

        adj[u].push_back(v);
    }
}