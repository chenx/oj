// N = words.size(), L is the maximum possible length of a word.
// Time complexity: O(L^2 * N)
// Space complexity: O(N)
class Solution2 {
    int getMaxLen(string& word, set<string>& dict, map<string, int>& memo) {
        if (memo.contains(word)) return memo[word];

        int maxLen = 1;
        for (int i = 0; i < word.length(); ++ i) {
            string next = word.substr(0, i) + word.substr(i+1);
            if (dict.contains(next)) {
                maxLen = max(maxLen, 1 + getMaxLen(next, dict, memo));
            }
        }
        memo[word] = maxLen;
        return maxLen;
    }

public:
    int longestStrChain(vector<string>& words) {
        set<string> dict(words.begin(), words.end());
        map<string, int> memo;
        int maxLen = 0;
        for (auto word : words) {
            maxLen = max(maxLen, getMaxLen(word, dict, memo));
        }
        return maxLen;
    }
};


class Solution {
private:
    int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + dfs(words, memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(wordsPresent, memo, word));
        }
        return ans;
    }
};


/**
1048. Longest String Chain
Medium

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without 
changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor 
of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
 */
