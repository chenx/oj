// This should work. Although time out for very large test case.
// Use brutal force match. O(n^2). 2/15/2015.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        
        if (n < 20) return ans;
        
        for (int i = 0; i <= n - 10; ++ i) {
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
