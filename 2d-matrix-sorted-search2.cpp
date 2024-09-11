#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    bool searchMatrix(vector<vector<int>>&matrix,int target){
        int row=matrix.size();
        int col=matrix[0].size();

        int rowIndex=0;
        int colIndex=col-1;

        while(rowIndex<row && colIndex>=0){
            int element=matrix[rowIndex][colIndex];
            if(target==element){
                return 1;
            }
            if(element<target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
    }
};

int main(){
    vector<vector<int>>matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=100;

    Solution sol;
    int ans=sol.searchMatrix(matrix,target);
    cout<<(ans==true?"Element found":"Element not found");

    return 0;
}