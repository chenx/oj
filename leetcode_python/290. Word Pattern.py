class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        if len(pattern) != len(s):
            return False
        
        map1 = {}
        map2 = {}

        for i in range(len(s)):
            a = pattern[i]
            b = s[i]

            if a not in map1:
                map1[a] = b
            elif map1[a] != b:
                return False

            if b not in map2:
                map2[b] = a
            elif map2[b] != a:
                return False
                
        return True

/**
290. Word Pattern
Solved
Easy
Topics
conpanies iconCompanies

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and 
a non-empty word in s. Specifically:

    Each letter in pattern maps to exactly one unique word in s.
    Each unique word in s maps to exactly one letter in pattern.
    No two letters map to the same word, and no two words map to the same letter.
 */
