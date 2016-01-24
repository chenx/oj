class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    
    // This works too.
    bool isAnagram2(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int n = s.length();
        vector<int> v1(256, 0), v2(256, 0);
        
        for (int i = 0; i < n; ++ i) {
            ++ v1[s[i]];
        }
        for (int i = 0; i < n; ++ i) {
            ++ v2[t[i]];
        }
        
        for (int i = 0; i < 256; ++ i) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }    
};
