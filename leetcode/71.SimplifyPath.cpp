//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/25/2012
// @Last modified: 12/25/2012
//

class Solution6 {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string out;
        vector<string> tokens;
        while (getline(ss, out, '/')) {
            if (out == "" || out == ".") {
                // do nothing
            } else if (out == "..") {
                if (! tokens.empty()) tokens.pop_back();
            } else {
                tokens.push_back(out);
            }
        }

        string result = "/";
        for (string token : tokens) {
            if (result != "/") result += "/";
            result += token;
        }
        return result;
    }
};


// Works. Use vector instead of stack for storing directory strings.
class Solution5 {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;
        for (char c : path) {
            if (c == '/') process(st, cur);
            else cur += c;
        }
        process(st, cur);

        string ans = "/";
        for (auto& s : st) {
            if (ans != "/") ans += "/";
            ans += s;
        }
        return ans;
    }

    void process(vector<string>& st, string& cur) {
        if (cur.empty() || cur == ".") {
            // do nothing.
        } else if (cur == "..") {
            if (!st.empty()) st.pop_back();
        } else {
            st.push_back(cur);  // add new directory.
        }
        cur = "";
    }
};

// Works. Best so far.
class Solution4 {
public:
    string simplifyPath(string path) {
        stack<string> s;

        string cur;
        for (int i = 0; i < path.length(); i ++) {
            if (path[i] == '/') handleToken(s, cur);
            else cur += path[i];
        }
        handleToken(s, cur);

        // output
        string ans = "";
        for (; !s.empty(); s.pop()) {
            ans = (ans == "") ? s.top() : (s.top() + "/" + ans);
        }
        ans = "/" + ans;
        return ans;
    }

    void handleToken(stack<string>& s, string& cur) {
        if (cur.empty() || cur == "/") {
            // do nothing
        } else if (cur == ".") {
            // do nothing
        } else if (cur == "..") {
            if (!s.empty()) s.pop();
        } else {
            s.push(cur);
        }
        cur = "";
    }
};

class Solution {
public:
    // use a stack to hold all dir names. Pop when ".." is found, Ignore "/" and ".".
    string simplifyPath(string path) {
        stack<string> dirs;
        string d = "";
        
        for (int i = 0; i < path.length(); i ++) {
            if (path[i] == '/') {
                if (d != "" && d != ".") dirs.push(d); // don't forget d != ""
                d = "";
            } 
            else if (path[i] == '.') {
                if (d == ".") {
                    if (dirs.size() > 0) dirs.pop(); // w/o "if (dirs.size() > 0)", may throw exception.
                    d = "";
                }
                else { d = "."; } // don't forget else { d = "."; }
            }
            else {
                d += path[i]; 
            }
        }
        if (d != "" && d != ".") dirs.push(d); // don't forget d != ""
        
        d = "";
        while (dirs.size() > 0) {
            if (d == "") d = dirs.top();
            else d = dirs.top() + "/" + d;
            dirs.pop();
        }
        d = "/" + d;
        
        return d;
    }
};


//
// This works too. This is better than Solution above:
// 1) the logic is more clear.
// 2) this allows 3 or more dots: "...". This is valid dir/file name. 
//
// Note: if don't allow 3 or more dots, can do this in Solution3.
//
class Solution2 {
public:
    string simplifyPath(string path) {
        int n = path.length();
        if (n == 0) return "";
        
        stack<string> s;
        string d;
        
        for (int i = 0; i < n; ++ i) {
            if (path[i] == '/') process(s, d);
            else d += path[i];
        }
        process(s, d);
        
        d = "";
        while (! s.empty()) {
            if (d == "") d = s.top();
            else d = s.top() + "/" + d;
            s.pop();
        }
        d = "/" + d;
        
        return d;
    }
    
    inline void process(stack<string> &s, string &d) {
        if (d == ".") {
            // do nothing.
        }
        else if (d == "..") {
            if (! s.empty()) s.pop();
        }
        else if (d != "") {
            s.push(d);
        }
        d = "";
    }
};


//
// This shows how to not allow 3 or more dots.
//
class Solution3 {
public:
    string simplifyPath(string path) {
        int n = path.length();
        if (n == 0) return "";
        
        stack<string> s;
        string d;
        
        int dots = 0;
        for (int i = 0; i < n; ++ i) {
            if (path[i] == '/') process(s, d);
            else {
                dots = (path[i] == '.') ? (dots + 1) : 0;
                if (dots == 3) { 
                    cout << "3 dots detected at position " << i << endl;
                    break;
                }
                d += path[i];
            }
        }
        process(s, d);
        
        d = "";
        while (! s.empty()) {
            if (d == "") d = s.top();
            else d = s.top() + "/" + d;
            s.pop();
        }
        d = "/" + d;
        
        return d;
    }
    
    inline void process(stack<string> &s, string &d) {
        if (d == ".") {
            // do nothing.
        }
        else if (d == "..") {
            if (! s.empty()) s.pop();
        }
        else if (d != "") {
            s.push(d);
        }
        d = "";
    }
};


/*
Problem:

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
 */


