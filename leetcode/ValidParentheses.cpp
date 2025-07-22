//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/1/2013
// @Last modified: 1/1/2013
//

// Works. Succinct. But slower due to use of hashmap.
class Solution6 {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (char x : s) {
            if (m.find(x) != m.end()) st.push(m[x]);
            else if (!st.empty() && st.top() == x) st.pop();
            else return false;
        }
        return st.empty();
    }
};

// Works. Not as optimal, but works.
class Solution5 {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (char x : s) {
            switch (x) {
                case '{':
                case '(':
                case '[':
                        st.push(m[x]);
                        break;
                case '}':
                case ')':
                case ']':
                        if (st.empty() || st.top() != x) return false;
                        st.pop();
                        break;
            }
        }
        return st.empty();
    }
};

// Works.
class Solution4 {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        unordered_map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        
        stack<char> t;
        
        for (int i = 0; i < s.length(); ++ i) {
            char c = s[i];
            if (m.find(c) != m.end()) t.push(c);
            else if (! t.empty() && m[t.top()] == c) t.pop();
            else return false;
        }
        
        return t.empty();
    }
};

// Works. Best so far!  Totally avoids switch/if-else.
class Solution3 {
public:
    bool isValid(string s) {
        map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        
        stack<char> t;
        for (int i = 0; i < s.length(); ++ i) {
            char c = s[i];
            if (m.find(c) != m.end()) t.push(c);
            else {
                if (! t.empty() && c == m[t.top()]) t.pop();
                else return false;
            }
        }
        
        return t.empty();
    }
};

// Works. Tested.
class Solution2 {
public:
    bool isValid(string s) {
        stack<char> t;
        unordered_map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        
        for (int i = 0; i < s.length(); ++ i) {
            char c = s[i];
            switch (c) {
                case '(': 
                case '{':
                case '[':
                    t.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if (t.empty() || t.top() != m[c]) return false;
                    t.pop();
                    break;
            }
        }
        
        return t.empty();
    }
};

// Works. Fastest.
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
