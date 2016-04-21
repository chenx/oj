// This should work, but times out for large input.
// Use the iterative solution is necessary.
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
            if (! *s) {
                while (*p == '*') ++ p;
                return ! *p;
            }
            
            if (*p == '*') {
                return isMatch(s + 1, p) || isMatch(s, p + 1);
            }
            if (*p == *s || *p == '?') {
                return isMatch(s + 1, p + 1);
            }
            else {
                return false;
            }
    }
};
