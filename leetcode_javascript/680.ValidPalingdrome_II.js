/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    const isPalindrome = (s, left, right) => {
        for (; left < right; ++ left, -- right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
        }
        return true;
    }

    for (let left = 0, right = s.length - 1; left < right; ++ left, -- right) {
        if (s.charAt(left) != s.charAt(right)) {
            return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
        }
    }
    return true;
};


/**
680. Valid Palindrome II
Easy

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
