// This works too.
class Solution3 {
public:
    int hammingWeight(uint32_t n) {
        int m = 0;
        
        for (int i = 0; i < 32; ++ i) {
            if (n & 1) ++ m;
            n >>= 1;
        }
        
        return m;
    }
};

// This works too. So input n is always positive.
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int ct = 0;
        while (n > 0) {
            n = n & (n-1);
            ++ ct;
        }
        
        return ct;        
    }
};

class Solution {
public:
    int hammingWeight(uint32_t m) {
        long long n = m;
        
        int ct = 0;
        while (n > 0) {
            n = n & (n-1);
            ++ ct;
        }
        
        return ct;        
    }
};


/**
Number of 1 Bits 

Write a function that takes an unsigned integer and returns the number of ’1' bits it has 
(also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
so the function should return 3.
 */
