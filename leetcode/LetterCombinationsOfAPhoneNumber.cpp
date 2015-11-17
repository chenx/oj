//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 1/15/2013
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits == "") {
            v.push_back("");
            return v;
        }
        
        string mapping[] = {"0", "1", "abc", "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string s = "";
        comb(v, digits, s, 0, mapping);
        return v;
    }
    
    void comb(vector<string> &v, string &digits, 
              string s, int pos, string mapping[]) {
        if (pos == digits.length()) {
            v.push_back(s);
            return;
        }
        
        string m = mapping[digits[pos] - '0'];
        for (int i = 0; i < m.size(); i ++) {
            comb(v, digits, s + m[i], pos + 1, mapping);
        }
    }
};


// This also works the same as Solution.
// Note: important to have "0" and "1" for 0 and 1, to keep original digit.
class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        getComb(ans, s, digits, 0);
        
        return ans;
    }
    
    void getComb(vector<string> &ans, string s, string digits, int pos) {
        static char * p[] = {
        "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        }; // 0, 1, 2, ..., 9
        
        if (pos == digits.length()) {
            ans.push_back(s);
            return;
        }
                        
        char * ps = p[ digits[pos] - '0' ];
        int len = strlen(ps);
        for (int i = 0; i < len; ++ i) {
            getComb(ans, s + ps[i], digits, pos + 1);
        }
    }
};


// This works too. 11/16/2015
class Solution3 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") return ans;
        
        string s = "";
        getComb(ans, digits, 0, s);
        return ans;
    }
    
    void getComb(vector<string> &ans, string &digits, int pos, string s) {
        if (pos == digits.length()) {
            ans.push_back(s);
            return;
        }
        
        static string m[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        char c = digits[pos];
        if (c >= '2' && c <= '9') {
            for (int i = 0, len = m[c - '2'].length(); i < len; ++ i) {
                getComb(ans, digits, pos + 1, s + m[c - '2'][i]);
            }
        } 
        else {
            getComb(ans, digits, pos + 1, s + digits[pos]);
        }
    }
};
