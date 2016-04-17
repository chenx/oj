class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask = 0;
        for (int k = j - i + 1; k > 0; -- k) mask = (mask << 1) + 1;
        for (; i > 0; -- i) {
            mask <<= 1;
            m <<= 1;
        }
        
        mask = ~ mask;
        n = n & mask; // set i...j to all 0s
        n = n | m;    // set i...j to m
        return n;
    }
};


/**
Update Bits

    Description
    Notes
    Testcase
    Judge

Given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to set all bits between i and j in N equal to M (e g , 
M becomes a substring of N located at i and starting at j)

Notice

In the function, the numbers N and M will given in decimal, you 
should also return a decimal number.
Clarification

You can assume that the bits j through i have enough space to 
fit all of M. That is, if M=10011， you can assume that there are 
at least 5 bits between j and i. You would not, for example, have 
j=3 and i=2, because M could not fully fit between bit 3 and bit 2.

Example

Given N=(10000000000)2, M=(10101)2, i=2, j=6

return N=(10001010100)2
Challenge

Minimum number of operations?

 */
