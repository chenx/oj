class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int m = A.size(), n = B.size(), maxLen = 0;
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (A[i-1] == B[j-1]) DP[i][j] = 1 + DP[i-1][j-1];
                else DP[i][j] = 0;
                
                maxLen = max(maxLen, DP[i][j]);
            }
        }
        
        return maxLen;
    }
};


/**
Longest Common Substring

Given two strings, find the longest common substring.

Return the length of it.
Have you met this question in a real interview?
Notice

The characters in substring should occur continuously in original string. 
This is different with subsequence.

Example

Given A = "ABCD", B = "CBCE", return 2.
Challenge

O(n x m) time and memory.

 */
