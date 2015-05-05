//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 10/26/2014
//

//
// This works too. 
// Is best solution. Really easy to understand.
// Converted from Java version at: 
// https://oj.leetcode.com/discuss/10493/easy-to-understand-java-solution 
//
class Solution3 {
public:
    string convert(string s, int nRows) {
        string rows[nRows];
        //for (int i = 0; i < nRows; ++ i) rows[i] = "";
        
        int k = 0, n = s.length();
        while (k < n) {
            for (int i = 0; i < nRows && k < n; ++ i) rows[i] += s[k ++];
            for (int i = nRows - 2; i >= 1 && k < n; -- i) rows[i] += s[k ++];
        }
        
        string ans; // = "";
        for (int i = 0; i < nRows; ++ i) ans += rows[i];
        
        return ans;
    }
};

// This works too. 10-26-2014
class Solution2 {
public:
    string convert(string s, int nRows) {
        int N = s.length();
        if (N == 0 || nRows == 0) return "";
        if (nRows == 1) return s; // first line code below will go infinite when nRows is 1.
        
        string t = "";
        
        // first line
        for (int j = 0; j < N; j += 2*nRows - 2) {
            t += s[j];
        }
        
        // middle lines
        for (int i = 1; i < nRows - 1; ++ i) {
            int ct = 0; // column count
            for (int j = i; j < N + nRows; j += nRows - 1) {
                int k = j;
                if (ct & 1) {
                    // base is the index of the last element in the previous column 
                    int base = (j/(2 * nRows - 2)) * (2 * nRows - 2) + ( (ct & 1) ? (nRows - 1) : 0 );
                    k = base + (nRows - i - 1); // for odd number column, index goes in inverse.
                }
                if (k < N) t += s[k];
                
                ++ ct;
            }
        }
        
        // last line
        for (int j = nRows - 1; j < N; j += 2*nRows - 2) {
            t += s[j];
        }
        
        return t;
    }
};

// This works.
class Solution {
public:
    // Each block size is 2*nRows - 2.
    // Number of blocks: s.length / (2*nRows - 2)
    string convert(string s, int nRows) {
        string r;
        
        int len = s.length();
        if (len <= nRows || nRows == 1) return s;
        
        int block_size = 2 * nRows - 2;
        int block_num = len / block_size;
        
        int i, j, k, x = 2 * nRows - 2, y = nRows - 1;
        
        // add first row. each element is x = 2*nRows - 2 apart.
        for (j = 0, k = 0; j <= block_num; j ++, k += x) {
            if (k < len) r += s[k];
        }
        
        // add middle rows
        for (i = 1; i < nRows - 1; i ++) {
            for (j = 0, k = i; j <= block_num; j ++, k += x) {
                if (k < len) r += s[k];
                if (k-i + y-i + y < len) r += s[k-i + y-i + y];
            }
        }
        // k-i: top row's k, y-i: inverse rank,
        // k-i + y-i: actual k. 
        // k-i + y-i + y: index of char here.
        // Note: if not zigzag (down, up, down, up),
        // but down down down down, then here should be:
        // if (k + y < len) r += [k+ y];
        
        // add last row.
        for (j = 0, k = y; j <= block_num; j ++, k += x) {
            if (k < len) r += s[k];
        }        
        
        return r;
    }
};


/*
Problem:

The string "PAYPALISHIRING" is written in a zigzag pattern on a 
given number of rows like this: (you may want to display this 
pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
