# Check [:i], then [:j] and [j:i]
# apple+pen+apple
# Time: O(n^2*k + n*k), n = len(s), k = average length of a word
# Space: O(n + m*k), m = len(wordDict)
class Solution2:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        n = len(s)
        DP = [False] * n

        for i in range(1, 1+n): # O(n)
            if s[:i] in wordSet:  # O(k), k = length(s[:i])
                DP[i-1] = True
            else:
                for j in range(1, 1+i):  # O(n)
                    if DP[j-1] and s[j:i] in wordSet: # O(k)
                        DP[i-1] = True
                        break
        
        print(DP)
        return DP[n-1]


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        n = len(s)

        DP = [False] * n

        # Check [:i], then [:j] and [j:i]
        # apple+pen+apple
        # print(f"s[0]: {s[:0]}, s[1]: {s[:1]}")
        for i in range(n):
            # print(s[:i+1])
            if s[:i+1] in wordSet: # s[0, i]. "a"[:0] = "", "a"[:1] = "a"
                DP[i] = True
            else:
                for j in range(i):
                    # s[0,j], s[j, i-j]
                    # print(f"2: {s[:j+1], s[j+1:i+1]}")
                    if DP[j] and s[j+1:i+1] in wordSet:
                        DP[i] = True
                        break
        
        print(DP)
        return DP[n-1]



/**
139. Word Break
Solved
Medium
Topics
conpanies iconCompanies

Given a string s and a dictionary of strings wordDict, return true if s can be segmented 
into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
 */
