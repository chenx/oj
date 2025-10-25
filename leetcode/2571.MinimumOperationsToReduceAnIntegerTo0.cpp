// From https://algo.monster/liteproblems/2571
// Time: O(log n), Space: O(1)
class Solution {
public:
    int minOperations(int n) {
        int operations = 0;           // Total number of operations needed
        int consecutiveOnes = 0;       // Count of consecutive 1-bits encountered
      
        // Process each bit of n from right to left
        while (n > 0) {
            if ((n & 1) == 1) {
                // Current bit is 1: increment consecutive ones counter
                consecutiveOnes++;
            } else if (consecutiveOnes > 0) {
                // Current bit is 0 and we have accumulated consecutive 1s
                // Time to process the group of consecutive 1s we just finished counting
                operations++;
              
                // If we had exactly one 1-bit, we can clear it with one operation
                // If we had multiple consecutive 1s, we need to handle carry-over
                consecutiveOnes = (consecutiveOnes == 1) ? 0 : 1;
            }
          
            n >>= 1;  // Shift to examine the next bit
        }
      
        // Handle any remaining consecutive 1s after processing all bits
        if (consecutiveOnes == 1) {
            operations += 1;  // Single 1-bit requires one operation
        } else if (consecutiveOnes > 1) {
            operations += 2;  // Multiple consecutive 1s require two operations
        }
      
        return operations;
    }
};

/**
2571. Minimum Operations to Reduce an Integer to 0

You are given a positive integer n, you can do the following operation any number of times:

    Add or subtract a power of 2 from n.

Return the minimum number of operations to make n equal to 0.

A number x is power of 2 if x == 2i where i >= 0.
 */
