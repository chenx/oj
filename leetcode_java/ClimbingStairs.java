/**
 * Climbing Stairs
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
 */
public class Solution {
    public int climbStairs(int n) {
        if (n <= 2) return n;
        
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++ i) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        
        return b;
    }
}

// This works too. But above may be better.
public class Solution2 {
    public int climbStairs(int n) {
        if (n <= 2) return n;
        
        int a = 1, b = 2, x = 0;
        for (int i = 3; i <= n; ++ i) {
            x = a + b;
            a = b;
            b = x;
        }
        
        return x;
    }
}
