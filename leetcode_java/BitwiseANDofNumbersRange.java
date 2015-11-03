// This works too. Best so far.
// Idea is: It's can be reduced to find the same prefix of the numbers in this range. 
// From: https://leetcode.com/discuss/53646/simple-and-easy-to-understand-java-solution
public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int diffBits = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            diffBits ++;
        }
        return n << diffBits;
    }
}

// This works too.
// From: https://leetcode.com/discuss/56801/my-simple-recursive-solution-c-68ms
// If we only consider the last bit of some successive numbers, 
// the last bit of result of bitwise AND must be 0. So I recursive 
// the problem into judge the last bit of range numbers, m and n. 
// If m == n, return m; else if m != n, put a 0 after the result 
// of rangeBitwiseAnd(m >> 1, n >> 1);
public class Solution3 {
    public int rangeBitwiseAnd(int m, int n) {
        if (m == n){
            return m ;
        }
        int res = rangeBitwiseAnd(m >> 1, n >> 1);
        return res << 1;
    }
}

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
