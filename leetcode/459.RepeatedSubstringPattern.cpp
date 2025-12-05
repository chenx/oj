// See: https://leetcode.com/problems/repeated-substring-pattern/editorial/
// Let t = s + s. We can easily and efficiently check all possible rotations by 
// removing the first and last character of t, then checking if s is a substring of t.
// TIme: O(n)
// Space: O(1)
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        return ss.substr(1, ss.length() - 2).find(s) != -1;
    }
};


// See: https://leetcode.com/problems/repeated-substring-pattern/editorial/
// Time: O(n * sqrt(n))
// Space: O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int i = 1; i <= n/2; ++ i) {
            if (n % i == 0) {
                string pattern = s.substr(0, i), t;
                for (int j = 0; j < n/i; ++ j) {
                    t += pattern;
                }
                if (t == s) {
                    return true;
                }
            }
        }
        return false;
    }
};


/**
459. Repeated Substring Pattern
Easy / Medium

Given a string s, check if it can be constructed by taking a substring of it and appending 
multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:

Input: s = "aba"
Output: false

Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 */
