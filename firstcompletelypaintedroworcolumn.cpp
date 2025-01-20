#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        unordered_map<int,pair<int,int>>mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = mat[i][j];
                mp[val]={i,j};
            }
        }

        vector<int>rowCountPaint(m,0);
        vector<int>colCountPaint(n,0);

        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            // auto [row, col]=mp[val];     will work for c++17 compiler 
            int row=mp[val].first;
            int col=mp[val].second;

            rowCountPaint[row]++;
            colCountPaint[col]++;

            if(rowCountPaint[row]==n || colCountPaint[col] == m){
                return i;
            }
        }
        return -1;
    }
};

class SolutionTwo{
    public:
    int firstCompleteIndex(vector<int>&arr, vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();

        unordered_map<int, int>mp;

        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            mp[val]=i;
        }

        int minIndex=INT_MAX;

        for(int i=0;i<m;i++){
            int lastIndex=INT_MIN;

            for(int j=0;j<n;j++){
                int val=mat[i][j];
                int idx=mp[val];
                lastIndex=max(lastIndex, idx);
            }

            minIndex = min(minIndex, lastIndex);
        }

        for(int i=0;i<n;i++){
            int lastIndex=INT_MIN;

            for(int j=0;j<m;j++){
                int val=mat[j][i];
                int idx=mp[val];
                lastIndex=max(lastIndex, idx);
            }

            minIndex = min(minIndex, lastIndex);
        }

        return minIndex;
    }
};

int main(){
    Solution sol;
    vector<int>arr={1,3,4,2};
    vector<vector<int>>mat={{1,4},{2,3}};
    cout<<sol.firstCompleteIndex(arr,mat);

    return 0;
}