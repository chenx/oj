// Just enumerate.
// See https://leetcode.com/problems/next-greater-numerically-balanced-number/editorial/
class Solution {
public:
    int nextBeautifulNumber(int n) {
        while (! isBalanced(++ n)) ;
        return n;
    }

    bool isBalanced(int n) {
        map<int, int> counter; // <digit, count>
        while (n > 0) {
            ++ counter[n % 10];
            n /= 10;
        }

        for (const auto [key, val] : counter) {
            if (key != val) return false;
        }
        return true;
    }
};

/**
2048. Next Greater Numerically Balanced Number
Medium

An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.
 */
