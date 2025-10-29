class Solution {
    public boolean validPalindrome(String s) {
        for (int l = 0, r = s.length() - 1; l < r; ++ l, -- r) {
            if (s.charAt(l) != s.charAt(r)) {
                return check(s, l+1, r) || check(s, l, r-1);
            }
        }
        return true;
    }

    private boolean check(String s, int l, int r) {
        for (; l < r; ++ l, -- r) {
            if (s.charAt(l) != s.charAt(r)) return false;
        }
        return true;
    }
}

/**
680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false
 */
