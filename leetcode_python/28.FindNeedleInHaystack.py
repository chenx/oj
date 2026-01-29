class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        if n < m:
            return -1
        
        for i in range(n-m):
            for j in range(m):
                if haystack[i+j] != needle[j]:
                    break
                if j == m-1: return i
        return -1

/**
28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
conpanies iconCompanies

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
 */
