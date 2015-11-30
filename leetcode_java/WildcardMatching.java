public class Solution {
    public boolean isMatch(String s, String p) {
        int ip0 = 0, is0 = 0, ip = 0, is = 0;
        boolean starFound = false;
        
        while (true) {
            if (is == s.length()) {
                while (ip < p.length() && p.charAt(ip) == '*') ++ ip;
                return ip == p.length();
            }

            if (ip < p.length() && (p.charAt(ip) == '?' || p.charAt(ip) == s.charAt(is))) {
                ++ ip; 
                ++ is;
            }
            else if (ip < p.length() && p.charAt(ip) == '*') {
                ip0 = ip; 
                is0 = is;
                starFound = true;
                ++ ip;
            }
            else {
                if (starFound) {
                    ip = ip0;
                    is = ++ is0;
                    ++ ip;
                }
                else {
                    return false;
                }
            }
        }
    }
}


/**
Wildcard Matching
Difficulty: Hard

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
 */
