public class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        if (n == 0) return "";
        
        String s = strs[0];
        int mlen = s.length();
        for (int i = 1; i < n; ++ i) {
            mlen = getMaxLen(s, strs[i], Math.min(mlen, strs[i].length()));
        }
        
        return s.substring(0, mlen);
    }
    
    int getMaxLen(String s, String t, int mlen) {
        for (int i = 0; i < mlen; ++ i) {
            if (s.charAt(i) != t.charAt(i)) return i;
        }
        return mlen;
    }
}

/**
Longest Common Prefix
Difficulty: Easy

Write a function to find the longest common prefix string amongst an array of strings. 
 */
