#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int row = ans.size();
        int col = ans[0].size();

        int total = row * col;
        int count = 1;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        while (count <= total)
        {
            // starting Row
            for (int i = startingCol; i <= endingCol && count <= total; i++)
            {
                ans[startingRow][i]=count++;
            }
            startingRow++;

            // ending Col
            for (int i = startingRow; i <= endingRow && count <= total; i++)
            {
                ans[i][endingCol]=count++;
            }
            endingCol--;

            // ending row
            for (int i = endingCol; i >= startingCol && count <= total; i--)
            {
                ans[endingRow][i]=count++;
            }
            endingRow--;

            // starting col
            for (int i = endingRow; i >= startingRow && count <= total; i--)
            {
                ans[i][startingCol]=count++;
            }
            startingCol++;
        }
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution sol;

    cout<<"Your matrix is : "<<endl;

    vector<vector<int>> ans = sol.generateMatrix(n);

    for (const auto &row : ans)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}