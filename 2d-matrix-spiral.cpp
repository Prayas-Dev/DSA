#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int row=matrix.size();
        int col=matrix[0].size();

        int total=row*col;

        vector<int>ans;
        int count=0;

        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        while(count<total){

            for(int i=startingCol;i<=endingCol && count<total;i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            for(int i=startingRow;i<=endingRow && count<total;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            for(int i=endingCol;i>=startingCol;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            for(int i=endingRow;i>=startingRow && count<total;i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }

};

int main(){

    Solution sol;

    vector<vector<int>>matrix(5,vector<int>(4));
    cout<<"Enter the values of array : "<<endl;

    int row=matrix.size();
    int col=matrix[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
        cout<<endl;
    }

    cout<<"The Matrix is : "<<endl;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The spiral pattern of the above matrix is : "<<endl;
    vector<int>result=sol.spiralOrder(matrix);
    for(int ele:result){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}