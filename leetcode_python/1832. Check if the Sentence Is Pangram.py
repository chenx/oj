class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        charCount = [0] * 26

        for ch in sentence:
            charCount[ord(ch) - ord('a')] += 1
        
        for ct in charCount:
            if ct == 0:
                return False
        return True

/**
1832. Check if the Sentence Is Pangram
Solved
Easy
Topics
conpanies iconCompanies
Hint

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:

Input: sentence = "leetcode"
Output: false
 */
