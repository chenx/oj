// Time: O(nm), n = dictionary.size(), m = average word length.
// Space: O(1)
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string result;
        for (string& word : dictionary) {
            if (! isSubsequence(s, word)) continue;

            if (word.length() > result.length() || 
                (word.length() == result.length() && word.compare(result) < 0)) {
                result = word;
            }
        }
        return result;
    }

    // Returns true if t is a subsequence of s
    bool isSubsequence(string& s, string& t) {
        if (s.length() < t.length()) return false;
        int j = 0;
        for (int i = 0; i < s.length() && j < t.length(); ++ i) {
            if (s[i] == t[j]) ++ j;
        }
        return j == t.length();
    }
};


/**
524. Longest Word in Dictionary through Deleting
Medium

Given a string s and a string array dictionary, return the longest string in the dictionary that 
can be formed by deleting some of the given string characters. If there is more than one possible 
result, return the longest word with the smallest lexicographical order. If there is no possible 
result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
 */
