class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        if n == 0: return 0

        maxLen = len(strs[0])
        for i in range(1, n):
            maxLen = min(maxLen, len(strs[i]))
            for j in range(maxLen):
                if strs[0][j] != strs[i][j]:
                    maxLen = j
                    break
        
        return strs[0][:maxLen]

/**
14. Longest Common Prefix
Solved
Easy
Topics
conpanies iconCompanies

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 */
