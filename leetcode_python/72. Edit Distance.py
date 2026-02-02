class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1, len2 = len(word1), len(word2)
        DP = [[0 for _ in range(1 + len2)] for _ in range(1 + len1)]

        for i in range(1, 1 + len1):
            DP[i][0] = i
        for j in range(1, 1 + len2):
            DP[0][j] = j
        
        for i in range(1, 1 + len1):
            for j in range(1, 1 + len2):
                if word1[i-1] == word2[j-1]:
                    DP[i][j] = DP[i-1][j-1]
                else:
                    DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]))
        
        return DP[len1][len2]

/**
72. Edit Distance
Solved
Medium
Topics
conpanies iconCompanies

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
 */
