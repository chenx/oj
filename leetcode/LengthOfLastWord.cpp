//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/19/2012
// @Last modified: 12/19/2012
//

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) return 0;
        
        char * p = (char *) s, * q;

        for (; *p == ' ' ; ++ p) {} // skip start spaces.
        if (*p == 0) return 0;
        
        q = p; // q is first non-space char.
        for (++ p; *p; ++ p) {
            if (*(p - 1) == ' ' && *p != ' ') q = p;
        }
        -- p; // p at the end.
        
        for(; *p == ' '; -- p) ; // skip end spaces.
        
        return p - q + 1;
    }
};


//
// This works too, and seems more clear.
//
class Solution2 {
public:
    int lengthOfLastWord(const char *s) {
        const char * end = s;
        
        while (*end == ' ') ++ end;
        
        if (! *end) return 0; // only blank space.
                
        while (*end) ++ end; // move end to end of string.
        
        -- end; // back off.
        
        while (*end == ' ') -- end; // end points to end of last word.
        
        const char * start = end;
        
        while (*start != ' ' && start != s) -- start; // start != s is important!!
        
        if (*start == ' ') ++ start; // back off if space.
        
        return end - start + 1;
    }
};