//
// This does not work yet. out of memory error.
//
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "0";
        int int_part = numerator / denominator;
        char p[10];
        sprintf(p, "%d", int_part);
        numerator %= denominator;
        
        string s = "";
        int n1 = numerator;
        while (1) {
            int a = numerator * 10;
            int q = a / denominator; // quotient
            int r = a % denominator; // remainder
            
            char qc = '0' + q;
            s += qc;
            
            if (r == 0) {
                break;
            }
            else if (r == n1) {
                s = "(" + s + ")";
                break;
            }
            
            numerator = r;
        }
        
        s = string(p) + "." + s;
        return s;
    }
};

/**
Fraction to Recurring Decimal 

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
 */
