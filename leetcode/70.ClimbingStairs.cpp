class Solution3 {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++ i) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};

// This works too. 10/26/2014
class Solution2 {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++ i) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
    
    // This works too, and most simple.
    int climbStairs2(int n) {
        if (n <= 1) return 1;
        
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++ i) {
            b = a + b;
            a = b - a;
        }
        return b;
    }    
};

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 1;
        if (n == 2) return 2;
        
        int f1 = 1;
        int f2 = 2;
        int f;
        for (int i = 3; i <= n; i ++) {
            f = f1 + f2; // f1, f2, f
            f1 = f2;
            f2 = f;
        }
        
        return f;
    }
};



/**
70. Climbing Stairs
Easy

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 */
