/**
 * This works.
 * 
 * Note BigInteger is not supported by leetcode OJ.
 * BigInteger can be used this way:
 * 
 * BigInteger sum = BigInteger.valueOf(0);
 * for(int i = 2; i < 5000; i++) {
 *     if (isPrim(i)) {
 *         sum.add(BigInteger.valueOf(i));
 *     }
 * }
 */
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ct = 0;
        
        while (n != 0) {
            n = n & (n-1);
            ++ ct;
        }
        
        return ct;
    }
}

/**
Number of 1 Bits 

Write a function that takes an unsigned integer and returns the number of ’1' bits it has 
(also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
so the function should return 3.
 */
