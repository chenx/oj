// From: https://leetcode.com/problems/valid-parenthesis-string/editorial
// O(n) time, O(1) space.
class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0, closeCount = 0, n = s.length();
        for (int i = 0; i < n; ++ i) {
            if (s[i] == '(' || s[i] == '*') ++ openCount;
            else -- openCount;

            if (s[n-1-i] == ')' || s[n-1-i] == '*') ++ closeCount;
            else -- closeCount;

            if (openCount < 0 || closeCount < 0) return false;
        }

        return true;
    }
};

/**
678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 */
