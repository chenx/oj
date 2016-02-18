//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// This works. Passes small test set, but fails large test set.
class Solution {
public:
    int numDistinct(string S, string T) {
        return ct(&S[0], &T[0]);
    }
    
    int ct(char *s, char *t) {
        if (0 == *t) return 1;
        if (0 == *s) return 0; // end of s, but not end of t.
        
        int n = 0;
        while (*s) {
            if (*s == *t) {
                n += ct(s+1, t+1);
            }
            ++ s;
        }
        
        return n;
    }
};

// This works too. Passes small test set, but fails large test set.
class Solution2 {
public:
    int numDistinct(string S, string T) {
        return ct(&S[0], &T[0]);
    }
    
    int ct(char *s, char *t) {
        if (0 == *t) return 1;
        if (0 == *s) return 0; // end of s, but not end of t.

        if (*s == *t) {
            return ct(s+1, t+1) + ct(s+1, t);
        }
        else {
            return ct(s+1, t);
        }
    }
};

// DP. This works and passes both small and large test sets!
// Be careful of the DP condition!
// DP: i for pos in T, j for pos in S:
// DP[i][j] = DP[i-1][j-1] + DP[i][j-1], if T[i] = S[j]; i.e., S advances by 1, or both advances by 1.
//            DP[i][j-1], otherwise. i.e., S advances by 1.
class Solution3 {
public:
    int numDistinct(string S, string T) {
        if (S[0] == '\0') return 0;
        if (T[0] == '\0') return 1;
        
        int DP[T.length() + 1][S.length() + 1];
        for (int i = 0; i <= T.length(); ++ i) DP[i][0] = 0; // when S = "".
        for (int i = 0; i <= S.length(); ++ i) DP[0][i] = 1; // when T = "".
        
        for (int i = 0; i < T.length(); ++ i) {
            for (int j = 0; j < S.length(); ++ j) {
                if (S[j] == T[i]) {
                    DP[i+1][j+1] = DP[i][j] + DP[i+1][j]; // Note: T same, S += 1 or both +=1.
                }
                else {
                    DP[i+1][j+1] = DP[i+1][j]; // T same, S += 1.
                }
            }
        }
        
        return DP[T.length()][S.length()];
    }
};

// This works too.
class Solution4 {
public:
    int numDistinct(string s, string t) {
        int lens = s.length(), lent = t.length();
        
        vector<vector<int>> dp(lens + 1, vector<int>(lent + 1, 0));
        
        for (int j = 0; j <= lent; ++ j) dp[0][j] = 0;
        for (int i = 0; i <= lens; ++ i) dp[i][0] = 1;

        for (int i = 0; i < lens; ++ i) {
            for (int j = 0; j < lent; ++ j) {
                if (s[i] == t[j]) {
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                }
                else {
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
        
        return dp[lens][lent];
    }
};

/*
Problem:

 Given a string S and a string T, count the number of distinct 
 subsequences of T in S.

A subsequence of a string is a new string which is formed from 
the original string by deleting some (can be none) of the 
characters without disturbing the relative positions of the 
remaining characters. (ie, "ACE" is a subsequence of "ABCDE" 
while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
 */
