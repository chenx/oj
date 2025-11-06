class Solution {
  public int longestCommonSubsequence(String text1, String text2) {
    int m = text1.length(), n = text2.length();
    int[][] DP = new int[m + 1][n + 1]; // Make a grid of 0's.

    for (int col = n - 1; col >= 0; col--) {
      for (int row = m - 1; row >= 0; row--) {
        if (text1.charAt(row) == text2.charAt(col)) {
          DP[row][col] = 1 + DP[row + 1][col + 1];
        } else {
          DP[row][col] = Math.max(DP[row + 1][col], DP[row][col + 1]);
        }
      }
    }

    return DP[0][0];
  }
}


/**
1143. Longest Common Subsequence
Medium

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without 
changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.
 */
