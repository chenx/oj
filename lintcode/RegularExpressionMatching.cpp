class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (! *p) return ! *s;
        
        if (*(p+1) == '*') {
            if (*p == *s || (*p == '.' && *s)) {
                return isMatch(s + 1, p) || isMatch(s, p + 2);
            }
            return isMatch(s, p + 2);
        }
        else if (*p == *s || (*p == '.' && *s)) {
            return isMatch(s + 1, p + 1);
        }
        else {
            return false;
        }
    }
};
