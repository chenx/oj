// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int product = 1, count = 0;

        for (int i = 0, left = 0; i < nums.length; ++ i) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[left];
                ++ left;
            }
            count += i - left + 1;
        }
        return count;
    }
}

/**
713. Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of contiguous subarrays 
where the product of all the elements in the subarray is strictly less than k.
 */
