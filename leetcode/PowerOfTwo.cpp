//
// Note: (n > 0) && (n & n-1 == 0) is incorrect, since it'll calculate n-1 == 0 first.
//
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n & n-1) == 0;
    }
};

/*
Power of Two

Given an integer, write a function to determine if it is a power of two. 
 */
