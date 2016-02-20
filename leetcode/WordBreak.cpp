//
// Note that WordBreak, WordBreak_II, PalindromePartitioning, PalindromePartitioning_II are
// actually different aspects of the same problem. Just that one uses a dictionary for valid
// words, one uses the rule of palindrome. 
//
// Solution: most intuitive is DFS, next is DP.
//
// X.C.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;


// Works too. 
class Solution4 {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int lens = s.length();
        if (lens == 0) return false;
        
        vector<bool> can(lens, false);
        
        for (int i = 0; i < lens; ++ i) {
            string t = s.substr(0, i+1);
            if (wordDict.find(t) != wordDict.end()) {
                can[i] = true;
                continue;
            }
            
            for (int j = i; j > 0; -- j) {
                string t = s.substr(j, i-j+1);
                if (wordDict.find(t) != wordDict.end() && can[j-1]) {
                    can[i] = true;
                    break;
                }
            }
        }
        
        return can[lens-1];
    }
};


// This works too. Most short and clean so far. 2/15/2015. X.C.
class Solution3 {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                string u = s.substr(j, i - j);
                if (dp[j] && dict.find(u) != dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
    
// This works too.
// Use 1-D array, instead of 2-D array.
// X. C. 1/25/2015
class Solution2 {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        vector<int> dp(n);
        fill(dp.begin(), dp.end(), 0);
        
        for (int i = 1; i <= n; ++ i) {
            string t = s.substr(0, i);
            if (dict.find(t) != dict.end()) {
                dp[i-1] = 1;
            }
            else {
                for (int j = 1; j < i; ++ j) {
                    string u = s.substr(j, i - j);
                    if (dp[j-1] && dict.find(u) != dict.end()) {
                        dp[i-1] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};

class Solution {
public:
    //bool wordBreak(string s, unordered_set<string> &dict) {

    // works too. modified from wordBreak2, 
    // by using dp[n][n+1] instead of dp[n][n], so length is more intuitive.
    bool wordBreak3(string s, set<string> &dict) {
        if (s == "" || dict.find(s) != dict.end()) return true;
        
        int n = s.length();
        int dp[n][n+1]; // dp[start][length]
        memset(dp, 0, n * (n+1) * sizeof(int));
        
        for (int len = 1; len <= n; ++ len) {
            for (int start = 0; start <= n - len; ++ start) {
                string t = s.substr(start, len);
                if (dict.find(t) != dict.end()) {
                    dp[start][len] = 1;
                }
                else {
                    for (int k = 1; k <= len - 1; ++ k) {
                        if (dp[start][k] && dp[start+k][len - k]) dp[start][len] = 1;    
                    }
                }
            }
        }
       
        return dp[0][n];
    }
    
    // works too. and passes large test.
    bool wordBreak2(string s, set<string> &dict) {
        if (s == "" || dict.find(s) != dict.end()) return true;
        
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, n * n * sizeof(int));
        
        for (int len = 1; len <= n; ++ len) {
            for (int start = 0; start <= n - len; ++ start) {
                string t = s.substr(start, len);
                if (dict.find(t) != dict.end()) {
                    dp[start][len-1] = 1;
                }
                else {
                    for (int k = 1; k <= len - 1; ++ k) {
                        if (dp[start][k-1] && dp[start+k][len - k -1]) dp[start][len-1] = 1;    
                    }
                }
            }
        }
        
        /*
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        
        return dp[0][n-1];
    }
             
    // works, but timeout.
    bool wordBreak(string s, set<string> &dict) {
        //cout << "-----------" << s << endl;
        if (s == "" || dict.find(s) != dict.end()) return true;
        
        for (int i = 1; i < s.length(); ++ i) {
            string t = s.substr(0, i);
            //cout << t << endl;
            if (dict.find(t) != dict.end()) {
                string s2 = s.substr(i);
                if ( wordBreak(s2, dict) ) return true;
            }
        }
        
        return false;
    }
};

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    //string s = "aaaaaaaaaaaaaab";
    string d[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    set<string> dict;
    for (int i = 0; i < 10; ++ i) { dict.insert(d[i]); }
    
    Solution so;
    cout << so.wordBreak3(s, dict) << endl;
    return 0;
}

/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
