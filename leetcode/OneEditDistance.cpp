// Should Work. Not tested.
class Solution2 {
    bool IsOneEditDistance(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if (n1 > n2) return IsOneEditDistance(t, s);
        if (n2 > n1 + 1) return false;

        if (n1 == n2) {
            int ct = 0;
            for (int i = 0; i < n1; ++ i) {
                if (s[i] != t[i]) ++ ct;
                if (ct == 2) return false;
            }
            return ct == 1;
        }
        else {
            int i = 0;
            for (; i < n1 && s[i] == t[i]; ++ i) ;
            // if i == n1, should be true, the below statement will be ignored.
            for (; i < n1 && s[i] == t[i+1]; ++ i) ;
            return i == n1;
        }
    }
};

// Works. Tested.
class Solution {
    bool IsOneEditDistance(string s, string t) {
        int lens = s.length(), lent = t.length();
        if (lens > lent) return IsOneEditDistance(t, s);
        
        if (lent - lens > 1) return false;
        else if (lent == lens) {
            int diff = 0;
            for (int i = 0; i < lens; ++ i) {
                if (s[i] != t[i]) ++ diff;
            }
            return diff == 1;
        } else { // lent == lens + 1. Only difference is t has 1 more char at beginning or end.
            int is = 0, it = 0;
            for (; is < lens && s[is] == t[it]; ++ is, ++ it) {}
            ++ it;
            for (; is < lens && s[is] == t[it]; ++ is, ++ it) {}
            return is == lens && it == lent;
        }
    }
};

/**
Problem: determine if s and t differ by exactly 1 char.
 */
