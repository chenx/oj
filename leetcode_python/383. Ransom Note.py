from collections import defaultdict
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        charCount = defaultdict(int)
        for ch in magazine:
            charCount[ch] += 1
        
        for ch in ransomNote:
            if not ch in charCount:
                return False
            charCount[ch] -= 1
            if charCount[ch] < 0:
                return False
        return True

/**
383. Ransom Note
Solved
Easy
Topics
conpanies iconCompanies

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters 
from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 */
