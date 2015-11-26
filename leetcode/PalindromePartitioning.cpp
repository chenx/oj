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

// This works too.
// Different from Solution2 only in index position.
// X.C. 11/26/2015
class Solution3 {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<vector<string>>> ans(1 + n);
        if (n == 0) return ans[0];
        
        for (int i = 0; i < n; ++ i) {
            // check substring s.substr(0, i+1).
            string t = s.substr(0, i + 1);
            if (isPalindrome(t)) {
                vector<string> v(1);
                v[0] = t;
                ans[i].push_back(v);
            }
            
            for (int j = i; j > 0; -- j) {
                string t = s.substr(j, i - j + 1);
                if (isPalindrome(t)) {
                    vector<vector<string>> v = ans[j - 1]; 
                    for (int k = 0; k < v.size(); ++ k) {
                        v[k].push_back(t);
                        ans[i].push_back(v[k]);
                    }
                }
            }
        }
        
        return ans[n-1];
    }
    
    bool isPalindrome(string t) {
        int L = 0, R = t.size() - 1;
        while (L < R) {
            if (t[L] != t[R]) return false;
            ++ L; -- R;
        }
        return true;
    }
};

// This works too.
// Different from Solution only in index position.
// X.C. 1/25/2015
class Solution2 {
public:
    vector<vector<string> > partition(string s) {
        int n = s.length();
        vector<vector<vector<string> > > ans(n);
        
        for (int i = 1; i <= n; ++ i) {
            string a = s.substr(0, i);
            if (isPalindrome(a)) { 
                vector<string> u;
                u.push_back(a);
                ans[i-1].push_back(u); 
            }
            
            for (int j = 1; j < i; ++ j) {
                string b = s.substr(j, i - j); // check each substring starts at j, ends at i.
                vector<vector<string> > v = ans[j-1];
                if (v.size() > 0 && isPalindrome(b)) {
                    for (int k = 0; k < v.size(); ++ k) {
                        vector<string> u = v[k];
                        u.push_back(b);
                        ans[i-1].push_back(u);
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
