// Time: O(n) - n = s.length()
// Space: O(k) - k is number of distinct chars.
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> count;
        for (char ch : s) ++ count[ch];

        int maxCount = 0;
        char maxChar;
        for (auto [ch, ct] : count) {
            if (ct > maxCount) {
                maxCount = ct;
                maxChar = ch;
            }
        }

        if (maxCount > (s.length() + 1) / 2) return "";

        // place maxChar.
        string t = s;
        int i = 0;
        for (; i < s.length() && count[maxChar] > 0; i += 2) {
            t[i] = maxChar;
            -- count[maxChar];
        }

        // place other chars.
        for (auto [ch, ct] : count) {
            while (ct > 0) {
                if (i >= s.length()) i = 1;
                t[i] = ch;
                i += 2;
                -- ct;
            }
        }
        return t;        
    }
};


/**
767. Reorganize String
Medium

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"

Example 2:

Input: s = "aaab"
Output: ""
 */
