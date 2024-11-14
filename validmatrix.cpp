#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    void setZeroes(vector<vector<int>>& matrix){
        vector<int>rowMatrix(matrix.size());
        vector<int>columnMatrix(matrix[0].size());  
        int k=0,l=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    rowMatrix[k]=i;
                    k++;
                    columnMatrix[l]=j;
                    l++;
                }
            }
        }
        setZeroes(matrix,rowMatrix,columnMatrix);
    }
    void setZeroes(vector<vector<int>>&matrix,vector<int>&rowMatrix, vector<int>&columnMatrix){
        for(int i=0;i<rowMatrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=0;
            }
        }
        for(int i=0;i<columnMatrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[j][i]=0;
            }
        }
    }

};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
};

    return 0;
}