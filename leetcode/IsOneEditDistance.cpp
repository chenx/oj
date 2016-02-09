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
