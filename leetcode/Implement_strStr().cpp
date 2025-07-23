//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

// This works too. Another kmp method.
class Solution7 {
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
        
        int F[m+1]; // = {0}; // this initialization won't work.
        getFailureFunc2(F, target);
        
        int i = 0, j = 0;
        while (i < n) {
            if (source[i] == target[j]) {
                if (j == m - 1) return i - j;
                ++ i; ++ j;
            }
            else if (j > 0) {
                j = F[j];// - 1];
            }
            else {
                ++ i;
            }
        }
        
        return -1;
    }
    
    void getFailureFunc2(int F[], const char * p) {
        int i = 0, j = -1, m = strlen(p);
        F[0] = -1;
        
        while (i < m) {
            if (j == -1 || p[j] == p[i]) {
                F[++ i] = ++ j;
            }
            else {
                j = F[j];
            }
        }
    }
};


class Solution6 {
public:
    // Note: for (b = needle; *b && (*b ++ == *a ++); ) {}
    // will cause problem!
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == needle || NULL == haystack) return NULL;
        int len_a = strlen(haystack);
        int len_b = strlen(needle);
        if (len_b == 0) return haystack;
        if (len_a < len_b) return NULL;

        int len = len_a - len_b;
        char * a, * b;
        for (int i = 0; i <= len; i ++) {
            a = haystack + i;
            for (b = needle; *b && (*b == *a); ++ a, ++ b) {}
            if (! *b) return haystack + i;            
        }
        return NULL;
    }
};

// This works too.
// Note: if use "if (*pb ++ != *pa ++) break;", then it won't work! don't know why.
class Solution5 {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) return NULL;
        int lena = strlen(haystack);
        int lenb = strlen(needle);
        
        for (int i = 0; i <= lena - lenb; ++ i) {
            char *pa = haystack + i;
            char *pb = needle;
            while (*pb) {
                if (*pb  != *pa ) break;
                ++pa, ++pb;
            }
            if (! *pb) return haystack + i;
        }
        
        return NULL;
    }
};

// This works too. Brute-Force match. O(mn).
class Solution4 {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) return NULL;
        int len = strlen(haystack) - strlen(needle);
        
        char *pa, *pb;
        for (int i = 0; i <= len; ++ i) {
            for (pa = haystack+i, pb=needle; *pb && *pb == *pa; ++pa, ++pb) ;
            if (! *pb) return haystack + i;
        }
        
        return NULL;
    }
};

// This works too. Use KMP match. O(m+n).
class Solution3 {
public:
    int strStr(char *haystack, char *needle) {
        return kmp(haystack, needle);
    }
private:    
    int kmp(char * T, char * P) {
        int n = strlen(T), m = strlen(P);
        if (n < m) return -1;
        if (m == 0) return 0;
        
        vector<int> F(m);
        getFailureFunc(P, F);
        
        int i = 0, j = 0;
        
        while (i < n) {
            if (T[i] == P[j]) {
                if (j == m - 1) return i - m + 1;
                ++ i, ++ j;
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
    
    void getFailureFunc(char * P, vector<int> & F) {
        int m = strlen(P);
        F[0] = 0;
        int i = 1, j = 0;

        while (i < m) {
            if (P[i] == P[j]) {
                F[i] = j + 1;
                ++ i, ++ j;
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

// This works too. Use new signature.
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();

        for (int i = 0, len = len1 - len2; i <= len; ++ i) {
            int j = 0;
            for (; j < len2; ++ j) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == len2) return i;
        }
        
        return -1;
    }
};

// Works.
class Solution8 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if (n < m) return -1;

        for (int i = 0; i <= n - m; i ++) {
            int j = 0;
            for (; j < m; j ++) {
                if (haystack[i + j] != needle[j]) break;  // Notice: haystack[i + j]
            }

            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};

// This works too. Use new signature.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        
        int lenj = needle.length(), i, j;
        int len = haystack.length() - lenj;

        for (i = 0; i <= len; ++ i) {
            for (j = 0; j < lenj; ++ j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == lenj) return i;
        }
        
        return -1;
    }
};

/**
Implement strStr()
Difficulty: Easy

Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack. 
 */
