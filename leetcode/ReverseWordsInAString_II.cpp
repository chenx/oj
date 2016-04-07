// Should work. Modified from Solution3, on the function reverse().
class Solution4 {
public:
    void reverseWords(string &s) {
        s = removeSpace(s);

        rev(s, 0, s.length() - 1);
        
        for (int i = 0, j = 0; j <= s.length(); ++ j) {
            if (j == s.length() || isspace(s[j])) {
                rev(s, i, j - 1);
                i = j + 1;
            }
        }
    }
    
    void rev(string &s, int p, int q) {
        while (p < q) 
            swap(s[p ++], s[q --]);
    }
};

// Should work. Not tested. Modified from Solution2.
class Solution3 {
public:
    // Works too. Modified from reverseWords2.
    void reverseWords3(string &s) {
        s = removeSpace(s);

        reverse(s.begin(), s.end());
        for (int i = 0, j = 0; j <= s.length(); ++ j) {
            while (j < s.length() && ! isspace(s[j])) ++ j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
};
    
// Should work. Not tested. From CCH.
class Solution2 {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end()); // Note how string behaves same as vector.
        for (int i = 0, j = 0; j <= s.length(); ++ j) { // <=
            if (j == s.length() || isspace(s[j])) {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
    }
};


// Works. Tested. By: XC.
class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() <= 1) return;
        
        char * p = (char*) s.c_str(), * q; // note the casting.
        rev(p, p + s.length() - 1);
        
        while (*p) {
            while (*p == ' ') ++ p; // p is head of word.
            if (! *p) break; // end of string.
            
            q = p;
            while (*q && *q != ' ') ++ q;
            -- q; // q is end of word.
            
            rev(p, q);
            p = q + 1;
        }
    }
    
    void rev(char * p , char * q) {
        while (p < q) {
            char tmp = *p;
            *p = *q;
            *q = tmp;
            ++ p; -- q;
        }
    }
};

/**
Reverse Words in a String II 
Difficulty: Medium

Given an input string, reverse the string word by word. 
A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing 
spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
 */
