// One scan.
// See: https://leetcode.com/problems/maximum-product-of-three-numbers/editorial/
// Time: O(n)
class Solution2 {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int num : nums) {
            if (num < min1) min2 = min1, min1 = num;
            else if (num < min2) min2 = num;

            if (num > max1) max3 = max2, max2 = max1, max1 = num;
            else if (num > max2) max3 = max2, max2 = num;
            else if (num > max3) max3 = num;
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};


// Brute force. 
// Time: O(n^3)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int result = INT_MIN, n = nums.size();
        for (int i = 0; i < n-2; ++ i) {
            for (int j = i+1; j < n-1; ++ j) {
                int prod = nums[i] * nums[j];
                for (int k = j+1; k < n; ++ k) {
                    result = max(result, prod * nums[k]);
                }
            }
        }
        return result;
    }
};


/**
628. Maximum Product of Three Numbers
Attempted
Easy
Topics
conpanies iconCompanies

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6

Example 2:

Input: nums = [1,2,3,4]
Output: 24

Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 */
