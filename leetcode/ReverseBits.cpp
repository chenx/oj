// This works.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; ++ i) {
            m = (m << 1) + (n & 1);  // need to have the parentheses here due to operator precedence. 
            n = n >> 1;
        }
        
        return m;
    }
};

/**
 * Question: If this is called many times, how to optimize?
 * Answer: table lookup:
 * Construct a rev[256] for 0-255.
 * Each time get the reverse of 8 bits from rev, only need 4 rounds.
 * See code below:
 *  uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        vector<int> rev(256);
        for (int i = 0; i < 4; ++ i) {
            m = (m << 8) + rev[n & 0xff];
            n >>= 8;
        }
    }
 */

/**
Reverse Bits 

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it? 
(A: could do table lookup: store all 8-bits inversion; 32 bits is combination of 4 8-bits sections.)

Related problem: Reverse Integer
 */
