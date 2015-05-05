#include <iostream>
using namespace std;

// No ****** in a row.
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        
        return m(s, p);
    }
    
    // This works, but time out for large test set.
    bool m(const char *s, const char *p) {
        if (*s == 0) {
            if (*p == 0) return true;
            if (*(p+1) == '*') return m(s, p+2); // ignore a*.
            return false;
        }
            
        if (*p == '.' || *p == *s) { 
            if (*(p+1) != '*') {
                return m(s+1, p+1);
            } else { // ignore s, p or both.
                return m(s+1, p) || m(s+1, p+2) || m(s, p+2);
            }
        } else if (*(p+1) == '*') {
            return m(s, p+2);
        } else { 
            return false;
        }        
    }
};

// This works, and passes complex test set too. Use recursion too.
// From: http://blog.csdn.net/tingmei/article/details/8049850
class Solution2 {  
    public:  
        bool isMatch(const char *s, const char *p) {  
            // Start typing your C/C++ solution below  
            // DO NOT write int main() function      
            if (*p == '\0') return *s == '\0';  
            if (*(p+1) == '*') // ģʽ������һ���ַ���'*'  
            {  
                while(*p == *s || (*p == '.' && *s != '\0'))  
                {  
                    //�ַ�����ģʽ��ƥ��0/1/2...���ַ������  
                    if (isMatch(s++, p+2))  
                        return true;  
                }  
                // �ַ�����ģʽ������ƥ��  
                return isMatch(s, p+2);  
            }  
            else  
            {  
                if (*p == *s || (*p == '.' && *s != '\0'))  
                    return isMatch(s+1, p+1);  
                return false;  
            }  
        }  
        
        // Optimized from isMatch().
        //
        // Note:  if (*p == 0) return *s == 0;  
        // is NOT equivalent to:
        //        if (!*p && !*s) return true;
        //        if (!*p || !*s) return false; // <- this is problematic.
        // For example, if p = ".*", s = "", then !*p is false, 
        // !*s is true, but this match is true! Since * can match 0 '.'.
        //
        bool isMatch2(const char *s, const char *p) {  
            if (*p == 0) return *s == 0;  
            if (*(p+1) == '*') {
                while(*p == *s || (*p == '.' && *s)) {  // *p matches *s.
                    if (isMatch(s++, p+2)) return true;  
                }  
                return isMatch(s, p+2); // *p doesn't match *s, ignore p and p+1.
            }  
            else {
                if (*p == *s || (*p == '.' && *s))  
                    return isMatch(s+1, p+1);  
                return false;  
            }  
        }          

    // This works too, modified from isMatch3.
    bool isMatch3(const char *s, const char *p) {
        if (!s && !p) return true;
        if (!s || !p) return false;

        if (!*p) return !*s;
        
        if (*(p+1) == '*') {
            if (*s == *p || (*p == '.' && *s)) {
                return isMatch(s, p+2) || isMatch(s+1, p);   
            }
            else {
                return isMatch(s, p+2);
            }            
        }
        else if (*s == *p || (*p == '.' && *s)) {
            return isMatch(s+1, p+1);
        }
        else {
            return false;
        }
    }
};  
    
    
// Not working yet.
class Solution3 {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        
        return m(s, p);
    }
    
    bool m(const char *s, const char *p) {
        bool t1 = false, t2 = false;
        const char * s0, * p0;
                
        while(1) {
            
            if (*s == 0) {
                if (*p == 0) return true;
                else if (*(p+1) == '*') {
                    p += 2;
                }
                else {
                    return false;
                }
            }
                
            if (*p == '.' || *p == *s) { 
                if (*(p+1) != '*') {
                    ++s, ++p;
                } else { // ignore s, p or both.
                    //return m(s+1, p) || m(s+1, p+2) || m(s, p+2);
                }
            } else if (*(p+1) == '*') {
                p += 2;
            } else { 
                return false;
            }        
            
        }
    }
};


int main() {
    return 0;
}
