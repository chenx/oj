
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;

        int pos = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit != 0) {
                result.insert(result.begin(), digit * pow(10, pos));
            }
            ++ pos;
        }
        return result;
    }
};

/**
3697. Compute Decimal Representation
Easy

You are given a positive integer n.

A positive integer is a base-10 component if it is the product of a single digit from 1 to 9 
and a non-negative power of 10. For example, 500, 30, and 7 are base-10 components, 
while 537, 102, and 11 are not.

Express n as a sum of only base-10 components, using the fewest base-10 components possible.

Return an array containing these base-10 components in descending order.
 */
