public class Solution {
    public int numDecodings(String s) {
        int len = s.length();
        if (len == 0) return 0;
        
        int[] ways = new int[len + 1];
        ways[len] = 1;
        
        ways[len - 1] = s.charAt(len - 1) == '0' ? 0 : 1;

        char c, c2;        
        for (int i = len - 2; i >= 0; -- i) {
            c = s.charAt(i);
            c2 = s.charAt(i + 1);
            if (c == '0') ways[i] = 0;
            else if (c == '1' || (c == '2' && c2 <= '6')) ways[i] = ways[i+1] + ways[i+2];
            else ways[i] = ways[i+1];
        }
        
        return ways[0];
    }
}

/**
Decode Ways
Difficulty: Medium

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
 */
