// Given n as the length of chars, m as the length of words and k as the average length of each word in words,
// Time complexity: O(n+m⋅k)
// Space: O(26) =~ O(1)
//
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        map<char, int> count;
        for (char ch : chars) count[ch] ++;

        for (string& word : words) {
            map<char, int> countWord;
            for (char ch : word) countWord[ch] ++;

            bool isGood = true;
            for (auto [ch, ct] : countWord) {
                if (! count.contains(ch) || ct > count[ch]) {
                    isGood = false;
                    break;
                }
            }
            if (isGood) result += word.length();
        }
        return result;
    }
};


/**
1160. Find Words That Can Be Formed by Characters
Easy

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 */
