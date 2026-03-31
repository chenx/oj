class Solution2:
    def addBoldTag(self, s: str, words: List[str]) -> str:
        n = len(s)
        bold = [False] * n
        for word in words:
            index = s.find(word)
            while index != -1:
                for i in range(index, index + len(word)):
                    bold[i] = True
                index = s.find(word, index + 1)
        
        result = []  # use list instead of str.
        for i in range(n):
            if bold[i] and (i == 0 or not bold[i-1]):
                result.append('<b>')
            result.append(s[i])
            if bold[i] and (i == n-1 or not bold[i+1]):
                result.append('</b>')
        return ''.join(result)


# Let n be s.length, m be words.length, and k be the average length of the words.
# Time complexity: O(m⋅(n^2⋅k−n⋅k^2))
# Space: O(n)
class Solution:
    def addBoldTag(self, s: str, words: List[str]) -> str:
        n = len(s)
        bold = [False] * n
        for word in words: # m
            index = s.find(word) # n*k, at most (n-k) times
            while index != -1:
                for j in range(index, index + len(word)): # 
                    bold[j] = True
                index = s.find(word, index + 1)

        result = ''
        for i in range(n): # n
            if bold[i] and (i == 0 or not bold[i-1]):
                result += '<b>'
            result += s[i]
            if bold[i] and (i == n-1 or not bold[i+1]):
                result += '</b>'

        return result


/**
616. Add Bold Tag in String
Solved
Medium
Topics
conpanies iconCompanies

You are given a string s and an array of strings words.

You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words.

    If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag.
    If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.

 

Example 1:

Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
Explanation: The two strings of words are substrings of s as following: "abcxyz123".
We add <b> before each substring and </b> after each substring.

Example 2:

Input: s = "aaabbb", words = ["aa","b"]
Output: "<b>aaabbb</b>"
 */
