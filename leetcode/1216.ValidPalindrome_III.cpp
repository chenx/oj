// From: https://leetcode.com/problems/valid-palindrome-iii/editorial/
// Bottom up DP.
// Time complexity : O(n^2). Where n is the length of string s
// Space complexity : O(n^2). 
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), 0));

        // Generate all combinations of `i` and `j` in the correct order.
        for (int i = s.length() - 2; i >= 0; i--)
            for (int j = i + 1; j < s.length(); j++) {

                // Case 1: Character at `i` equals character at `j`
                if (s[i] == s[j])
                    memo[i][j] = memo[i + 1][j - 1];

                // Case 2: Character at `i` does not equal character at `j`.
                // Either delete character at `i` or delete character at `j`
                // and try to match the two pointers using recursion.
                // We need to take the minimum of the two results and add 1
                // representing the cost of deletion.
                else
                    memo[i][j] = 1 + min(memo[i + 1][j], memo[i][j - 1]);
            }

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return memo[0][s.length() - 1] <= k;
    }
};

/**
1216. Valid Palindrome III
Hard

Given a string s and an integer k, return true if s is a k-palindrome.

A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.

 

Example 1:

Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.

Example 2:

Input: s = "abbababa", k = 1
Output: true
 */
