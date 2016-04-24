// kmp. works too.
class Solution2 {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) { 
        if (source == NULL || target == NULL) return -1;
        int n = strlen(source), m = strlen(target);
        if (n < m) return -1;
        if (m == 0) return 0;
        
        int F[m]; // = {0}; // this initialization won't work.
        getFailureFunc(F, target);
        
        int i = 0, j = 0;
        while (i < n) {
            if (source[i] == target[j]) {
                if (j == m - 1) return i - j;
                ++ i; ++ j;
            }
            else if (j > 0) {
                j = F[j - 1];
            }
            else {
                ++ i;
            }
        }
        
        return -1;
    }
    
    void getFailureFunc(int F[], const char * p) {
        int i = 1, j = 0, m = strlen(p);
        F[0] = 0;
        
        while (i < m) {
            if (p[i] == p[j]) {
                F[i] = j + 1;
                ++ i; ++ j;
            }
            else if (j > 0) {
                j = F[j - 1];
            }
            else {
                F[i] = 0;
                ++ i;
            }
        }
    }
};


class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        //if (source == NULL && target == NULL) return -1;
        if (source == NULL || target == NULL) return -1;
        
        int n1 = strlen(source), n2 = strlen(target), n = n1 - n2;
        if (n < 0) return -1;
        
        for (int i = 0; i <= n; ++ i) {
            const char * s = source + i, * t = target;
            for ( ; *t && *t == *s ; ++ t, ++ s) ;
            if (! *t) return i;
        }
        return -1;
    }
};


/**
strStr

For a given source string and a target string, you should output 
the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.
Have you met this question in a real interview?
Clarification

Do I need to implement KMP Algorithm in a real interview?

    Not necessary. When you meet this problem in a real interview, 
    the interviewer may just want to test your basic implementation 
    ability. But make sure your confirm with the interviewer first.

Example

If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

 */
