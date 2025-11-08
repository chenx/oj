class Solution {
public:
    bool validPalindrome(string s) {
        for (int L = 0, R = s.length() - 1; L < R; ++ L, -- R) {
            if (s[L] != s[R]) {
                return isValid(s, L+1, R) || isValid(s, L, R-1);
            }
        }
        return true;
    }

    bool isValid(string& s, int L, int R) {
        for (; L < R; ++ L, -- R) {
            if (s[L] != s[R]) return false;
        }
        return true;
    }
};

/**
680. Valid Palindrome II
Easy

Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 */
