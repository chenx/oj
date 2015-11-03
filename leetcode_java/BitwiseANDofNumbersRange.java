// This works. 
// From: https://leetcode.com/discuss/57971/c-64ms-2-simple-solutions 
public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if((m ^ n) > m) return 0;   //n has more num of digits than m, includeing m = 0
        if(m == n) return m;        //if m == n

        int result = m;
        for(long i = m + 1; i <= n; i++)
            result &= i;
        return result;       
    }
}

// This times out for input such as (0, 2147483647).
class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x = m;
        for (++ m; m <= n; ++ m) x &= m;
        return x;     
    }
};


/**
Bitwise AND of Numbers Range
Difficulty: Medium

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND 
of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4. 
 */
