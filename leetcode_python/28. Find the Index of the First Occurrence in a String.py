class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(haystack), len(needle)
        if m < n:
            return -1
        
        for i in range(0, m-n+1):
            for j in range(0, n):
                # print(f"compare: (i={i}, j={j}) {haystack[i+j]} ?= {needle[j]}")
                if haystack[i + j] != needle[j]:
                    break
                if j == n-1:
                    return i
        return -1


/**
28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
conpanies iconCompanies

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 */
