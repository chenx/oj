//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/19/2012
// @Last modified: 1/15/2013
//

// Works too. Tested. Most clean.
class Solution3 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, 0, 0);
        return ans;
    }
    
    void helper(vector<string> &ans, string s, int n, int L, int R) {
        if (L == n && R == n) {
            ans.push_back(s);
            return;
        }
        
        if (L > R) helper(ans, s + ")", n, L, R + 1);
        if (L < n) helper(ans, s + "(", n, L + 1, R);
    }
};

// This works too.
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        
        generate(ans, s, 0, 0, n);
        
        return ans;
    }
    
    void generate(vector<string> &ans, string s, int left, int right, int n) {
        if (left == n && right == n) {
            ans.push_back(s);
            return;
        }
        
        if (left > right) {
            generate(ans, s + ")", left, right + 1, n);
        }
        if (left < n) {
            generate(ans, s + "(", left + 1, right, n);
        }
    }
};

/*
   Notes:
   1) stack s is passed by value, i.e., copied. Can't use just 1.
   2) output is: x = s.top() + x, can't be x = x + s.top().
   3) possible combinations: C(2n, n)/(n+1).
      http://en.wikipedia.org/wiki/Catalan_number
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        stack<string> s;
        g(v, s, 0, 0, n);
        return v;
    }
    
    void g(vector<string> &v, stack<string> s, 
           int left, int right, int n) {
        if (left == n && right == n) {
            string x = "";
            while (s.size() > 0) {
                x = s.top() + x; // note: can't be x + s.top().
                s.pop();
            }
            v.push_back(x);
            return;
        }
        
        if (left > right) {
            s.push(")");
            g(v, s, left, right + 1, n);
            s.pop();
        }
        
        if (left < n) {
            s.push("(");
            g(v, s, left + 1, right, n);
            s.pop();
        }
    }
};


/**
Generate Parentheses
Difficulty: Medium

Given n pairs of parentheses, write a function to generate 
all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
 */
