// From: https://algo.monster/liteproblems/3411

class Solution {
public:
    int maxLength(vector<int>& nums) {
        // Find the maximum element and LCM of all elements in the array
        // These will be used to establish an upper bound for pruning
        int maxElement = 0;
        int overallLcm = 1;
        for (int num : nums) {
            maxElement = max(maxElement, num);
            overallLcm = lcm(overallLcm, num);
        }
      
        // Calculate the maximum possible product as a pruning threshold
        // If any subarray's product exceeds this, it cannot satisfy the condition
        long long maxProduct = (long long)overallLcm * maxElement;
      
        int n = nums.size();
        int maxSubarrayLength = 0;
      
        // Try all possible subarrays starting from index i
        for (int i = 0; i < n; ++i) {
            long long product = 1;  // Product of current subarray
            long long gcdValue = 0;  // GCD of current subarray
            long long lcmValue = 1;  // LCM of current subarray
          
            // Extend the subarray ending at index j
            for (int j = i; j < n; ++j) {
                // Update product, GCD, and LCM for the subarray [i, j]
                product *= nums[j];
                gcdValue = gcd(gcdValue, nums[j]);
                lcmValue = lcm(lcmValue, nums[j]);
              
                // Check if the current subarray satisfies the condition:
                // product of elements = GCD * LCM
                if (product == gcdValue * lcmValue) {
                    maxSubarrayLength = max(maxSubarrayLength, j - i + 1);
                }
              
                // Prune: if product exceeds the maximum threshold, 
                // no need to extend further from this starting point
                if (product > maxProduct) {
                    break;
                }
            }
        }
      
        return maxSubarrayLength;
    }
};


/**
3411. Maximum Subarray With Equal Products
Easy

You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

    prod(arr) is the product of all elements of arr.
    gcd(arr) is the 

of all elements of arr.
lcm(arr) is the

    of all elements of arr.

Return the length of the longest product equivalent

of nums.

 

Example 1:

Input: nums = [1,2,1,2,1,1,1]

Output: 5

Explanation: 

The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, 
gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

Example 2:

Input: nums = [2,3,4,5,6]

Output: 3

Explanation: 

The longest product equivalent subarray is [3, 4, 5].

Example 3:

Input: nums = [1,2,3,1,4,5,1]

Output: 5
 */
