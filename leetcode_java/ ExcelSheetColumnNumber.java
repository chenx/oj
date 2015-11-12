public class Solution {
    public int titleToNumber(String s) {
        int n = 0;
        for (int i = 0, len = s.length(); i < len; ++ i) {
            n = n * 26 + (s.charAt(i) - 'A' + 1);
        }
        return n;
    }
}

/**
Excel Sheet Column Number
Difficulty: Easy

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
 */
