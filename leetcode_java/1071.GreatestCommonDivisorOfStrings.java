// From: https://leetcode.com/problems/greatest-common-divisor-of-strings/editorial/
// Time complexity: O(m+n)
// Space complexity: O(m+n)
class Solution {
    public int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    
    public String gcdOfStrings(String str1, String str2) {
        // Check if they have non-zero GCD string.
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        
        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.length(), str2.length());
        return str1.substring(0, gcdLength);
    }
}

/**
1071. Greatest Common Divisor of Strings
Easy

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
 */
