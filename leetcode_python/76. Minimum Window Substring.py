class Solution2:
    def minWindow(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        if m < n:
            return ""

        toFind, found = {}, {} # <char, count>

        for ch in list(t):
            toFind[ch] = toFind.get(ch, 0) + 1
        
        minLen, minStart = 0, 0
        start = 0
        total = 0
        for i in range(m):
            ch = s[i]
            found[ch] = found.get(ch, 0) + 1
            if ch in toFind and found[ch] <= toFind[ch]:
                total += 1

            if total == n:
                while s[start] not in toFind or found[s[start]] > toFind[s[start]]:
                    found[s[start]] -= 1
                    start += 1
                size = i - start + 1
                if minLen == 0 or minLen > size:
                    minLen = size
                    minStart = start

        return "" if minLen == 0 else s[minStart : (minStart + minLen)]


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m, n = len(s), len(t)

        toFind : Dict[str, int] = {}
        found  : Dict[str, int] = {}

        for ch in list(t):
            toFind[ch] = toFind.get(ch, 0) + 1
        
        start = 0
        total = 0
        minWinLen = 0
        minWinStart = -1
        for i in range(m):
            ch = s[i]
            found[ch] = found.get(ch, 0) + 1
            if ch in toFind and found[ch] <= toFind[ch]:
                total += 1
            
            while total == n:
                winLen = i - start + 1
                if minWinLen == 0 or minWinLen > winLen:
                    minWinLen = winLen
                    minWinStart = start
                
                if s[start] not in toFind or found[s[start]] > toFind[s[start]]:
                    found[s[start]] -= 1
                    start += 1
                else:
                    break
        
        return "" if minWinStart == -1 else s[minWinStart : minWinStart + minWinLen]


/**
76. Minimum Window Substring
Solved
Hard
Topics
conpanies iconCompanies
Hint

Given two strings s and t of lengths m and n respectively, return the minimum window of s such that 
every character in t (including duplicates) is included in the window. If there is no such substring, 
return the empty string "".

The testcases will be generated such that the answer is unique.
 */
