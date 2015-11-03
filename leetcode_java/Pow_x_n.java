public class Solution {
    public double myPow(double x, int n) {
        if (n == 0) return Math.abs(x) < 0.000001 ? 0 : 1;
        boolean neg = (n < 0); // must use "()" here.
        if (neg) n = -n;
        
        double R = 1.0, F = x;
        while (n > 0) {
            if ((n & 1) != 0) R *= F; // must use "()" around "n & 1" here.
            n = n >> 1; // n >>= 1;
            if (n == 0) break;
            F *= F;
        }
        
        return neg ? 1 / R : R;
    }
}

/**
Pow(x, n)
Difficulty: Medium

Implement pow(x, n). 
 */
