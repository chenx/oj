// From: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/editorial
class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> map;  // <char, count>

        for (const char c : s) {
            -- map[c];
        }
        for (const char c : t) {
            ++ map[c];
        }

        int ans = 0;
        for (auto e : map) {
            if (e.second > 0) ans += e.second;
        }
        return ans;
    }
};

/**
1347. Minimum Number of Steps to Make Two Strings Anagram
Medium

You are given two strings of the same length s and t. In one step you can choose any character of t and 
replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 */
