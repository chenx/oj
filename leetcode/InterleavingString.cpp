//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/8/2012
// @Last modified: 1/8/2012
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// walk through s3, if a matched char is in s1, walk s1, else if a matched char is in s2 then walk s2. 
// This works for small test set, but times out for large test set.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        
        return walk(s1, s2, s3, 0, 0, 0);   
    }
    
    bool walk(string &s1, string &s2, string &s3, int i1, int i2, int i3) {
        if (i1 == s1.length() && i2 == s2.length() && i3 == s3.length()) return true;
        
        if (s3[i3] == s1[i1] && s3[i3] == s2[i2]) {
            return walk(s1, s2, s3, i1 + 1, i2, i3 + 1) || 
                   walk(s1, s2, s3, i1, i2 + 1, i3 + 1);
        }
        else if (s3[i3] == s1[i1]) {
            return walk(s1, s2, s3, i1 + 1, i2, i3 + 1);
        }
        else if (s3[i3] == s2[i2]) {
            return walk(s1, s2, s3, i1, i2 + 1, i3 + 1);
        }
        else {
            return false;
        }
    }
};


// Same as above, but use pointer arithmetic. 
// Still times out for large input.
class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        
        char * p1 = &s1[0];
        char * p2 = &s2[0];
        char * p3 = &s3[0];
        
        return walk(p1, p2, p3);
    }
    
    bool walk(char * p1, char * p2, char * p3) {
        if (*p1 == 0 && *p2 == 0 && *p3 == 0) return true;
        
        if (*p1 == *p3 && *p2 == *p3) {
            return walk(p1 + 1, p2, p3 + 1) || walk(p1, p2 + 1, p3 + 1);
        }
        else if (*p1 == *p3) {
            return walk(p1 + 1, p2, p3 + 1);
        }
        else if (*p2 == *p3) {
            return walk(p1, p2 + 1, p3 + 1);
        }
        else {
            return false;
        }        
    }
};


// DFS: Use a stack to keep track of previous options.
// Works for small test set.
// But still times out for large test set.
class Solution3 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;

        int i1 = 0, i2 = 0, i3 = 0;
        stack<int> t;
        while (1) {
            if (i1 == s1.length() && i2 == s2.length() && i3 == s3.length()) return true;
            
            if (s3[i3] == s1[i1] && s3[i3] == s2[i2]) {
                t.push(i1);
                t.push(i2);
                t.push(i3);
                
                ++ i1;
                ++ i3;
            }
            else if (s3[i3] == s1[i1]) {
                ++ i1;
                ++ i3;
            }
            else if (s3[i3] == s2[i2]) {
                ++ i2;
                ++ i3;
            }
            else {
                if (t.size() > 0) {
                    i3 = t.top(), t.pop();
                    i2 = t.top(), t.pop();
                    i1 = t.top(), t.pop();
                    
                    ++ i2;
                    ++ i3;
                }
                else {
                    return false;
                }
            }
        }
    }
};

// This also works for small test set.
// But still times out for large test set. This is even slower than above methods.
// http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings/
class Solution4 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        
        return walk(s1, s2, s3, 0, 0, 0);   
    }
    
    bool walk(string a, string b, string c, int i, int j, int k) {
        if (i >= a.length() && j >= b.length() && k >= c.length()) {
            return true;
        }
 
        bool ret = false;
        if (i < a.length() && k < c.length() && a[i] == c[k]) {
            ret = walk(a, b, c, i + 1, j, k + 1);
        }
        if (!ret && j < b.length() && k < c.length() && b[j] == c[k]) {
            ret = walk(a, b, c, i, j + 1, k + 1);
        }
 
        return ret;
    }
};


// Same. Back tracking. Passes small test set, times out large test set.
// Note: also can use:
//        stack<const char *> t; // const value, but pointer can change.
//        
//        const char * p1 = s1.c_str(); // or &s1[0];
//        const char * p2 = s2.c_str(); // or &s2[0];
//        const char * p3 = s3.c_str(); // or &s3[0];
//
class Solution5 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        stack<char *> t;
        
        char * p1 = &s1[0]; // or (char*) s1.c_str(); // s1.c_str() type: const char*.
        char * p2 = &s2[0]; // or (char*) s2.c_str();
        char * p3 = &s3[0]; // or (char*) s3.c_str();
        
        while(1) {
            if (*p3 == 0) {
                return (*p1 == 0 && *p2 == 0);
            }

            if (*p3 == *p1) {
                if (*p3 == *p2) {
                    t.push(p1);
                    t.push(p2);
                    t.push(p3);
                }
                ++ p3;
                ++ p1;
            }
            else if (*p3 == *p2) {
                ++ p3;
                ++ p2;
            }
            else {
                if (t.size() > 0) {
                    p3 = t.top(); t.pop();
                    p2 = t.top(); t.pop();
                    p1 = t.top(); t.pop();
                    ++ p3;
                    ++ p2;
                } else {
                    return false;
                }
            }
            
        }
    }  
};

// DP solution. O(|s1||s2|). Passes both small and large test sets!
// http://lifestruthonwisdom.blogspot.com/2012/09/dynamic-programming-practice-problems_28.html
// dp[i,j] = true, if i = j = 0
//           false, if s1[i] != s3[i+j] and s2[j] != s3[i+j]
//           dp[i-1,j], if s1[i] == s3[i+j] and s2[j] != s3[i+j]
//           dp[i,j-1], if s2[j] == s3[i+j] and s1[i] != s3[i+j]
//           dp[i-1,j] || dp[i,j-1], if s1[i] == s2[j] == s3[i+j]
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        if (l1 + l2 != s3.length()) return false;
        else if (l1 + l2 == 0) return true; // all 3 strings are empty.
        
        int dp[l1+1][l2+1];
        for (int i = 0; i < l1+1; ++ i) 
            for (int j = 0; j < l2+1; ++ j)
                dp[i][j] = 0;

        // also can use:
        // bzero(c, (l1+1)*(l2+1) * sizeof(int));      // from strings.h, legacy code
        // memset(c, 0, (l1+1)*(l2+1) * sizeof(int));  // from string.h

        for (int i = 0; i < l1; ++ i) {
            if (s1[i] == s3[i]) dp[i+1][0] = 1;
            else break;
        }

        for (int i = 0; i < l2; ++ i) {
            if (s2[i] == s3[i]) dp[0][i+1] = 1;
            else break;
        }
        
        for (int i = 1; i < l1+1; ++ i) {
            for (int j = 1; j < l2+1; ++ j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i-1+j]) || 
                           (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[l1][l2];
    }    
};


int main() {
    Solution s;
    string s1 = "accbaabaaabbcbaacbababacaababbcbabaababcaabbbbbcacbaa";
    string s2 = "cabaabcbabcbaaaacababccbbccaaabaacbbaaabccacabaaccbbcbcb";
    string s3 = "accbcaaabbaabaaabbcbcbabacbacbababaacaaaaacbabaabbcbccbbabbccaaaaabaabcabbcaabaaabbcbcbbbcacabaaacccbbcbbaacb";
    //string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    //string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    //string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}

/*
Problem:
        
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Comment: 
If s1 and s2 don't have duplicate char, then O(m+n) solution is straight forward,
just scan s3 once, match each char with either s1 or s2.

But if s1 and s2 contain duplicated char, it's more complex.
Use DP, it's O(mn). Use back track, it's worse.
 */
 
 
/*
// This should work too.
// http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings/
// By: Frederic says:
// February 15, 2012 at 10:27 AM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int isInterleaved(char *a, char *b, char *c)
{
    int la = strlen(a);
    int lb = strlen(b);
    int lc = strlen(c);
    if (lc != la + lb)
        return 0;
    // d[j][i] is 1 iff
    // isInterleaved(strndup(a, i),
    //    strndup(b, j), strndup(c, i+j))
    // otherwise 0
    int d[lb+1][la+1];
 
    bzero(d, (lb+1)*(la+1)*sizeof(int));
 
    for (int i = 0; i < la; ++i) {
        if (a[i] == c[i])
            d[0][i+1] = 1;
        else
            break;
    }
 
    for (int i = 0; i < lb; ++i) {
        if (b[i] == c[i])
            d[i+1][0] = 1;
        else
            break;
    }
 
    for (int i = 1; i <= la; ++i)
        for (int j = 1; j <= lb; j++)
            d[j][i] = (d[j-1][i] && c[i+j-1] == b[j-1])
                      || (d[j][i-1] && c[i+j-1] == a[i-1]);
 
    return d[lb][la];
}
 
void checkFunc(char *a, char *b, char *c)
{
    if (isInterleaved(a, b, c))
        printf("%s is interleaved of %s and %s\n", c, a, b);
    else
        printf("%s is not interleaved of %s and %s\n", c, a, b);
}
 
int main(void)
{
    checkFunc("AB", "CD", "ACBD");
    checkFunc("AB", "CD", "ACBG");
    checkFunc("AAB", "AAC", "AACAAB");
    checkFunc("AAAAAAAAAAB", "AAAAAAAAAAC", "AAAAAAAAAAAAAAACAAAAAB");
 
    return 0;
}

 */
