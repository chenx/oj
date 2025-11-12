// Time Complexity: O(N^2)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = 0;

        for (int i = 0; i < n; ++ i) {
            count += getCount(s, i, i) + getCount(s, i, i+1);
        }
        return count;
    }

    int getCount(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            ++ count;
            -- left, ++ right;
        };
        return count;
    }
};

/**
647. Palindromic Substrings
Medium

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
 */
