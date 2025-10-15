// See https://algo.monster/liteproblems/3229
// O(n) time. O(1) space.
typedef long long ll;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        // Initialize result with the absolute difference at the first position
        // This represents the operations needed to transform nums[0] to target[0]
        ll totalOperations = abs(target[0] - nums[0]);
      
        // Process each subsequent element
        for (int i = 1; i < nums.size(); ++i) {
            // Calculate the difference at current position
            long currentDiff = target[i] - nums[i];
          
            // Calculate the difference at previous position
            long previousDiff = target[i - 1] - nums[i - 1];
          
            // Check if both differences have the same sign (both positive or both negative)
            if (currentDiff * previousDiff > 0) {
                // Same sign: we can potentially reuse operations from the previous position
                // Only add the additional operations needed beyond what was already done
                ll additionalOps = abs(currentDiff) - abs(previousDiff);
                if (additionalOps > 0) {
                    totalOperations += additionalOps;
                }
            } else {
                // Different signs or one is zero: we need completely new operations
                // Add the full absolute difference for the current position
                totalOperations += abs(currentDiff);
            }
        }
      
        return totalOperations;
    }
};

/**
3229. Minimum Operations to Make Array Equal to Target
Hard

You are given two positive integer arrays nums and target, of the same length.

In a single operation, you can select any subarray of nums and increment each element within that subarray 
by 1 or decrement each element within that subarray by 1.

Return the minimum number of operations required to make nums equal to the array target.
 */
