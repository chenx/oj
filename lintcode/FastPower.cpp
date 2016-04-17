class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        //if (a == 1) return a % b;
        
        long long R = 1, F = a;
        while (n > 0) {
            if (n & 1) R = (R * F) % b;
            F = (F * F) % b;  // note this!
            n = n >> 1;
        }
        
        return R % b;
    }
};


/**
Fast Power

Calculate the an % b where a, b and n are all 32bit integers.
Have you met this question in a real interview?
Example

For 231 % 3 = 2

For 1001000 % 1000 = 0
Challenge

O(logn)

 */
