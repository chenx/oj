//
// Symbol Value
// I 	    1
// V 	    5
// X 	    10
// L 	    50
// C 	    100
// D    	500
// M    	1,000
// 
// Subtractive notation is often used as follows:
//    I placed before V or X indicates one less, so four is IV (one less than five) 
//        and nine is IX (one less than ten)
//    X placed before L or C indicates ten less, so forty is XL (ten less than fifty) 
//        and ninety is XC (ten less than a hundred)
//    C placed before D or M indicates a hundred less, so four hundred is CD (a 
//        hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand)[5]
//
// To convert number to Roman:
//    for each symbol s (including combined symbol):
//        while (number > s)
//            number -= s
//            roman.append(s)
//
// See: https://en.wikipedia.org/wiki/Roman_numerals
//
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// This works too. Modified from Solution2. 11/29/2015
class Solution3 {
public:
    string intToRoman(int num) {
        static string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        static int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s = "";
        
        for (int i = 0, len = sizeof(val) / sizeof(int); i < len; ++ i) {
            eval(num, s, val[i], roman[i]);
        }
        return s;
    }
    
    void eval(int &num, string &s, int v, string roman) {
        while (num >= v) {
            s += roman;
            num -= v;
        }
    }
};

// This works too. 11/7/2014
class Solution2 {
public:
    string intToRoman(int num) {
        string s;
        eval(num, s, 1000, "M");
        eval(num, s, 900, "CM");
        eval(num, s, 500, "D");
        eval(num, s, 400, "CD");
        eval(num, s, 100, "C");
        eval(num, s, 90, "XC");
        eval(num, s, 50, "L");
        eval(num, s, 40, "XL");
        eval(num, s, 10, "X");
        eval(num, s, 9, "IX");
        eval(num, s, 5, "V");
        eval(num, s, 4, "IV");
        eval(num, s, 1, "I");
        return s;
    }
    
    void eval(int &num, string &s, int v, string roman) {
        while (num >= v) {
            s += roman;
            num -= v;
        }
    }
};

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


/**
Integer to Roman
Difficulty: Medium

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */
