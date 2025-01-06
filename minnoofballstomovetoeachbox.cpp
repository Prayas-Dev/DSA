#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> minOperation(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int cumValue = 0;
        int cumValueSum = 0;

        for (int i = 0; i < n; i++)
        {
            ans[i] = cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        cumValue = 0;
        cumValueSum = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] += cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string box = "110";
    vector<int> ans = sol.minOperation(box);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}