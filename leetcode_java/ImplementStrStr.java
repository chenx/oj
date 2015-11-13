public class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.equals("")) return 0;
        if (haystack.equals("")) return -1; // can remove first 2 lines, and it still works.
        
        int len = haystack.length() - needle.length();
        int lenj = needle.length(), i, j;
        
        for (i = 0; i <= len; ++ i) {
            for (j = 0; j < lenj; ++ j) {
                if (haystack.charAt(i + j) != needle.charAt(j)) break;
            }
            if (j == lenj) return i;
        }
        
        return -1;
    }
}

/**
Implement strStr()
Difficulty: Easy

Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack. 
 */
