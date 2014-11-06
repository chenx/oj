//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/20/2013
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This works too! DP. Should be easier to understand than Solution2.
class Solution3 {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        
        vector<int> ways(len+1); // or: int ways[len+1];
        ways[len] = 1; // only reachable by s[i] where i = len-2.
        ways[len-1] = (s[len-1] == '0') ? 0 : 1;
        
        for (int i = len-2; i >= 0; -- i) {
            if (s[i] == '0') ways[i] = 0;
            else if (s[i] == '1' || 
                     (s[i] == '2' && s[i+1] - '0' <= 6)) {
                ways[i] = ways[i+1] + ways[i+2];
            }
            else { // s[i] > 2 or s[i+1] > 6
                ways[i] = ways[i+1];
            }
        }
        
        return ways[0];
    }
};


// This works and passes both small and large test sets!
// Using DP:
// ways[i] = ways[i+1] + ways[i+2], if s[i] = 1 or s[i] = 2 and s[i+1] <= 6; 
//           0, if s[i] == 0;
//           ways[i+1], otherwise.
// From: http://blog.unieagle.net/2012/09/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Adecode-ways%EF%BC%8C%E4%B8%80%E7%BB%B4%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/
class Solution2 {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        vector<int> ways(s.length() + 1, 1); // +1 to avoid checkcing boundary below.
        
        for (int i = s.length() - 1; i >= 0; -- i) {
            if (s[i] == '0') ways[i] = 0;
            else ways[i] = ways[i+1];
            
            if (i < s.length() - 1 && (
                s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')
                )) {
                ways[i] += ways[i+2];
            }
        }
        
        return ways[0];
    }
};


// This passes small test set, but times out for large test set.
class Solution1 {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        return countWays(s, 0);
    }
    
    int countWays(string &s, int i) {
        if (i == s.length()) return 1;
        if (i == s.length() - 1) return (s[i] == '0') ? 0 : 1;
        
        if ((s[i] == '1' || s[i] == '2') && s[i+1] == '0') { // This branch can be removed, due to branch 2 and 3 below.
            return countWays(s, i + 2);
        }
        else if ( s[i] == '1' || 
            (s[i] == '2' && (s[i+1] - '0' <= 6)) ) {
            return countWays(s, i+1) + countWays(s, i+2);
        }
        else if (s[i] == '0') {
            return 0;
        }
        else {
            return countWays(s, i + 1);
        }
    }
};

// Optimized from Solution. Still times out for large test set.
class Solution2 {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        return countWays(&s[0]);
    }
    
    int countWays(char *p) {
        if (*p == 0) return 1;
        if (*(p+1) == 0) return (*p == '0') ? 0 : 1;
        
        int v = *p - '0', v1 = *(p+1) - '0';
        if ((v == 1 || v == 2) && v1 == 0) {
            return countWays(p+2);
        }
        else if ( v == 1 || (v == 2 && v1 <= 6) ) {
            return countWays(p+1) + countWays(p+2);
        }
        else if (v == 0) {
            return 0;
        }
        else {
            return countWays(p+1);
        }
    }
};

int main() {
    Solution s;
    string str = "1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565";
    cout << s.numDecodings(str);
    return 0;
}
