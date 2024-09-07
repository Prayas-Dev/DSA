#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
    //My Solution :
        // void rotate(vector<vector<int>>&matrix){
        //     vector<vector<int>>ans(matrix);
        //     int row=matrix.size();
        //     int col=matrix[0].size();
        //     int endingCol=col-1;

        //     int n=0;

        //     while(n<row){
        //         for(int i=0;i<col;i++){
        //             ans[i][endingCol]=matrix[n][i];
        //         }
        //         n++;
        //         endingCol--;
        //     }
        //     matrix=ans;
        // }

        //Optimized Solution
        void rotate(vector<vector<int>>&matrix){
            int n=matrix.size();

            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }

};

int main(){

    Solution sol;

    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Given matrix is : "<<endl;
    for(const auto&ele:matrix){
        for(int row:ele){
            cout<<row<<" ";
        }
        cout<<endl;
    }

    cout<<"After rotating matrix : "<<endl;

    sol.rotate(matrix);

    for(const auto&ele:matrix){
        for(auto row:ele){
            cout<<row<<" ";
        }
        cout<<endl;
    }

    return 0;
}