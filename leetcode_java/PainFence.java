// Need two one-dimensional array dp1 and dp2, dp1[i] means the number of solutions 
// when the color of last two fences (whose indexes are i-1,i-2) are same. dp2[i] 
// means the number of solutions when the color of last two fences are different.
// So
// dp1[i]=dp2[i-1],
// dp2[i]=(k-1)(dp1[i-1]+dp2[i-1]) =(k-1)(dp2[i-2]+dp2[i-1])
// Final result is dp1[n-1]+dp2[n-1];
// In the code, variable a,c mean the last two items of dp1, variable b,d mean the 
// last two items of dp2, and c could be eliminated.
//
// From: 
// https://leetcode.com/discuss/56146/dynamic-programming-c-o-n-time-o-1-space-0ms
// http://www.cnblogs.com/jcliBlogger/p/4783051.html
//
public class Solution {
    public int numWays(int n, int k) {
        if (n <= 1 || k==0) return n*k;
        int a = k, b = k * (k-1), c = 0, d = 0;
        for (int i = 2; i < n; ++ i){
            d = (k-1) * (a+b);
            a = b;
            b = d;
        }
        return a + b;
    }
};

// rewrite it a little bit: s means same and stands for the last element of your dp1; 
// d means different, d1 and d2 stands for the last two elements of your dp2.
// In each loop, dp1[i] = dp2[i - 1] turns into s = d2 and 
// dp2[i] = (k - 1) * (dp2[i - 2] + dp2[i - 1]) becomes d2 = (k - 1) * (d1 + d2). 
// Moreover, d1 needs to be set to the old d2, which is recorded in s. So we have d1 = s.
// Finally, the return value dp1[n - 1] + dp2[n - 1] is just s + d2.
// The code is as follows.

public class Solution2 {
    public int numWays(int n, int k) {
    int numWays(int n, int k) {
        if (n < 2 || k == 0) return n * k; 
        int s = k, d1 = k, d2 = k * (k - 1); 
        for (int i = 2; i < n; i++) {
            s = d2;
            d2 = (k - 1) * (d1 + d2);
            d1 = s;
        }
        return s + d2;
    }
};

/**
Paint Fence

There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent 
fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
 */
