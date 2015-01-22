//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//
class Solution {
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
class Solution2 {
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
class Solution3 {
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
class Solution {
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
