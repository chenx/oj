class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        def getMaxLen(word, wordSet, maxLenMemo):
            if word in maxLenMemo:
                return maxLenMemo[word]

            if len(word) == 1:
                return 1

            maxLen = 1  # at least 1 for the current word
            for i in range(len(word)):
                nextWord = word[:i] + word[i+1:]
                # print(f"word = {word}, nextWord = {nextWord}")
                if nextWord in wordSet:
                    maxLen = max(maxLen, 1 + getMaxLen(nextWord, wordSet, maxLenMemo))
            
            maxLenMemo[word] = maxLen
            return maxLen


        wordSet = set(words)
        maxLen = 0
        maxLenMemo : dict[str, int] = {}
        for word in words:
            maxLen = max(maxLen, getMaxLen(word, wordSet, maxLenMemo))
        
        return maxLen



/**
1048. Longest String Chain
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without 
changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor 
of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 */
