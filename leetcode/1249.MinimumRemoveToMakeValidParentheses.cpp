// See: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/editorial/
class Solution3 {
public:
    string minRemoveToMakeValid(string s) {
        int diffCount = 0;

        string t = minRemove(s, '(', ')');

        reverse(t.begin(), t.end());
        string result = minRemove(t, ')', '(');

        reverse(result.begin(), result.end());
        return result;
    }

    string minRemove(string& s, char open, char close) {
        int diffCount = 0;

        // remove RHS close char.
        string t;
        for (char ch : s) {
            if (ch == open) {
                ++ diffCount;
            } else if (ch == close) {
                if (diffCount == 0) continue;
                -- diffCount;
            }
            t += ch;
        }
        return t;
    }
};

// Same as Solution. Better naming from 'total' to 'balance'.
// Time complexity : O(n), where n is the length of the input string.
// Space complexity : O(n), where n is the length of the input string.
class Solution2 {
public:
    string minRemoveToMakeValid(string s) {
        int openCount = 0, balance = 0;

        string t;
        // Remove ')'
        for (char ch : s) {
            if (ch == '(') {
                ++ openCount;
                ++ balance;
            } else if (ch == ')') {
                if (balance == 0) continue;
                -- balance;
            }
            t += ch;
        }

        // Remove '(' on RHS
        string result;
        int openToKeep = openCount - balance;
        for (char ch : t) {
            if (ch == '(') {
                if (openToKeep == 0) continue;
                -- openToKeep;
            }
            result += ch;
        }
        return result;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // remove invalid ')'
        int openCount = 0, total = 0;
        string t;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == '(') {
                ++ openCount;
                ++ total;
            } else if (s[i] == ')') {
                if (total == 0) continue;
                -- total;
            }
            t += s[i];
        }

        // remove invalid '(' from RHS
        int openToKeep = openCount - total;
        string ans;
        for (int i = 0; i < t.length(); ++ i) {
            if (t[i] == '(') {
                if (openToKeep == 0) continue;
                -- openToKeep;
            }
            ans += t[i];
        }
        return ans;
    }
};

/**
1249. Minimum Remove to Make Valid Parentheses
Medium

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that 
the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.
 */
