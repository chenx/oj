// See: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/editorial/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return accumulate(word1.begin(), word1.end(), string{}) == 
               accumulate(word2.begin(), word2.end(), string{});
    }
};


/**
1662. Check If Two String Arrays are Equivalent
Topics

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 */
