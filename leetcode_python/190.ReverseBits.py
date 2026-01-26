class Solution:
    def reverseBits(self, n: int) -> int:
        m = 0
        for i in range(32):
            m = (m << 1) + (n & 1)
            n >>= 1
        return m

/**
190. Reverse Bits
Easy

Reverse bits of a given 32 bits signed integer.
 */
