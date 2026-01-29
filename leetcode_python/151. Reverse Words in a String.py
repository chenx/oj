// Form: https://leetcode.com/problems/reverse-words-in-a-string/
class Solution3:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))


class Solution2:
    def reverseWords(self, s: str) -> str:
        def reverse(s, start, end):
            s = list(s) # convert string to list
            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
            return "".join(s)
    
        s = " ".join(s.split()) # remove multiple spaces
        
        arr = s.split(" ")
        arr.reverse()
        for s in arr:
            s = reverse(s, 0, len(s) - 1)

        return " ".join(arr)


class Solution:
    def reverseWords(self, s: str) -> str:
        def reverse(s, start, end):
            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
    
        s = " ".join(s.split()) # remove multiple spaces
        s = list(s) # split chars to an array.
        
        start, end = 0, 0
        n = len(s)
        while start < len(s):
            while end < n and s[end].isspace():
                end += 1

            start = end
            while end < n and not s[end].isspace():
                end += 1
            
            reverse(s, start, end - 1)
            start = end
        
        s.reverse()
        s = "".join(s)
        return s



/**
151. Reverse Words in a String
Solved
Medium
Topics
conpanies iconCompanies

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string 
should only have a single space separating the words. Do not include any extra spaces.
 */
