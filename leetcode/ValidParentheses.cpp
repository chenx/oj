//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/1/2013
// @Last modified: 1/1/2013
//

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;        
        
        for (int i = 0, len = s.length(); i < len; ++ i) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    t.push(s[i]);
                    break;
                case ')':
                    if (t.size() > 0 && t.top() == '(') t.pop();
                    else return false;
                    break;
                case ']':
                    if (t.size() > 0 && t.top() == '[') t.pop();
                    else return false;
                    break;
                case '}':
                    if (t.size() > 0 && t.top() == '{') t.pop();
                    else return false;
                    break;
                default:
                    return false;
                    break;
            }
        }
        
        return t.empty();        
    }
};

/*
Problem:
        
Given a string containing just the characters '(', ')', '{', '}', 
'[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" 
are all valid but "(]" and "([)]" are not.
 */
