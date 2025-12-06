// See: https://leetcode.com/problems/sort-transformed-array/editorial/
// 2 pointers.
// Time: O(n)
// Space: O(1) // not consider output size of result.
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; ++ i) {
            nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        }

        int left = 0, right = n - 1;
        if (a < 0) {
            int p = 0;
            while (left <= right) {
                if (nums[left] < nums[right]) result[p ++] = nums[left ++];
                else result[p ++] = nums[right --];
            }
        } else { // a > 0
            int p = n-1;
            while (left <= right) {
                if (nums[left] > nums[right]) result[p --] = nums[left ++];
                else result[p --] = nums[right --];
            }
        }

        return result;
    }
};


// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (int i = 0; i < nums.size(); ++ i) {
            nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};


/**
360. Sort Transformed Array
Medium

Given a sorted integer array nums and three integers a, b and c, apply a quadratic function of the 
form f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array in a sorted order.

 

Example 1:

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]

Example 2:

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
 */
