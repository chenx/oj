#include <iostream>
using namespace std;

// Slightly modified from Solution5 and more clear. Works.
class Solution6 {
public:
    bool isMatch(string s, string p) {
        int si = 0, si0 = 0, pi = 0, pi0 = 0;
        bool starFound = false;
        
        while (true) {
            if (si == s.length()) {
                while (p[pi] == '*') ++ pi;
                return pi == p.length();
            }

            if (s[si] == p[pi] || p[pi] == '?') {
                ++ si;
                ++ pi;
            } else if (p[pi] == '*') {
                starFound = true;
                si0 = si;
                pi0 = pi;
                ++ pi;
            } else {
                if (starFound) {
                    si = ++ si0;
                    pi = pi0 + 1;
                } else {
                    return false;
                }
            }
        }
    }
};

// This works too. Modified from Solution4.
class Solution5 {
public:
    bool isMatch(string s, string p) {
        int ip0 = 0, is0 = 0, ip = 0, is = 0;
        bool starFound = false;
        
        while (true) {
            if (is == s.length()) {
                while (p[ip] == '*') ++ ip;
                return ip == p.length();
            }

            if (p[ip] == '?' || p[ip] == s[is]) {
                ++ ip; 
                ++ is;
            }
            else if (p[ip] == '*') {
                ip0 = ip; 
                is0 = is;
                starFound = true;
                ++ ip;
            }
            else {
                if (starFound) {
                    ip = ip0;
                    is = ++ is0;
                    ++ ip;
                }
                else {
                    return false;
                }
            }
        }
    }
};

// This works too. Modified from Java version.
class Solution4 {
public:
    bool isMatch(string s, string p) {
        int ip0 = 0, is0 = 0, ip = 0, is = 0;
        bool starFound = false;
        
        while (true) {
            if (is == s.length()) {
                while (ip < p.length() && p[ip] == '*') ++ ip;
                return ip == p.length();
            }

            if (ip < p.length() && (p[ip] == '?' || p[ip] == s[is])) {
                ++ ip; 
                ++ is;
            }
            else if (ip < p.length() && p[ip] == '*') {
                ip0 = ip; 
                is0 = is;
                starFound = true;
                ++ ip;
            }
            else {
                if (starFound) {
                    ip = ip0;
                    is = ++ is0;
                    ++ ip;
                }
                else {
                    return false;
                }
            }
        }
    }
};

// This works too, pass both small and large test sets.
// Probably better than Solution, since the code is simpler.
class Solution3 {
public:
    bool isMatch(const char *s, const char *p) {
        const char * s0, * p0;
        bool x = false;
        
        while (1) {
            if (! *s) {
                while (*p == '*') ++ p;
                return ! *p;
            }
            
            if (*p == '?' || *p == *s) {
                ++ p;
                ++ s;
            } 
            else if (*p == '*') {
                s0 = s;
                p0 = p;
                x = true; // everything before matched, only need to start here!
                
                ++ p; // assume * does not match anything.
            }
            else {
                if (x) {
                    s = ++ s0; // s0 inc by 1 each time.
                    p = p0;
                    
                    ++ p;
                }
                else { 
                    return false; 
                }
            }
        }
    }
};

// This works, using iteration!
// Reference: http://blog.csdn.net/tingmei/article/details/8049926
// Note: 
// 1) ++ p is faster than p ++; 
// 2) use !(*p) instead of *p == 0.
// 3) declare s0, p0 to const char *, to avoid casting which is slower.
class Solution {
public:
    // This passes small test set, but time out for large test set.
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        
        const char * s0, * p0; // to avoid cast like this: s0 = (char *) s.
        bool star = false;
        while (1) {
            if (*s == 0) {
                if (*p == 0) return true; // <------- code not necessary 
                
                while (*p == '*') ++ p;
                return !(*p);
            }
            
            if (*p == '?') {
                ++ s, ++ p;
            } else if (*p == '*') { // *
                while (*(p+1) == '*') ++p; // ignore extra '*'.
                //return isMatch(s, p+1) || isMatch(s+1, p);
                s0 = s;
                p0 = p; // p0 points to '*'.
                star = true;
                p = p0 + 1; // first ignore '*', see if s can match the rest of p.
            } else {
                if (*p != *s) {
                    if (! star) return false;
                    // now consider * matches one more char in s.
                    ++ s0;
                    s = s0;
                    p = p0 + 1; // revert pattern.
                }
                while (*p && *p == *s) { ++ p, ++ s; }
            }
        }
    }
};

// This works, using recursion.
// This passes small test set, but time out for large test set.
class Solution2 {
public:
    // This works and is the most direct form without optimization.
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;

        if (*s == 0) {
            while (*p == '*') p ++;
            return *p == 0;
        }
        
        if (*p == '?' || *p == *s) {
            return isMatch(s+1, p+1);
        } else if (*p == '*') {
            return isMatch(s, p+1) || isMatch(s+1, p);
        } else {
            return false;
        }
    }
    
    // This works too. Optimized from isMatch(). But still times out.
    bool isMatch2(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        if (*p == 0) {
            if (*s == 0) return true;
        }
        if (*s == 0) {
            while (*p == '*') p ++;
            return *p == 0;
        }
        
        if (*p == '?') {
            return isMatch(s+1, p+1);
        } else if (*p != '*') {
            if (*p != *s) return false;
            while (*p && *p == *s) { p++, s++; }
            return isMatch(s, p);
        } else {
            while (*(p+1) == '*') ++p;
            return isMatch(s, p+1) || isMatch(s+1, p);
        }
    }
           
    // this is wrong, since *s == 0, *p == 0 must be considered.
    bool isMatch_v1(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        
        if (*p == '?') {
            return isMatch(s+1, p+1);
        } else if (*p != '*') {
            if (*p != *s) return false;
            else return isMatch(s+1, p+1);
        } else {
            return isMatch(s, p+1) || isMatch(s+1, p);
        }
    }
    
    // This matches p to only partial of s.
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        
        while (1) {
            while (*p == '*') p ++;
            if (*p == 0) return true;
            if (*s == 0) return false; // *p != 0 and *p != '*'
            
            if (*p == '?') {
                p ++;
                s ++;
                continue;
            }
            
            // else, look for *p in s.
            while (*s && *s != *p) { s ++; }
            
            if (*s == 0) break; // *p not found.
            else { // *p is found.
                s ++;
                p ++;
            }
        }
        
        return (*p == *s);
    }    
        
};

int main() {
    return 0;
}

/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        if (*s == 0) {
            if (*p == 0) return true;
            if (*p != '*') return false;
            else { if (*(p+1) == 0) return true; }
        } else {
            if (*p == 0) return false;
        }
        
        if (*p == '?') {
            ++p, ++s;
            while (*p && *p == *s) { ++p; ++s; }
            return isMatch(s, p);
        } else if (*p != '*') {
            if (*p != *s) return false;
            while (*p && *p == *s) { ++p; ++s; }
            return isMatch(s, p);
        } else {
            // *p == '*'
            while (*(1+p) == '*') ++p;
            return isMatch(s, p+1) || (*s != 0 && isMatch(s+1, p));
        }
    }
};


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        
        while (1) {
            int is_star = (*p == '*');
            while (*p == '*') p ++;
            if (*p == 0) {
                if (*s == 0) return true;
                else return is_star; // true since '*' matchs all
            } 
            if (*s == 0) return false; // *p != 0 and *p != '*'
            
            if (*p == '?') {
                p ++;
                s ++;
                continue;
            }
            
            // else, look for *p in s.
            while (*s && *s != *p) { s ++; }
            
            if (*s == 0) break; // *p not found.
            else { // *p is found.
                s ++;
                p ++;
            }
        }
        
        return (*p == *s);
    }
};


class Solution {
public:
    // This passes small test set, but time out for large test set.
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        bool start = false;
        
        while (1) {
            if (*p == 0) {
                if (*s == 0) return true;
            }
            if (*s == 0) {
                while (*p == '*') p ++;
                return *p == 0;
            }
            
            if (*p == '?') {
                //return isMatch(s+1, p+1);
                s ++, p ++;
            } else if (*p != '*') {
                if (*p != *s) return false;
                while (*p && *p == *s) { p++, s++; }
                //return isMatch(s, p);
            } else { // *
                while (*(p+1) == '*') ++p;
                //return isMatch(s, p+1) || isMatch(s+1, p);
                
            }
        }
    }
};

 */

