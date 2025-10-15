// Same as Solution, but use 2 cycles to avoid confusion of i % n.
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> stack;

        for (int k = 0; k < 2; ++ k) {
            for (int i = n - 1; i >= 0; --i) {
                while (!stack.empty() && nums[stack.top()] <= nums[i]) {
                    stack.pop();
                }
                res[i] = stack.empty() ? -1 : nums[stack.top()];
                stack.push(i);
            }
        }
        return res;
    }
};

// From: https://leetcode.com/problems/next-greater-element-ii/editorial
// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> stack;
        for (int i = 2 * n - 1; i >= 0; --i) {
            while (!stack.empty() && nums[stack.top()] <= nums[i % n]) {
                stack.pop();
            }
            res[i % n] = stack.empty() ? -1 : nums[stack.top()];
            stack.push(i % n);
        }
        return res;
    }
};

/**
503. Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in 
the array, which means you could search circularly to find its next greater number. If it doesn't 
exist, return -1 for this number.
 */
