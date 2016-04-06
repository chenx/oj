//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/6/2013
// @Last modified: 1/21/2013
//

// Same as Solution3, but shortened.
class Solution5 {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), len = 0, maxLen = 0, count = 0;
        
        for (int i = 0; i < n; ++ i) 
            getLen(s[i] == '(', len, count, maxLen);

        len = count = 0;
        for (int i = n - 1; i >= 0; -- i) 
            getLen(s[i] == ')', len, count, maxLen);

        return maxLen;
    }
    
    void getLen(bool isOpen, int &len, int &count, int &maxLen) {
        if (isOpen) ++ len, ++ count; 
        else ++ len, -- count; 

        if (count == 0) maxLen = max(maxLen, len);
        else if (count < 0) len = count = 0;
    }
};

// Slighly changed from Solution3. Works too.
class Solution4 {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0, pair = 0, len = 0;

        for (int i = 0; i < s.length(); ++ i) {
            count(maxlen, pair, len, s[i] == '(' ? 1 : -1);
        }
        
        pair = len = 0;
        for (int i = s.length() - 1; i >= 0; -- i) {
            count(maxlen, pair, len, s[i] == ')' ? 1 : -1);
        }
        
        return maxlen;
    }
    
    void count(int &maxlen, int &pair, int &len, int c) {
        pair += c;
        len ++;

        if (pair == 0) {
            maxlen = max(maxlen, len);
        }
        else if (pair < 0) {
            pair = 0;
            len = 0;
        }
    }
};

// Adapted from Solution. Works too.
class Solution3 {
public:
    int longestValidParentheses(string s) {
        int len = 0, len_max = 0, count = 0;
        for (int i = 0 ; i < s.length(); ++ i) {
            checkChar(len, len_max, count, s[i] == '(');
        }
        
        len = 0, count = 0;
        for (int i = s.length() - 1; i >= 0; -- i) {
            checkChar(len, len_max, count, s[i] == ')');
        }
        
        return len_max;
    }

    void checkChar(int &len, int &len_max, int &count, bool cond) {
        if (cond) { 
            ++ count;
            ++ len;
        }
        else {
            -- count;
            ++ len;
        }
        if (count == 0) { // equal # of '(' and ')' found.
            if (len > len_max) len_max = len;
        }
        else if (count < 0) {
            len = 0;
            count = 0;
        }            
    }
};

// http://yewenxing.wordpress.com/2012/03/11/longest-valid-parentheses/
// Idea:
// Scan from head to tail, if '(', increase count; else if ')', decrease count.
// Always increase len. If count is 0, update max length. If count < 0, then
// let len and count both be 0.
// Then repeat the same procedure from tail to head.
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0, len_max = 0, count = 0;
        for (int i = 0 ; i < s.length(); ++ i) {
            if (s[i] == '(') {
                ++ count;
                ++ len;
            }
            else {
                -- count;
                ++ len;
            }
            if (count == 0) {
                if (len > len_max) len_max = len;
            }
            else if (count < 0) {
                len = 0;
                count = 0;
            }
        }
        
        len = 0, count = 0;
        for (int i = s.length() - 1; i >= 0; -- i) {
            if (s[i] == ')') { // Note now it's ')' instead of '('.
                ++ count;
                ++ len;
            }
            else {
                -- count;
                ++ len;
            }
            if (count == 0) {
                if (len > len_max) len_max = len;
            }
            else if (count < 0) {
                len = 0;
                count = 0;
            }            
        }
        
        return len_max;
    }
};


// This does not work.
class Solution2 {
public:
    int longestValidParentheses(string s) {
        stack<char> t;
        int len = 0, prev_len = 0, max_len = 0;
        
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == ')') {
                if (t.size() > 0) {
                  if (t.top() == '(') {
                    t.pop();
                    len += 2;
                    if (t.size() == 0) {
                        len += prev_len;
                        prev_len = len;
                    }
                    if (len > max_len) max_len = len;
                    if (t.size() == 0) {
                        len = 0;
                    }
                  } else {
                      while (t.size() > 0) t.pop();
                      prev_len = 0;
                      len = 0;
                  }
                }
                else {
                    prev_len = 0;
                    len = 0;
                }
            } else {
                if (t.size() > 0 && t.top() == ')') {
                    prev_len = len = 0;
                    while (t.size() > 0) { t.pop(); }
                } 
                t.push(s[i]);    
            }
        }
        
        return max_len;        
    }
};


/*
Problem:

Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

 */
