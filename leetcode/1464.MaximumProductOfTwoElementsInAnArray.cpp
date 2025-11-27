// See: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/editorial/
// O(n) time.
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int v1 = INT_MIN, v2 = INT_MIN;

        for (int num : nums) {
            if (num > v1) { 
                v2 = v1;
                v1 = num;
            }
            else if (num > v2) {
                v2 = num;
            }
        }
        return (v1 - 1) * (v2 - 1);
    }
};

// Sort.
// O(nlogn) time.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums[nums.size() - 1];
        int y = nums[nums.size() - 2];
        return (x - 1) * (y - 1);
    }
};

/**
1464. Maximum Product of Two Elements in an Array
Easy

Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).

 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

Example 3:

Input: nums = [3,7]
Output: 12
 */
