#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int col = matrix[0].size();
        int end = matrix.size() * col - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            int r = mid / col;
            int c = mid % col;

            if (matrix[r][c] == target) {
                return true;
            }
            else if (target < matrix[r][c]) {
                end = mid - 1;  
            }
            else {
                st = mid + 1; 
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 9;

    Solution sol;
    bool found = sol.searchMatrix(matrix, n);  
    cout << (found ? "Element found" : "Element not found") << endl;  

    return 0;
}
