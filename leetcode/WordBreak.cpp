#include <iostream>
#include <string>
#include <set>
using namespace std;

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
