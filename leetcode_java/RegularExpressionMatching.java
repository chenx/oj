public class Solution {
    public boolean isMatch(String s, String p) {
        return match(s, 0, p, 0);
    }
    
    boolean match(String s, int is, String p, int ip) {
        if (is == s.length() && ip == p.length()) return true;
        if (ip == p.length()) return false;
        
        if (ip < p.length() - 1 && p.charAt(ip + 1) == '*') {
            if (is < s.length() && (p.charAt(ip) == s.charAt(is) || p.charAt(ip) == '.')) {
                return match(s, is + 1, p, ip) || match(s, is, p, ip + 2);
            }
            else return match(s, is, p, ip + 2);
        }
        else if (is < s.length() && (p.charAt(ip) == s.charAt(is) || p.charAt(ip) == '.')) {
            return match(s, is + 1, p, ip + 1);
        }
        else {
            return false;
        }        
    }
}


/**
Regular Expression Matching
Difficulty: Hard

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
 */
