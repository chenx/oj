public class Solution {
    public String convertToTitle(int n) {
        String s = "";
        if (n <= 0) return s;
        
        while (n > 0) {
            int v = (n - 1) % 26;       // Note: use n-1
            char c = (char) ('A' + v);  // Note: must cast explicitly.
            s = c + s;
            n = (n - 1) / 26;
        }
        
        return s;
    }
}

/**
Excel Sheet Column Title 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 */
