/**
 * This works.
 * Be careful when one ends, but the other got more section.
 * A section that does not exist is regarded as 0.
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        const char * s1 = version1.c_str(), 
                   * s2 = version2.c_str();
        int v1 = 0, v2 = 0;    
        while (1) {
            v1 = next(s1);
            v2 = next(s2);
            if (v1 < 0 || v2 < 0) break;
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
        }
        
        if (v1 < 0) v1 = 0;
        if (v2 < 0) v2 = 0;

        if (v1 > v2) return 1;
        if (v1 < v2) return -1;
        return 0;
    }
    
    int next(const char *& s) {
        if (*s == '.') ++ s;
        if (! *s) return -1;
        
        int v = 0;
        while (*s >= '0' && *s <= '9') {
            v = v * 10 + (*s - '0');
            ++ s;
        }
        return v;
    }
};


/*
Compare Version Numbers 

Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
 */
