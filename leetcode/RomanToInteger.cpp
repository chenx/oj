// From: https://leetcode.com/problems/roman-to-integer/editorial/
// Time: O(1)
// Space: O(1)
class Solution6 {
public:
    map<string, int> values = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
    };

    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.size()) {
            if (i < s.size() - 1) {
                string doubleSymbol = s.substr(i, 2);
                if (values.contains(doubleSymbol)) {
                    sum += values[doubleSymbol];
                    i += 2;
                    continue;
                }
            }
            // otherwise, it must be the length-1 symbol case
            string singleSymbol = s.substr(i, 1);
            sum += values[singleSymbol];
            i += 1;
        }
        return sum;
    }
};


//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// Works.
class Solution5 {
public:
    int romanToInt(string s) {
        if (s.length() == 0) return 0;

        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                            {'C', 100}, {'D', 500}, {'M', 1000}};

        int v = m[s[0]], prev = v, cur = v;
        for (int i = 1; i < s.length(); ++ i) {
            cur = m[s[i]];
            if (cur > prev) {
                v = (v - prev) + (cur - prev);
            } else {
                v += cur;
            }
            prev = cur;
        }

        return v;
    }
};

// Works. Use map.
class Solution4 {
public:
    int romanToInt(string s) {
        // Hashmap is slow. Use function getV is faster.
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000},
        };

        int v = 0, prev = 0;
        for (int i = 0; i < s.length(); i ++) {
            int cur = m[s[i]];
            if (cur > prev) { 
                v -= prev;
            } else {
                v += prev;
            }
            prev = cur;
        }
        v += prev;

        return v;
    }
};

// Works too. 
class Solution3 {
public:
    int romanToInt(string s) {
        if (s == "") return 0;
        
        // NOTE 1: if initialize prev = getV(s[0]), i = 1, it works too.
        // but now is most clean.
        int v = 0, prev = 0; 
        for (int i = 0; i < s.length(); ++ i) {
            int cur = getV(s[i]);
            if (cur <= prev) v += prev; // NOTE 2: must be "<=" for "+="! ">" for "-=".
            else v -= prev;
            prev = cur;
        }
        v += prev; // cur = 0, cur <= prev.
        
        return v;
    }
    
    // this works too.
    int romanToInt2(string s) {
        if (s == "") return 0;
        
        int v = 0, pre = getV(s[0]);
        for (int i = 1; i < s.length(); ++ i) {
            int cur = getV(s[i]);
            if (cur > pre) v -= pre;
            else v += pre;
            pre = cur;
        }
        v += pre;
        return v;
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

// This works too.
// More clean. 
// Basically, Roman number is written from large digit to small digit.
// To convert Roman to integer:
//     sum starts at 0, prev = 1st digit
//     for each 2nd to nth digit cur:
//         if cur > prev, then sum -= prev
//         else sum += prev
//     at end of loop, sum += the final prev
// 
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


