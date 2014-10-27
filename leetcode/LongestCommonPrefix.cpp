//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 1/21/2013
//

/*
 * It's possible to use a Trie, but it seems like a over-kill.
 */
 
// This works too, and is clean.
class Solution3 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        
        int p = strs[0].length();
        for (int i = 1, n = strs.size(); i < n; ++ i) {
            int q = common(strs[0], strs[i], p);
            p = min(p, q);
        }
        return strs[0].substr(0, p);
    }
    
    int common(string a, string b, int p) { // p - make use of previous result.
        int n = min(p, b.length());
        for (int i = 0; i < n; ++ i) {
            if (a[i] != b[i]) return i;
        }
        return n;
    }
    
    int min(int a, int b) { return a < b ? a : b; }
};

// This works too. And is shorter. Better.
class Solution2 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        
        int i;
        char c;
        bool goon = true;
        
        for (i = 0; goon; ++ i) {
            if ((c = strs[0][i]) == '\0') break;  // also can use 0, or ! (c = ..).
            for (int j = 1; j < strs.size(); ++ j) {
                //if (strs[j][i] == '\0' || strs[j][i] != c) {
                if (strs[j][i] != c) { // case of "strs[j][i] == '\0'" included.
                    goon = false;
                    -- i; // to counter-act the "++i".
                    break;
                }
            }
        }
        
        return strs[0].substr(0, i);        
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string p = "";
        int len = strs.size();
        if (len == 0) return p;
        
        int ct = strs.size();
        int min_len = strs[0].size();
        for (int i = 1; i < ct; i ++) {
            if (min_len > strs[i].length {
                min_len = strs[i].length();
            }
        }
        
        char c;
        int i, j;
        for (i = 0; i < min_len; i ++) { 
            c = strs[0][i];
            // loop thru each string.
            for (j = 1; j < ct; j ++) {
                if (c != strs[j][i]) break;
            }
            if (j == ct) p += c;
            else break; // inconsistent char found.
        }
        
        return p;
    }
};
