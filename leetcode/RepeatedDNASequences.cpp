// This works! So short. Slightly modified from: 
// https://oj.leetcode.com/discuss/24710/can-anyone-tell-me-how-get-ac-result-below-50ms-using-c
// Use rolling hash m, which contains a space of 20 digits.
// note s[i] >> 1 & 3 will label a letter in A (65: 1000001), C(67: 1000011), G(71: 1000111), T(84: 1010100).
// which will result in: A - 00, C - 01, G - 11, T - 10.
class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r;
        int t = 0, i = 0, len = s.size(), m[1 << 20] = {0};
        while (i < 9) {
            t = t << 2 | s[i++] >> 1 & 3;
        }
        while (i < len) {
            if (m[t = t << 2 & 0xFFFFF | s[i++] >> 1 & 3]++ == 1) {
                r.push_back(s.substr(i - 10, 10));
            }
        }
        return r;
    }
};

// This should work. Although time out for very large test case.
// Use brutal force match. O(n^2). 2/15/2015.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        
        if (n < 20) return ans;
        
        for (int i = 0; i <= n - 20; ++ i) {
            string p = s.substr(i, 10);
            if (strstr(s.c_str() + i + 10, p.c_str()) != NULL) {
                ans.push_back(p);
            }
        }
        
        return ans;
    }
    
    char * strstr(char * s, char * p) {
        int lens = strlen(s), lenp = strlen(p);
        
        for (int i = 0; i <= lens - lenp; ++ i) {
            char * a = s + i, * b = p;
            while (*b && *b == *a) { ++ a, ++ b; }
            if (! *b) return s + i;
        }
        
        return NULL;
    }
};

/**
Repeated DNA Sequences 

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */
