//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 12/27/2012
//

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> IPs;
        int L = s.length();
        if (L < 4 || L > 12) return IPs;
        
        for (int L1 = 1; L1 <= 3; L1 ++) {
            for (int L2 = 1; L2 <= 3; L2 ++) {
                for (int L3 = 1; L3 <= 3; L3 ++) {
                    int L4 = L - L1 - L2 - L3;
                    if (L4 < 1 || L4 > 3) continue;
                    if (isValidIP(s, L1, L2, L3, L4)) {
                        IPs.push_back(getIP(s, L1, L2, L3, L4));
                    }
                }
            }
        }
        
        return IPs;
    }
    
    bool isValidIP(string &s, int L1, int L2, int L3, int L4) {
        return isValidDigit(s, 0, L1) && 
               isValidDigit(s, L1, L2) && 
               isValidDigit(s, L1 + L2, L3) && 
               isValidDigit(s, L1 + L2 + L3, L4);
    }
    
    // assume: good IP: 1) >= 0 and <= 255, 2) does not start with 0.
    bool isValidDigit(string &s, int left, int len) {
        if (s[left] == '0' && len > 1) return false; // don't forget this!
        
        int n = 0;
        for (int i = 0; i < len; i ++) {
            n = n * 10 + s[left + i] - '0';
        }
        return n <= 255 && n >= 0;
    }
    
    string getIP(string &s, int L1, int L2, int L3, int L4) {
        return s.substr(0, L1) + "." + s.substr(L1, L2) + "." + s.substr(L1+L2, L3) + "." + s.substr(L1+L2+L3, L4);
    }
};

// This works too. But not as clear as Solution above. 11/4/2014
class Solution2 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        
        for (int i = 0; i < 3; ++ i) {
            for (int j = i+1; j <= i+3; ++ j) {
                for (int k = j+1; k <= j+3; ++ k) {
                    if (k+1 >= s.length()) continue;
                    
                    string s1 = s.substr(0, i+1),
                           s2 = s.substr(i+1, j-i),
                           s3 = s.substr(j+1, k-j),
                           s4 = s.substr(k+1, s.length()-1-k);
                    if (valid(s1) && valid(s2) && valid(s3) && valid(s4)) {
                        string ip = s1 + "." + s2 + "." + s3 + "." + s4;
                        if (find(ans.begin(), ans.end(), ip) == ans.end()) {
                            ans.push_back(ip);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    bool valid(string s) {
        if (s.length() > 1 && s[0] == '0') return false;
        
        int v = 0;
        for (int i = 0; i < s.length(); ++ i) {
            v = v * 10 + (s[i] - '0'); 
            if (v > 255) return false;
        }
        return v <= 255;
    }
};


/*
Problem:

Given a string containing only digits, restore it by returning all 
possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
