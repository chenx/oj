// Time: O(n), n is the number of words in all sentences.
// Space: O(1).
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWordsCount = 0;
        for (auto& sentence : sentences) {
            maxWordsCount = max(maxWordsCount, getWordsCount(sentence));
        }
        return maxWordsCount;
    }

    int getWordsCount(string& s) {
        int count = 0;
        for (char ch : s) {
            if (ch == ' ') ++ count;
        }
        return count + 1;
    }
};


/**
2114. Maximum Number of Words Found in Sentences
Easy

A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.
 */
