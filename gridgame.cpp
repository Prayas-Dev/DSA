#include <iostream>
#include <vector>
#include<numeric>
#include<climits>

using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int m=grid.size();
        int n=grid[0].size();

       long long firstRowRemainingSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);

       long long secondRowRemainingSum = 0;

       long long minimizedRobot2Sum = LLONG_MAX;

       for(int Robot1Col = 0;Robot1Col<n;Robot1Col++){
        firstRowRemainingSum -=grid[0][Robot1Col];
        long long bestOfRobot2 = max(firstRowRemainingSum, secondRowRemainingSum);

        minimizedRobot2Sum = min(minimizedRobot2Sum, bestOfRobot2);

        secondRowRemainingSum += grid[1][Robot1Col];
       }
       return minimizedRobot2Sum;
    }
};