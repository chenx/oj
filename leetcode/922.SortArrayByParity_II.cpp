// From: https://leetcode.com/problems/sort-array-by-parity-ii/editorial/
// One passes.
// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddPos = 1; // position of odd numbers.
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2 == 1) {
                while (nums[oddPos] % 2 == 1) oddPos += 2;

                swap(nums[i], nums[oddPos]);
            }
        }
        return nums;
    }
};


// From: https://leetcode.com/problems/sort-array-by-parity-ii/editorial/
// Two passes.
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int t = 0;
        for (int x: nums) {
            if (x % 2 == 0) {
                ans[t] = x;
                t += 2;
            }
        }

        t = 1;
        for (int x: nums) {
            if (x % 2 == 1) {
                ans[t] = x;
                t += 2;
            }
        }

        return ans;
    }
};


/**
922. Sort Array By Parity II
Easy

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

 

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Example 2:

Input: nums = [2,3]
Output: [2,3]
 */
