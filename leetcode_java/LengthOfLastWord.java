public class Solution {
    public int lengthOfLastWord(String s) {
        int p = s.length() - 1;
        
        for (; p >= 0 && s.charAt(p) == ' '; -- p) {}
        if (p < 0) return 0; // all spaces.
        
        // now s[p] is last non-space char.
        int q = p;
        for (; q >= 0 && s.charAt(q) != ' '; -- q) {}
        ++ q; // always increment q, no matter q < 0 or s[q] is space.
        
        return p - q + 1;
    }
}

/**
Length of Last Word
Difficulty: Easy

Given a string s consists of upper/lower-case alphabets and 
empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
 */
