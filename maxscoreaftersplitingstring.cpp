#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        if(s.size()<2){
            return 0;
        }
        int prefixOne = 0;
        vector<int> prefixSum(s.size(), 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                prefixOne++;
            }
            prefixSum[i] = prefixOne;
        }

        int zero = (s[0] == '1' ? 0 : 1), maxi = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
            maxi = max(maxi, zero + (prefixSum.back()-prefixSum[i-1]));
        }
        return maxi;
    }
};

int main()
{
    Solution sol;

    string s = "011101";
    cout << sol.maxScore(s);

    return 0;
}