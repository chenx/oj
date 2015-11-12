// both methods work.
public class Solution {
    public int mySqrt(int x) {
        if (x <= 0) return 0;
        
        double r0 = 0, r = x;
        while (Math.abs(r - r0) > 0.000001) {
            r0 = r;
            r = (r + x/r) / 2.0;
        }
        
        return (int) r;
    }
    
    public int mySqrt2(int x) {
        if (x <= 0) return 0;
        
        double L = 0, R = x;
        while (Math.abs(R - L) > 0.000001) {
            double M = L + (R - L)/2;
            if (M * M > x) R = M;
            else L = M;
        }
        
        return (int) R;
    }
}


/**
Sqrt(x)
Difficulty: Medium

Implement int sqrt(int x).

Compute and return the square root of x.
 */
