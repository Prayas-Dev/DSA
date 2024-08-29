#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int smallestsubarraysize(vector<int> &nums, int k)
    {
        int curr_sum = 0;
        int min_size = INT_MAX;
        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];

            while (curr_sum >= k && j <= i)
            {
                min_size = min(min_size, i - j + 1);
                curr_sum -= nums[j];
                j++;
            }
        }
        return (min_size!=INT_MAX)?min_size:0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 4, 45, 6, 10, 19};
    cout << sol.smallestsubarraysize(nums, 51);

    return 0;
}