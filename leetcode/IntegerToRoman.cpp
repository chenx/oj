//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// http://en.wikipedia.org/wiki/Roman_numerals
class Solution {
public:
    string intToRoman(int num) {
        string TH[] = {"M", "MM", "MMM"}; // 1000-3000
        string H[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; // 100-900
        string T[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; // 10-90
        string N[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; // 1-9
        
        string s = "";
        
        int q = num / 1000;
        if (q > 0) s += TH[q - 1];
        num %= 1000;
        
        q = num / 100;
        if (q > 0) s += H[q - 1];
        num %= 100;
        
        q = num / 10;
        if (q > 0) s += T[q - 1];
        num %= 10;

        q = num;
        if (q > 0) s += N[q - 1];
        
        return s;
    }
};
