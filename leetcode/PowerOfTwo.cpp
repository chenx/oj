// Works too.
class Solution6 {
    const static int m;
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && m % n == 0;
    }
};
const int Solution::m = 1 << 31;


// Works too! This is good.
class Solution5 {
    const static int m = 1 << 31;
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && m % n == 0;
    }
};


// Works too.
class Solution4 {
    const int m;
public:
    Solution() : m (1 << 31) { }
    
    bool isPowerOfTwo(int n) {
        return n > 0 && m % n == 0;
    }
};


// Works too.
class Solution3 {
    int m;
public:
    Solution() { m = 1 << 31; }
    
    bool isPowerOfTwo(int n) {
        return n > 0 && m % n == 0;
    }
};


// Works too.
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ! (n & (n-1));
    }
};


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
