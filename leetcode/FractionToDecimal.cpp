
// This works.
// From: https://oj.leetcode.com/discuss/18731/accepted-cpp-solution-with-explainations
string fractionToDecimal(int64_t n, int64_t d) {
    // zero numerator
    if (n == 0) return "0";

    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);

    // append integral part
    res += to_string(n / d);

    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<int, int> map;

    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {

        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;

        // append the quotient digit
        res += to_string(r / d);
    }

    return res;
}


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
