from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if beginWord == endWord:
            return 1
        
        words = set(wordList)
        
        q = deque()
        q.append([beginWord, 1])

        visited = set()
        visited.add(beginWord)

        while len(q) > 0:
            curWord, dist = q.popleft()

            for i in range(len(curWord)):
                # for each char of curWord, try different letters
                for j in range(ord('a'), ord('z') + 1):
                    if chr(j) == curWord[i]:
                        continue

                    nextWord = curWord[:i] + chr(j) + curWord[i+1:]
                    # print(f"nextWord = {nextWord}")
                    if nextWord in words and not nextWord in visited:
                        if nextWord == endWord:
                            return 1 + dist
                        q.append([nextWord, 1 + dist])
                        visited.add(nextWord)

        return 0

/**
127. Word Ladder
Hard

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest 
transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 */
