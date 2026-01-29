class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (m < n) return -1;

        for (int i = 0; i <= m-n; ++ i) {
            int j = 0;
            for (; j < n; ++ j) {
                if (haystack[i + j] != needle[j]) break;
                if (j == n-1) return i;
            }
        }
        return -1;
    }
};

/**
28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
conpanies iconCompanies

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
 */
