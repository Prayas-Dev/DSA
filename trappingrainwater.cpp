#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trappingRainwater(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        int trappedWater = 0;
        for (int i = 0; i < n; i++)
        {
            trappedWater += min(leftMax[i], rightMax[i]) - nums[i];
        }
        return trappedWater;
    }
};

int main()
{

    Solution sol;
    vector<int> nums = {4, 2, 0, 6, 3, 5};
    cout << sol.trappingRainwater(nums) << endl;

    return 0;
}