#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    vector<vector<int>>createMatrix(int n){
        vector<vector<int>>ans(n,vector<int>(n,0));
        int row=ans.size();
        int col=ans[0].size();

        int total=row*col;
        int count=1;

        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        while(count<=total){
            // Starting Row
            for(int i=startingCol;i<=endingCol && count<=total;i++){
                ans[startingRow][i]=count++;
            }
            startingRow++;

            // Ending Col
            for(int i=startingRow;i<=endingRow && count<=total;i++){
                ans[i][endingCol]=count++;
            }
            endingCol--;

            // Ending Row
            for(int i=endingCol;i>=startingCol && count<=total;i--){
                ans[endingRow][i]=count++;
            }
            endingRow--;

            // Starting Col
            for(int i=endingRow;i>=startingRow && count<=total;i--){
                ans[i][startingCol]=count++;
            }
            startingCol++;
        }
        return ans;
    }

};

int main(){
    Solution sol;
    vector<vector<int>>ans=sol.createMatrix(3);
    for(const auto&ele:ans){
        for(auto row:ele){
            cout<<row<<" ";
        }
        cout<<endl;
    }

    return 0;
}