public class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        if (dividend == 0) return 0;
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        
        long a = dividend, b = divisor;
        
        boolean neg = (a > 0 && b < 0) || (a < 0 && b > 0);
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        int d = 0;
        while ((b << d) <= a) ++ d;
        -- d;
        
        int q = 0;
        while (d >= 0) {
            long tmp = b << d;
            if (tmp <= a) {
                a -= tmp;
                q += 1 << d;
            }
            -- d;
        }
        
        if (neg) q = -q;
        return q;        
    }
}

/**
Divide Two Integers
Difficulty: Medium

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT. 
 */
