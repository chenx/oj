
class Solution9 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> DP(n + 1, false);
        set<string> words(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= n; ++ i) {
            if (words.contains(s.substr(0, i))) {
                DP[i] = true;
                continue;
            }

            for (int j = 1; j < i; ++ j) {
                if (DP[j] && words.contains(s.substr(j, i - j))) {
                    DP[i] = true;
                    break;
                }
            }
        }
        return DP[n];
    }
};

//
// Note that WordBreak, WordBreak_II, PalindromePartitioning, PalindromePartitioning_II are
// actually different aspects of the same problem. Just that one uses a dictionary for valid
// words, one uses the rule of palindrome. 
//
// Solution: most intuitive is DFS, next is DP.
//
// Reference: Palindrome Partitioning.
//
// X.C.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

// Works. 
// Given n = s.length(), m = wordDict.size(), and k as the average length of the words in wordDict,
// Time complexity: O(n⋅n), Space: O(n + m*k).
class Solution8 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> DP(n+1, false);
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= n; ++ i) {
            if (st.contains(s.substr(0, i))) {
                DP[i] = true;
            } else {
                for (int j = 1; j < i; ++ j) {
                    string t = s.substr(j, i-j);
                    if (DP[j] && st.contains(t)) {
                        DP[i] = true;
                        break;
                    }
                }
            }
        }
        return DP[n];
    }
};

// Works. Adapted from Solution5. 2025-09-02
class Solution7 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> DP(1 + n, false);

        unordered_set<string> dict;
        for (auto& word: wordDict) dict.insert(word);

        for (int i = 1; i <= n; ++ i) {
            string t = s.substr(0, i);
            if (dict.contains(t)) {
                DP[i] = true;
                continue;
            }
        
            for (int j = 1; j < i; ++ j) {
                string t = s.substr(j, i - j);
                if (dict.contains(t) && DP[j]) {
                    DP[i] = true;
                    break;
                }
            }
        }
        return DP[n];
    }
};

// Works, but time out for large input.
class Solution6 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string& w : wordDict) dict.insert(w);
        return helper(s, dict);
    }

    bool helper(string& s, unordered_set<string>& dict) {
        if (dict.contains(s)) return true;

        for (int i = 1; i < s.length(); ++ i) {
            string s1 = s.substr(0, i), s2 = s.substr(i);
            if (dict.contains(s1)) {
                if (helper(s2, dict)) return true;
            }
        }
        return false;
    }
};

// Works too. Be careful of boundaries!
// This should be the one easiest to memorize on boundaries.
// From: Amz intv
class Solution5 {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        int n = s.length();
        //if (n == 0) return false; // don't need this, since DP[0] = false below.
        
        vector<bool> DP(n+1, false);
        //DP[0] = true; // this should be false, for empty string.
        for (int i = 1; i <= n; ++ i) {
            string t = s.substr(0, i);
            if (dict.find(t) != dict.end()) {
                DP[i] = true;
                continue;
            }
            
            for (int j = 1; j < i; ++ j) {
                string t = s.substr(j, i - j); // (j, i - j) !!!
                if (dict.find(t) != dict.end() && DP[j]) {
                    DP[i] = true;
                    break;
                }
            }
        }
        
        return DP[n];
    }
};


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
139. Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of 
one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/




