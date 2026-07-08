// Greedy. 
// From: https://leetcode.com/problems/word-abbreviation/editorial/
// Time: O(C^2), C is number of all chars in all words.
// Space: O(C)
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        vector<string> result(n);
        vector<int> prefix(n, 0);

        for (int i = 0; i < n; ++ i) {
            result[i] = abbr(words[i], 0);
        }

        // get abbr fro each word, add to a count map.
        // - entries with count 0 go to result
        // - others go through process again.
        for (int i = 0; i < n; ++ i) {
            while (true) {
                unordered_set<int> dup;
                for (int j = i + 1; j < n; ++ j) {
                    if (result[j] == result[i]) {
                        dup.insert(j);
                    }
                }
                if (dup.empty()) break;

                dup.insert(i);
                for (int index : dup) {
                    result[index] = abbr(words[index], ++ prefix[index]);
                }
            }
        }

        return result;
    }

    string abbr(string& word, int i) {
        int n = word.length();
        if (n - i <= 3) return word;
        return word.substr(0, i+1) + to_string(n - i - 2) + word.back();
    }
};


/**
527. Word Abbreviation
Solved
Hard
Topics
conpanies iconCompanies

Given an array of distinct strings words, return the minimal possible abbreviations for every word.

The following are the rules for a string abbreviation:

    The initial abbreviation for each word is: the first character, then the number of characters in between, 
        followed by the last character.
    If more than one word shares the same abbreviation, then perform the following operation:
        Increase the prefix (characters in the first part) of each of their abbreviations by 1.
            For example, say you start with the words ["abcdef","abndef"] both initially abbreviated as "a4f". 
            Then, a sequence of operations would be ["a4f","a4f"] -> ["ab3f","ab3f"] -> ["abc2f","abn2f"].
        This operation is repeated until every abbreviation is unique.
    At the end, if an abbreviation did not make a word shorter, then keep it as the original word.

 

Example 1:

Input: words = ["like","god","internal","me","internet","interval","intension","face","intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

Example 2:

Input: words = ["aa","aaa"]
Output: ["aa","aaa"]
 */
