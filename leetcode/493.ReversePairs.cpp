// From: https://leetcode.com/problems/reverse-pairs/editorial/
// Time complexity: O(nlogn)
// Space complexity: O(n). Additional space for BITS array 
class Solution {
private:
    void update(vector<int>& BIT, int index, int val) {
        while (index > 0) {
            BIT[index] += val;
            index -= index & (-index);
        }
    }

    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index < BIT.size()) {
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy(nums);

        sort(copy.begin(), copy.end());

        vector<int> BITS(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += query(BITS, lower_bound(copy.begin(), copy.end(), 2LL * nums[i] + 1) - copy.begin() + 1);
            update(BITS, lower_bound(copy.begin(), copy.end(), nums[i]) - copy.begin() + 1, 1);
        }
        return count;
    }
};


/**
493. Reverse Pairs
Hard

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 */
