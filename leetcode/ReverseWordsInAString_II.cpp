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
