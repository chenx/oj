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

class Solution {
public:
    vector<vector<string>> partition(string s) {
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

/*
Problem:

 Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]


 */