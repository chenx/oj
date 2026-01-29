class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.split()[-1])

/**
58. Length of Last Word
Solved
Easy
Topics
conpanies iconCompanies

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal consisting of non-space characters only.
 */
