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
