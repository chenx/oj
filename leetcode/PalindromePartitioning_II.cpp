//
// http://www.leetcode.com/onlinejudge#
//
// Use DP. DP[s[1..n]] = DP[s[1..n-1]] + s[n] U
//                       DP[s[1..n-2]] + s[n-1..n] U  <- add this if s[n-1..n] is palindrome
//                           ..
//                       DP[s[1]] + s[2..n] <- add this if s[2..n] is palindrome
//
// @Author: Xin Chen
// @Created on: 3/2/2013
// @Last modified: 3/2/2013
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Works. Slightly modified from Solution6.
class Solution6_2 {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> DP(n+1);
        for (int i = 0; i <= n; ++ i) DP[i] = i - 1;
        
        for (int i = 1; i <= n; ++ i) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; ++ j)
                DP[i+j+1] = min(DP[i+j+1], 1 + DP[i-j]);
                
            for (int j = 0; i-j-1 >= 0 && i+j < n && s[i-j-1] == s[i+j]; ++ j)
                DP[i+j+1] = min(DP[i+j+1], 1 + DP[i-j-1]);
        }
        
        return DP[n];
    }
};

// This works. 
// The Manancher-like solution scan the array from left to right (for i loop) 
// and only check those sub-strings centered at s[i]; once a non-palindrome 
// string is found, it will stop and move to i+1. Same as the DP solution, 
// minCUTS[i] is used to save the minimum cuts for s[0:i-1]. For each i, we 
// do two for loops (for j loop) to check if the substrings s[i-j .. i+j] 
// (odd-length substring) and s[i-j-1.. i+j] (even-length substring) are palindrome.
// By increasing j from 0, we can find all the palindrome sub-strings centered 
// at i and update minCUTS accordingly. Once we meet one non-palindrome sub-string, 
// we stop for-j loop since we know there no further palindrome substring centered 
// at i. This helps us avoid unnecessary palindrome substring checks, as we did 
// in the DP algorithm. Therefore, this version is faster. 
// From: https://leetcode.com/discuss/47140/two-versions-given-one-28ms-one-manancher-like-algorithm-10
class Solution6 {
public:
    int minCut(string s) {
        const int N = s.size();
        if(N<=1) return 0;

        int i, j, minCUTS[N+1];
        for(i=0; i<=N; ++i) minCUTS[i] = i-1;

        for(i=1;i<N;i++)
        {
            for(j=0;(i-j)>=0 && (i+j)<N && s[i-j]== s[i+j]; ++j) // odd-length substrings 
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j]);

            for(j=0;(i-j-1)>=0 && (i+j)<N && s[i-j-1]== s[i+j]; ++j) // even-length substrings
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j-1]);
        }
        return minCUTS[N];
    }
}
    
// Should work. But times out for large input.
// Slightly modified from Solution4. Most clean in this approach.
class Solution5 {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> DP(n+1, -1);
        
        for (int i = 1; i <= n; ++ i) {
            string t = s.substr(0, i);
            if (isPalindrome(t)) {
                DP[i] = 0;
                continue;
            }
            
            for (int j = 1; j < i; ++ j) {
                string t = s.substr(j, i - j);
                if (isPalindrome(t)) {
                    if (DP[j] != -1 && (DP[i] == -1 || DP[i] > 1 + DP[j])) {
                        DP[i] = 1 + DP[j];
                        if (DP[i] == 1) break;
                    }
                }
            }
        }
        
        return DP[n];
    }
    
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        while (L < R) {
            if (s[L] != s[R]) return false;
            ++ L, -- R;
        }
        return true;
    }
};

// Should work. Although time out for large input.
// Most clean version so far. 2/15/2015. XC.
class Solution4 {
public:
    int minCut(string s) {
        int n = s.length();
        int ans[1 + n];

        for (int i = 1; i <= n; ++ i) {
            string w = s.substr(0, i);
            if (isPalindrome( w )) { 
                ans[i] = 0;
                continue;
            }
            
            ans[i] = i - 1; // max cuts for a string of length i.
            for (int j = 1; j < i; ++ j) {
                string w = s.substr(j, i - j); // check each substring starts at j, ends at i.
                if (isPalindrome( w ) && ans[i] > 1 + ans[j]) {
                    ans[i] = 1 + ans[j];
                    if (ans[i] == 1) break;
                }
            }
        }
        
        return ans[n];
    }
    
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        while (L < R) {
            if (s[L] != s[R]) return false;
            ++ L, -- R;
        }
        return true;
    }
};

// This should work, but Timeout for large input at this time.
// 1/25/2015
class Solution3 {
public:
    int minCut(string s) {
        int n = s.length();
        int ans[n];
        for (int i = 0; i < n; ++ i) ans[i] = i;

        for (int i = 1; i <= n; ++ i) {
            string a = s.substr(0, i);
            if (isPalindrome(a)) { 
                ans[i-1] = 0;
            }
            else {
                for (int j = 1; j < i; ++ j) {
                //for (int j = i-1; j >= 1; -- j) {
                    if (1 + ans[j-1] >= ans[i-1]) continue; // cut branch
                    
                    string b = s.substr(j, i - j); // check each substring starts at j, ends at i.
                    if (isPalindrome(b)) {
                        if (ans[i-1] > 1 + ans[j-1]) {
                            ans[i-1] = 1 + ans[j-1];
                            if (ans[i-1] == 1) break;
                        }
                    }
                }                            
            }
        }
        
        return ans[n-1];
    }
    
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        while (L < R) {
            if (s[L] != s[R]) return false;
            ++ L, -- R;
        }
        return true;
    }
};

//
// This works.
//
class Solution2 {
public:
    int minCut(string s) {
        int len = s.length();
        vector<int> ans(len);
                
        ans[0] = 0;
        
        for (int i = 1; i < len; ++ i) {        
            if (isPalindrome(s.substr(0, i+1))) {
                ans[i] = 0;
                continue;
            }
            
            ans[i] = i; // when each letter is a piece.
            /// Use this also works, but times out of the last test case of the large test set.
            /// result is correct though. Ant it is not really that long.
            /// for (int j = 1; j <= i; ++ j) { 
            for (int j = i; j >= 1; -- j) {
                if (1 + ans[j-1] >= ans[i]) continue; // cut branch
                
                string t = s.substr(j, i-j+1); // s[j..i]
                if (isPalindrome(t)) {
                    if (1 + ans[j-1] < ans[i]) {
                        ans[i] = 1 + ans[j-1];
                        if (ans[i] == 1) break; // cut branch. not really needed.
                    }
                }
            }
        }
        
        return ans[len - 1];
    }
        
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        int L = 0, R = s.length() - 1;
        while (L <= R) {
            if (s[L] != s[R]) return false;
            ++ L, -- R;
        }
        return true;
    }
};

//
// This works but causes Memory Limit Exceeded error.
//
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ans = partition(s);
        if (ans.size() == 0) return 0;
        int len = ans[0].size();
        for (int i = 1; i < ans.size(); ++ i) {
            if (len > ans[i].size()) len = ans[i].size();
        }
        return len - 1;
    }
    
    vector<vector<string> > partition(string s) {
        int len = s.length();
        vector<vector<vector<string> > > ans(len);
                
        vector<string> v;
        v.push_back(s.substr(0,1)); // s[0]
        ans[0].push_back(v);
        
        for (int i = 1; i < len; ++ i) {
            string t = s.substr(0, i+1); // entire s[0..i]
            if (isPalindrome(t)) {
                vector<string> u;
                u.push_back(t);
                ans[i].push_back(u);
            }
            
            for (int j = 1; j <= i; ++ j) {
                t = s.substr(j, i-j+1); // s[j..i]
                if (isPalindrome(t)) {
                    vector<vector<string> > w = ans[j-1];
                    for (int k = 0; k < w.size(); ++ k) {
                        vector<string> wk = w[k];
                        wk.push_back(t);
                        ans[i].push_back(wk);
                    }
                }
            }
        }
        
        return ans[len - 1];
    }
        
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        int L = 0, R = s.length() - 1;
        while (L <= R) {
            if (s[L] != s[R]) return false;
            ++ L, -- R;
        }
        return true;
    }
};

int main() {
    Solution s;
    string t = "a";
    cout << s.minCut(t);
    return 0;
}

/*
Problem:

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 

Large test set:

"a"	0	0	
 
"ab"	0	1	
 
"bb"	0	0	
 
"cdd"	0	1	
 
"dde"	0	1	
 
"efe"	0	0	
 
"fff"	0	0	
 
"abbab"	0	1	
 
"leet"	0	2	
 
"coder"	0	4	
 
"abcccb"	0	1	
 
"cabababcbc"	0	3	
 
"cbbbcc"	0	1	
 
"ccaacabacb"	0	3	
 
"racecar"	0	0	
 
"danaranad"	0	0	
 
"ababbbabbaba"	0	3	
 
"amanaplanacanalpanama"	0	0	
 
"seeslaveidemonstrateyetartsnomedievalsees"	0	0	
 
"eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj"	0	42	
 
"kwtbjmsjvbrwriqwxadwnufplszhqccayvdhhvscxjaqsrmrrqngmuvxnugdzjfxeihogzsdjtvdmkudckjoggltcuybddbjoizu"	0	89	
 
"ltsqjodzeriqdtyewsrpfscozbyrpidadvsmlylqrviuqiynbscgmhulkvdzdicgdwvquigoepiwxjlydogpxdahyfhdnljshgjeprsvgctgnfgqtnfsqizonirdtcvblehcwbzedsmrxtjsipkyxk"	0	143	
 
"ababababababababababababcbabababababababababababa"	0	0	
 
"fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"	0	75	
 
"apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp"	0	452	
 
"adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece"	0	273	
 
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"	0	1	
  
 */
