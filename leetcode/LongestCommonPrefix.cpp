//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 1/21/2013
//

/*
 * It's possible to use a Trie, but it seems like a over-kill.
 */

// Works. Tested. Good.
// This is totally different from previous solutions in approach.
// This basically is like merge sort. 
// Previous solutions just use (n-1) string to string comparisons, so O(n^2).
// This solution uses n/2 + n/4 + n/8 + .. comparisons:
// T(n) = 2*T(n/2) + n, so it's O(nlog(n)).
class Solution5 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int minLen = getCommonLen(strs, 0, strs.size() - 1);
        return strs[0].substr(0, minLen);
    }
    
    int getCommonLen(vector<string>& strs, int L, int R) {
        //if (L > R) return INT_MAX; // no need for this, since strictly L <= M <= R.
        if (L == R) return strs[L].length();
        
        int M = L + (R-L)/2;
        int len = min( getCommonLen(strs, L, M), getCommonLen(strs, M+1, R) );
        for (int i = 0; i < len; ++ i) {
            if (strs[L][i] != strs[R][i]) return i;
        }
        return len;
    }
};

// This works too. Is best so far. O(nm).
class Solution4 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        
        int minLen = strs[0].length();
        for (int i = 1; i < strs.size(); ++ i) {
            getCommonLen(strs[0], strs[i], minLen);
        }

        return strs[0].substr(0, minLen);
    }
    
    void getCommonLen(string a, string b, int &minLen) {
        minLen = min(minLen, (int) b.length());
        for (int i = 0; i < minLen; ++ i) {
            if (a[i] != b[i]) {
                minLen = i;
                break;
            }
        }
    }
};

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
