class Solution {
    public int minOperations(int n) {
        int operations = 0, consecutiveOnes = 0;

        while (n > 0) {
            if ((n & 1) == 1) {
                ++ consecutiveOnes;
            } else if (consecutiveOnes > 0) {
                ++ operations;
                consecutiveOnes = consecutiveOnes == 1 ? 0 : 1;
            }
            n >>= 1;
        }

        if (consecutiveOnes == 1) operations += 1;
        else if (consecutiveOnes > 1) operations += 2;

        return operations;
    }
}

/**
2571. Minimum Operations to Reduce an Integer to 0
Medium

You are given a positive integer n, you can do the following operation any number of times:

    Add or subtract a power of 2 from n.

Return the minimum number of operations to make n equal to 0.

A number x is power of 2 if x == 2i where i >= 0.
 */
