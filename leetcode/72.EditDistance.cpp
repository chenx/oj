//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/19/2012
// @Last modified: 3/22/2012
//

/*
 * Three things: 
 * 1) initialize: 0, 1, 2, 3, ...
 * 2) insert - left, delete - up
 * 3) for replace cost, use 
        a[i][j] + ((word1[i] == word2[j]) ? 0 : 1);
      instead of
        a[i][j] + (word1[i] == word2[j]) ? 0 : 1;
      The latter will be only 0 and 1.
 */

#include <iostream>
#include <string>
using namespace std;


class Solution5 {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> DP(n1+1, vector<int>(n2+1, 0));

        for (int i = 1; i <= n1; ++ i) DP[i][0] = i; // NOTE: "<="
        for (int j = 1; j <= n2; ++ j) DP[0][j] = j; // NOTE: "<="

        for (int i = 0; i < n1; ++ i) {
            for (int j = 0; j < n2; ++ j) {
                if (word1[i] == word2[j]) {
                    DP[i+1][j+1] = DP[i][j];
                } else {
                    DP[i+1][j+1] = 1 + min(DP[i][j], min(DP[i+1][j], DP[i][j+1]));
                }
            }
        }
        return DP[n1][n2];
    }
};


// This works too.
class Solution4 {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> v(len1+1, vector<int>(len2+1, 0));
        
        for (int j = 0; j <= len2; ++ j) v[0][j] = j;
        
        for (int i = 1; i <= len1; ++ i) {
            v[i][0] = i;
            for (int j = 1; j <= len2; ++ j) {
                int add = 1 + v[i-1][j];
                int del = 1 + v[i][j-1];
                int rep = v[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1); 
                v[i][j] = min(rep, min(add, del));
            }
        }
        
        return v[len1][len2];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();
        
        int i, j;
        int * a[word1.length() + 1];
        for (i = 0; i <= word1.length(); i ++) {
            a[i] = new int[word2.length() + 1];
        }
        
        for (i = 0; i <= word2.length(); i ++) {
            a[0][i] = i;
        }
        
        for (i = 0; i < word1.length(); i ++) {
            a[i+1][0] = i+1;
            for (j = 0; j < word2.length(); j ++) {
                int ins = a[i+1][j] + 1; // left
                int del = a[i][j+1] + 1; // up
                int rep = a[i][j] + ((word1[i] == word2[j]) ? 0 : 1);
                a[i+1][j+1] = min(ins, min(del, rep));
            }
        }
        
        dump(a, word2.length() + 1, word1.length() + 1);

        return a[word1.length()][word2.length()];
    }
    
    void dump(int ** a, int w, int h) {
        for (int i = 0; i < h; i ++) {
            for (int j = 0; j < w; j ++) {
                printf("%2d ", a[i][j]);
            }
            puts("");
        }
        puts("");
    }
};

//
// The recursive solution!
// This works, although times out for the large test set.
// This looks very simple!
//
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        return mD(word1.c_str(), word2.c_str());
    }
    
    int mD(const char * w1, const char * w2) {
        if (! *w1) return strlen(w2);
        if (! *w2) return strlen(w1);
        
        if (*w1 == *w2) { // Question: does it work by single out this??
            return mD(w1 + 1, w2 + 1);
        }
        else {
            int ins = mD(w1 + 1, w2) + 1;
            int del = mD(w1, w2 + 1) + 1;
            int rep = mD(w1 + 1, w2 + 1) + 1;
            return min(min(ins, del), rep);
        }
    }
};

//
// This works too. But times out for large input.
// Changed from Solution2.
//
class Solution3 {
public:
    int minDistance(string word1, string word2) {
        return mD(word1.c_str(), word2.c_str());
    }
    
    int mD(const char * w1, const char * w2) {
        if (! *w1) return strlen(w2);
        if (! *w2) return strlen(w1);
        
        int ins = mD(w1 + 1, w2) + 1;
        int del = mD(w1, w2 + 1) + 1;
        int rep = mD(w1 + 1, w2 + 1) + ((*w1 == *w2) ? 0 : 1);
        return min(min(ins, del), rep);
    }
};

int main() {
    Solution s;
    string w1 = "pzz";
    string w2 = "pux";
    s.minDistance(w1, w2);
    
    Solution2 s2;
    cout << "s2: " << s2.minDistance(w1, w2) << endl;

    Solution3 s3;
    cout << "s3: " << s3.minDistance(w1, w2) << endl;
    
    return 0;
}


/**
Edit Distance
Difficulty: Hard

Given two words word1 and word2, find the minimum number of steps required 
to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
 */

