class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        int i = 0;
        while (i < expression.size()) {
            int currNum = 0;
            int currDenom = 0;

            bool isNegative = false;

            // check for sign
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') {
                    isNegative = true;
                }
                // move to next character
                i++;
            }

            // build numerator
            while (isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }

            if (isNegative) currNum *= -1;

            // skip divisor
            i++;

            // build denominator
            while (i < expression.size() && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDenom = currDenom * 10 + val;
                i++;
            }

            // add fractions together using common denominator
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = abs(FindGCD(num, denom));

        // reduce fractions
        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};


/**
592. Fraction Addition and Subtraction
Solved
Medium
Topics
conpanies iconCompanies

Given a string expression representing an expression of fraction addition and subtraction, 
return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, 
change it to the format of a fraction that has a denominator 1. So in this case, 2 should 
be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"

Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 */
