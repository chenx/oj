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
