//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

#include <string>
#include <iostream>
using namespace std;

/*
 * int to string conversion:
   http://stackoverflow.com/questions/273908/c-integer-stdstring-conversion-simple-function
   Some implementations have a nonstandard itoa() function, and you could 
   look up Boost's lexical_cast, but if you stick to the standard it's 
   pretty much a choice between stringstream and sprintf() (snprintf() 
   if you've got it).
   
   std::string intToString(int i)
    {
        std::stringstream ss;
        std::string s;
        ss << i;
        s = ss.str();
    
        return s;
    }

 */
 
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return string("1");
        string a = "1";
        string b = "";
        string tmp;
        char num[10];
        
        for (int k = 1; k < n; k ++) {
            char c = a[0];
            int ct = 1;
            
            for (int i = 1; i < a.size(); i ++) {
                if (a[i] == c) {
                    ct ++;
                } else {
                    sprintf(num, "%d%c", ct, c);
                    b = b + string(num);
                    
                    c = a[i];
                    ct = 1;
                }
            }
            sprintf(num, "%d%c", ct, c);
            b = b + string(num); // don't forget last one.
            
            a = b;
            b = "";
        }
        
        return a;
    }
};


//
// This works too.
//
class Solution2 {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1) return s;
        
        string t;
        int ct;
        char c;
        for (int i = 2; i <= n; ++ i) {
            ct = 1;
            c = s[0];
            t = "";
            char v[11];
            for (int j = 1; j < s.length(); ++ j) {
                if (s[j] == c) {
                    ++ ct;
                }
                else {
                    sprintf(v, "%d%c", ct, c);
                    t = t + v;
                    ct = 1;
                    c = s[j];
                }
            }
            sprintf(v, "%d%c", ct, c);
            t = t + v;
            
            s = t;
        }
        
        return s;
    }
};


//
// This works too.
//
class Solution3 {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1) return s;
        
        string t;
        int ct;
        char c;
        for (int i = 2; i <= n; ++ i) {
            ct = 1;
            c = s[0];
            t = "";
            char v[11];
            for (int j = 1; j < s.length(); ++ j) {
                if (s[j] == c) {
                    ++ ct;
                }
                else {
                    t = t + getStr(ct, c);
                    ct = 1;
                    c = s[j];
                }
            }
            t = t + getStr(ct, c);
            
            s = t;
        }
        
        return s;
    }
    
    string getStr(int ct, char c) {
        stringstream ss;
        ss << ct;
        return ss.str() + c;
    }
};


// This works too, and seems most clean.
class Solution4 {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1) return s;
        
        for (int i = 2; i <= n; ++ i) {
            string t = "";
            char c = s[0];
            int ct = 1;
            for (int j = 1; j < s.length(); ++ j) {
                if (c == s[j]) { ++ ct; }
                else {
                    t += getStr(ct, c);
                    c = s[j];
                    ct = 1;
                }
            }
            if (ct > 0) { t += getStr(ct, c); }
            s = t;
        }
        
        return s;
    }
    
    string getStr(int ct, char c) {
        stringstream ss;
        ss << ct << c;
        return ss.str();
    }
};

//
// This works too. 
// Note the use of function to_string() to convert int to string.
//
class Solution5 {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1) return s;
        
        for (int i = 2; i <= n; ++ i) {
            string t = "";
            int ct = 1;
            char c = s[0];
            for (int j = 1; j < s.length(); ++ j) {
                if (c == s[j]) { ++ ct; }
                else {
                    t += to_string(ct) + c;
                    ct = 1;
                    c = s[j];
                }
            }
            if (ct > 0) t += to_string(ct) + c;
            
            s = t;
        }
        
        return s;
    }
};

// This also works.
class Solution6 {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string s = "1";
        
        for (int i = 2; i <= n; ++ i) {
            string t = "";
            
            char c = s[0];
            int ct = 1;
            for (int j = 1, lenj = s.length(); j < lenj; ++ j) {
                if (c == s[j]) {
                    ++ ct;
                }
                else {
                    t += to_string(ct);
                    t += c;
                    
                    c = s[j];
                    ct = 1;
                }
            }
            t += to_string(ct);
            t += c;
            
            s = t;
        }
        
        return s;        
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}

/**
Count and Say
Difficulty: Easy

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 
 */
