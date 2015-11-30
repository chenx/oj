public class Solution {
    public int romanToInt(String s) {
        int cur, prev = 0, sum = 0;
        for (int i = 0, len = s.length(); i < len; ++ i) {
            cur = getV(s.charAt(i));
            sum += (cur > prev) ? - prev : prev;
            prev = cur;
        }
        sum += prev;
        
        return sum;
    }
    
    private int getV(char c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else if (c == 'M') return 1000;        
        return 0;
    }    
}

/**
Roman to Integer
Difficulty: Easy

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */
