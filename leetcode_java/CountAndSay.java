public class Solution {
    public String countAndSay(int n) {
        if (n <= 0) return "";
        String s = "1";
        
        for (int i = 2; i <= n; ++ i) {
            String t = "";
            
            char c = s.charAt(0);
            int ct = 1;
            for (int j = 1, lenj = s.length(); j < lenj; ++ j) {
                if (c == s.charAt(j)) {
                    ++ ct;
                }
                else {
                    t += ct 
                    t += c;
                    
                    c = s.charAt(j);
                    ct = 1;
                }
            }
            t += ct;
            t += c;
            
            s = t;
        }
        
        return s;
    }
}

/**
Count and Say
Difficulty: Easy

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 
 */
