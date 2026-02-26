class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(list(s)) == sorted(list(t))


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        def getCharCountMap(x):
            map = {}
            for i in range(len(x)):
                map[x[i]] = map.get(x[i], 0) + 1
            return map
        
        return getCharCountMap(s) == getCharCountMap(t)

/**
242. Valid Anagram
Solved
Easy
Topics
conpanies iconCompanies

Given two strings s and t, return true if t is an of s, and false otherwise.
 */
