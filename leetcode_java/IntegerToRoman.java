public class Solution {
    String roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int n;
    
    public String intToRoman(int num) {
        String s = "";
        n = num;

        for (int i = 0, len = val.length; i < len; ++ i) {
            s = eval(s, val[i], roman[i]);
        }
        return s;
    }
    
    private String eval(String s, int v, String roman) {
        while (n >= v) {
            n -= v;
            s += roman;
        }   
        return s;
    }
}

/**
Integer to Roman
Difficulty: Medium

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */
