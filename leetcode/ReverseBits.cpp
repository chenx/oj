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
Reverse Bits 

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it? 
(A: could do table lookup: store all 8-bits inversion; 32 bits is combination of 4 8-bits sections.)

Related problem: Reverse Integer
 */
