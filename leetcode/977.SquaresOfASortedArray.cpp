// O(n) Time
// O(n) space.
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        vector<int> result(n);

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[-- n] = nums[left] * nums[left];
                ++ left;
            } else {
                result[-- n] = nums[right] * nums[right];
                -- right;
            }
        }
        return result;
    }
};


// O(n log(n)) Time.
// O(n) space.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {
            result.push_back(num * num);
        }
        sort(result.begin(), result.end());
        return result;
    }
};


/**
977. Squares of a Sorted Array
Easy

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 */
