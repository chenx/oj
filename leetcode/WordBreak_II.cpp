#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

// Works. Slightly different from Solution4, in index.
class Solution5 {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int lens = s.length();
        if (lens == 0 || ! wordBreakOK(s, wordDict)) return vector<string>();
        
        vector<vector<string>> words(lens);
        
        for (int i = 0; i < lens; ++ i) {
            string t = s.substr(0, i+1);
            if (wordDict.find(t) != wordDict.end()) {
                words[i].push_back(t);
            }
            
            for (int j = i; j > 0; -- j) {
                string t = s.substr(j, i-j+1);
                if (wordDict.find(t) != wordDict.end()) {
                    for (int k = 0; k < words[j-1].size(); ++ k)
                        words[i].push_back(words[j-1][k] + " " + t);
                }
            }
        }
        
        return words[lens-1];
    }
    
    bool wordBreakOK(string s, unordered_set<string>& wordDict) {
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


// This works. Most clean so far. 2/15/2015. X.C.
// Different from Solution 3, by adding a dummary ans[0].
class Solution4 {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Add this to pass large test. Quite artificial. Can remove this.
        if (! wordBreakOK(s, dict)) return vector<string>(); 
        
        int n = s.length();
        vector<vector<string> > ans(n+1);
        ans[0].push_back("");

        for (int i = 1; i <= n; ++ i) {
            string t = s.substr(0, i);
            if (dict.find(t) != dict.end()) {
                ans[i].push_back(t);
            }
            
            for (int j = 1; j < i; ++ j) {
                vector<string> &v = ans[j];
                string u = s.substr(j, i - j); // check substrings start at j, ends at i.
                if (v.size() > 0 && dict.find(u) != dict.end()) {
                    for (int k = 0; k < v.size(); ++ k) {
                        ans[i].push_back(v[k] + " " + u);
                    }
                }
            }
        }
        
        return ans[n];        
    }        
    
    bool wordBreakOK(string s, unordered_set<string> &dict) {
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

// This should work.
// Although didn't pass large test cases, reports "Memory Limit Exceeded".
// Conceptually this is easier to understand than previous solutions.
// X.C. 1/25/2015
class Solution3 {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        vector<vector<string> > ans(n);

        for (int i = 1; i <= n; ++ i) {
            string t = s.substr(0, i);
            if (dict.find(t) != dict.end()) {
                ans[i-1].push_back(t);
            }
            
            for (int j = 1; j < i; ++ j) {
                vector<string> &v = ans[j-1];
                string u = s.substr(j, i - j); // check substrings start at j, ends at i.
                if (v.size() > 0 && dict.find(u) != dict.end()) {
                    for (int k = 0; k < v.size(); ++ k) {
                        ans[i-1].push_back(v[k] + " " + u);
                    }
                }
            }
        }
        
        return ans[n-1];        
    }        
};

// This works, and passes large input.
// This saves time by using wordBreak_ok() to rule out infeasible solutions.
class Solution2 {
public:
    vector<string> wordBreak(string s, set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (! wordBreak_ok(s, dict)) {
            vector<string> ans;
            return ans;
        }
        
        int n = s.length();
        vector<string> dp[n][n+1];
        
        for (int len = 1; len <= n; ++ len) {
            for (int start = 0; start <= n - len; ++ start) {
                string t = s.substr(start, len);
                if (dict.find(t) != dict.end()) {
                    //dp[start][len] = 1;
                    dp[start][len].push_back(t);
                }
                
                // This now is different from wordBreak_ok():
                // we need all cases, so continue with the for loop.
                for (int k = 1; k <= len - 1; ++ k) {
                    if (dp[start][k].size() > 0 && dp[start + k][len - k].size() > 0) {
                        //dp[start][len] = 1;
                        for (int x = 0; x < dp[start][k].size(); ++ x) {
                            for (int y = 0; y < dp[start + k][len - k].size(); ++ y) {
                                string w = dp[start][k][x] + " " + dp[start + k][len - k][y];
                                if (find(dp[start][len].begin(), dp[start][len].end(), w) == dp[start][len].end()) 
                                {
                                    dp[start][len].push_back(w);
                                }
                            }
                        }
                    } // end if
                } // end for
                
            }
        }
       
        return dp[0][n];
        
    }
    
    bool wordBreak_ok(string s, set<string> &dict) {
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
};


class Solution {
public:
    // This works. But time out for large input.
    vector<string> wordBreak(string s, set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = s.length();
        vector<string> dp[n][n+1];
        
        /*
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n + 1; ++ j) {
                cout << dp[i][j].size() << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        
        for (int len = 1; len <= n; ++ len) {
            for (int start = 0; start <= n - len; ++ start) {
                string t = s.substr(start, len);
                //cout << "-------" << t << endl;
                
                if (dict.find(t) != dict.end()) {
                    //dp[start][len] = 1;
                    dp[start][len].push_back(t);
                }

                for (int k = 1; k <= len - 1; ++ k) {
                    if (dp[start][k].size() > 0 && dp[start + k][len - k].size() > 0) {
                        //dp[start][len] = 1;
                        for (int x = 0; x < dp[start][k].size(); ++ x) {
                            for (int y = 0; y < dp[start+k][len - k].size(); ++ y) {
                                string w = dp[start][k][x] + " " + dp[start+k][len - k][y];
                                //dp[start][len].push_back(w);
                                if (find(dp[start][len].begin(), dp[start][len].end(), w) == dp[start][len].end()) 
                                {
                                    dp[start][len].push_back(w);
                                }                                    
                            } // end for
                        } // end for
                    } // end if
                } // end for
            }
        }
       
        return dp[0][n];        
    }
    
};

void dumpVec(vector<string> ans) {
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++ i) {
        cout << ans[i] << endl;
    }
}

void test1() {
    cout << "test1" << endl;
    string s = "aaaaaaa";
    string d[] = {"a","aa","aaaa"};
    set<string> dict;
    for (int i = 0; i < 3; ++ i) { dict.insert(d[i]); }
    
    Solution so;
    vector<string> ans = so.wordBreak(s, dict);
    dumpVec(ans);
}

void test2() {
    cout << "test2" << endl;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string d[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    set<string> dict;
    for (int i = 0; i < 10; ++ i) { dict.insert(d[i]); }
    
    Solution2 so;
    vector<string> ans = so.wordBreak(s, dict);
    dumpVec(ans);
}

int main() {
    test1();
    test2();
    return 0;
}

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where 
each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 
*/
