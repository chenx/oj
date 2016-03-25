//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 1/15/2013
//

// Works.
class Solution5 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") return ans;
        
        string s;
        getComb(ans, s, digits, 0);
        return ans;
    }
    
    void getComb(vector<string> &ans, string s, string digits, int pos) {
        if (pos == digits.length()) {
            ans.push_back(s);
            return;
        }
        
        static vector<string> m {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // this works the same:
        // static string m[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string str = m[digits[pos] - '0'];
        for (int i = 0, len = str.length(); i < len; ++ i) {
            getComb(ans, s + str[i], digits, pos + 1);
        }
    }
};

// Works. Clean. 2/4/2016.
class Solution4 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") return ans;
        getComb(ans, digits, 0, "");
        return ans;
    }
    
    void getComb(vector<string> &ans, string &digits, int pos, string s) {
        if (pos == digits.length()) {
            ans.push_back(s);
            return;
        }
        
        // This handles 0 and 1 consistently without other chars.
        static string m[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string chars = m[digits[pos] - '0'];
        for (int i = 0; i < chars.length(); ++ i) {
            getComb(ans, digits, pos + 1, s + chars[i]);
        }
    }
};

// This works too. But not so good since 0/1 are handled differently. 11/16/2015
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
            string v = m[c - '2'];
            for (int i = 0, len = v.length(); i < len; ++ i) {
                getComb(ans, digits, pos + 1, s + v[i]);
            }
        } 
        else {
            getComb(ans, digits, pos + 1, s + digits[pos]);
        }
    }
};


// This also works the same as Solution.
// Note: important to have "0" and "1" for 0 and 1, to keep original digit.
class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") return ans;
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


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits == "") return v;

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


/**
Letter Combinations of a Phone Number
Difficulty: Medium

Given a digit string, return all possible letter combinations 
that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) 
is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, 
your answer could be in any order you want. 
 */
