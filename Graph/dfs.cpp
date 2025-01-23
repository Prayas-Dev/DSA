#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    vector<int> dfsOfGraph(int V, vector<int> mp[]){
        unordered_map<int, vector<int>> adj;

        for(int u=0;u<V; u++){
            for(auto v = mp[u].begin(); v!=mp->end(); v++){
                adj[u].push_back(*v);
            }
        }

        vector<int>result;
    }
};