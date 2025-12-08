// See: https://leetcode.com/problems/permutation-in-string/editorial/
// Time: O(m + n) = O(n), n = s2.length(), m = s1.length()
// Space: O(m + n) = O(26 + 26) = O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> ct1, ct2;
        for (char ch : s1) ++ ct1[ch];

        int i = 0, left = 0;
        for (; i < s1.length(); ++ i) {
            ++ ct2[s2[i]];
        }
        for (; i < s2.length(); ++ i) { // O(n)
            if (ct1 == ct2) return true;  // O(26) = O(1)

            ++ ct2[s2[i]];
            if (-- ct2[s2[left]] == 0) ct2.erase(s2[left]);
            ++ left;
        }
        return ct1 == ct2;  // O(26) = O(1)
    }
};


/**
567. Permutation in String
Medium

Given two strings s1 and s2, return true if s2 contains a

of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 */
