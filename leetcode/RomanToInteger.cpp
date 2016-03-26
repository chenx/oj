//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// This works too.
// More clean. 
// Basically, Roman number is written from large digit to small digit.
// If cur digit > prev digit, then should minus prev digit from sum.
class Solution2 {
public:
    int romanToInt(string s) {
        int cur, prev = 0, sum = 0;
        for (int i = 0, n = s.size(); i < n; ++ i) {
            cur = getV(s[i]);
            sum += (cur > prev) ? - prev : prev;
            prev = cur;
        }
        sum += prev;
        
        return sum;
    }
    
    int getV(char c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else if (c == 'M') return 1000;
    }
};


// This works.
// http://en.wikipedia.org/wiki/Roman_numerals
class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0) return 0;
        int n, i;
        
        int v = getVal(s[0]);
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i ++) {
            n = getVal(s[i + 1]);
            if (v < n) sum += -v;
            else sum += v;
            v = n;
        }
        sum += v;
        
        return sum;
    }
    
    int getVal(char c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else if (c == 'M') return 1000;
    }
};


/**
Roman to Integer
Difficulty: Easy

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */
