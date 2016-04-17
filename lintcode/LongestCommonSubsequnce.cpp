class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int m = A.size(), n = B.size(), maxLen = 0;
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (A[i-1] == B[j-1]) DP[i][j] = 1 + DP[i-1][j-1];
                else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
        
        return DP[m][n];
    }
};


/**
Longest Common Subsequence

Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.
Have you met this question in a real interview?
Clarification

What's the definition of Longest Common Subsequence?

    https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
    http://baike.baidu.com/view/2020307.htm

Example

For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

For "ABCD" and "EACB", the LCS is "AC", return 2.

 */
