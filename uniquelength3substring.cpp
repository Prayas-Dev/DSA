#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> uniquePalindromes;
        vector<int> firstOccurrence(26, -1), lastOccurrence(26, -1);

        for (int i = 0; i < s.length(); i++) {
            if (firstOccurrence[s[i] - 'a'] == -1) {
                firstOccurrence[s[i] - 'a'] = i;
            }
            lastOccurrence[s[i] - 'a'] = i;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int start = firstOccurrence[ch - 'a'];
            int end = lastOccurrence[ch - 'a'];
            if (start != -1 && end != -1 && end > start + 1) {
                unordered_set<char> middleChars;
                for (int i = start + 1; i < end; i++) {
                    middleChars.insert(s[i]);
                }
                for (char mid : middleChars) {
                    uniquePalindromes.insert(string(1, ch) + mid + ch);
                }
            }
        }

        return uniquePalindromes.size();
    }
};

int main(){
    Solution sol;
    string s="aabca";
    cout<<sol.countPalindromicSubsequence(s);

    return 0;
}