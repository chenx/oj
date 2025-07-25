//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/19/2012
// @Last modified: 12/19/2012
//

// This works. Better than Solution5.
class Solution6 {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        while (n >= 0 && s[n] == ' ') -- n;

        int m = n;
        while (m >= 0 && s[m] != ' ') -- m;

        return n - m;
    }
};

// Works. The best!
class Solution5 {
public:
    int lengthOfLastWord(string s) {
        int q = s.length() - 1;
        while (q >= 0 && isspace(s[q])) -- q;
        
        if (q < 0) return 0; // all space.
        
        int p = q - 1;
        while (p >= 0 && ! isspace(s[p])) -- p;
        
        return q - p;
    }
};


// This works too.
// Modified from Java version. May be the best, as no pointer is used.
class Solution4 {
public:
    int lengthOfLastWord(string s) {
        int p = s.length() - 1;
        
        for (; p >= 0 && s[p] == ' '; -- p) {}
        if (p < 0) return 0; // all spaces.
        
        // now s[p] is last non-space char.
        int q = p;
        for (; q >= 0 && s[q] != ' '; -- q) {}
        ++ q; // always increment q, no matter q < 0 or s[q] is space.
        
        return p - q + 1;        
    }
};


//
// This works too, and is shorter!
//
class Solution3 {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL || *s == '\0') return 0;
        
        const char * head = s;
        
        while (*s) ++ s;
        -- s;
        
        while (*s == ' ') -- s;
        const char * end = s; // end of last word.
        while (*s != ' ' && s >= head) -- s; // go to start of last word.
        
        return end - s;
    }
};


//
// This works too, and seems more clear.
//
class Solution2 {
public:
    int lengthOfLastWord(const char *s) {
        const char * end = s;
        
        while (*end == ' ') ++ end;
        
        if (! *end) return 0; // only blank space.
                
        while (*end) ++ end; // move end to end of string.
        
        -- end; // back off.
        
        while (*end == ' ') -- end; // end points to end of last word.
        
        const char * start = end;
        
        while (*start != ' ' && start != s) -- start; // start != s is important!!
        
        if (*start == ' ') ++ start; // back off if space.
        
        return end - start + 1;
    }
};


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) return 0;
        
        char * p = (char *) s, * q;

        for (; *p == ' ' ; ++ p) {} // skip start spaces.
        if (*p == 0) return 0;
        
        q = p; // q is first non-space char.
        for (++ p; *p; ++ p) {
            if (*(p - 1) == ' ' && *p != ' ') q = p;
        }
        -- p; // p at the end.
        
        for(; *p == ' '; -- p) ; // skip end spaces.
        
        return p - q + 1;
    }
};


/**
Length of Last Word
Difficulty: Easy

Given a string s consists of upper/lower-case alphabets and empty space 
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
 */
