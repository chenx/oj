// Use len = std::gcd(a, b).
// Time / Space: O(gcd(a, b))
class Solution2 {
public:
    int commonFactors(int a, int b) {
        set<int> factors;
        for (int i = 1, len = std::gcd(a, b); i <= len; ++ i) {
            if (a % i == 0) {
                factors.insert(i);
            }
        }

        int numFactors = 0;
        for (int f : factors) {
            if (b % f == 0) ++ numFactors;
        }
        return numFactors;
    }
};


class Solution {
public:
    int commonFactors(int a, int b) {
        set<int> factors;
        for (int i = 1; i <= a/2; ++ i) {
            if (a % i == 0) {
                factors.insert(i);
            }
        }
        factors.insert(a);

        int numFactors = 0;
        for (int f : factors) {
            if (b % f == 0) ++ numFactors;
        }
        return numFactors;
    }
};


/**
2427. Number of Common Factors
Easy


Given two positive integers a and b, return the number of common factors of a and b.

An integer x is a common factor of a and b if x divides both a and b.

 

Example 1:

Input: a = 12, b = 6
Output: 4
Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.

Example 2:

Input: a = 25, b = 30
Output: 2
Explanation: The common factors of 25 and 30 are 1, 5.
 */
