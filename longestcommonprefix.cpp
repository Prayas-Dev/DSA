#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // If the input vector is empty, return an empty string

        string prefix = strs[0]; // Assume the first string is the common prefix

        // Iterate over the rest of the strings in the vector
        for (int i = 1; i < strs.size(); i++) {
            // Check the current string and compare with the prefix
            while (strs[i].find(prefix) != 0) {
                // If the prefix is not found at the start of the current string,
                // reduce the prefix by one character from the end
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return ""; // If prefix becomes empty, return empty string
            }
        }
        return prefix; // Return the final longest common prefix
    }
};

int main() {
    Solution solution;

    // Example input
    vector<string> strs = {"flower", "flow", "flight"};
    
    // Call the longestCommonPrefix method
    string result = solution.longestCommonPrefix(strs);
    
    // Print the result
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}