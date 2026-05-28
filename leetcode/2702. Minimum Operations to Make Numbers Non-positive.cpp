// From: https://algo.monster/liteproblems/2702
// Time Complexity: O(n * log(max(nums)))
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        int firstTrueIndex = -1;

        // Feasible function to check if 'time' operations are sufficient
        auto feasible = [&](int time) {
            long long operationsNeeded = 0;

            for (int num : nums) {
                if (num > 1LL * time * y) {
                    long long remaining = num - 1LL * time * y;
                    // Ceiling division: (a + b - 1) / b
                    operationsNeeded += (remaining + x - y - 1) / (x - y);
                }
            }

            return operationsNeeded <= time;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (feasible(mid)) {
                firstTrueIndex = mid;
                right = mid - 1;  // Try to find smaller valid value
            } else {
                left = mid + 1;
            }
        }

        return firstTrueIndex;
    }
};


/**
2702. Minimum Operations to Make Numbers Non-positive
Solved
Hard
Topics
conpanies iconCompanies
Hint

You are given a 0-indexed integer array nums and two integers x and y. In one operation, you must choose an index i 
such that 0 <= i < nums.length and perform the following:

    Decrement nums[i] by x.
    Decrement values by y at all indices except the ith one.

Return the minimum number of operations to make all the integers in nums less than or equal to zero.

 

Example 1:

Input: nums = [3,4,1,7,6], x = 4, y = 2
Output: 3
Explanation: You will need three operations. One of the optimal sequence of operations is:
Operation 1: Choose i = 3. Then, nums = [1,2,-1,3,4]. 
Operation 2: Choose i = 3. Then, nums = [-1,0,-3,-1,2].
Operation 3: Choose i = 4. Then, nums = [-3,-2,-5,-3,-2].
Now, all the numbers in nums are non-positive. Therefore, we return 3.

Example 2:

Input: nums = [1,2,1], x = 2, y = 1
Output: 1
Explanation: We can perform the operation once on i = 1. Then, nums becomes [0,0,0]. All the positive numbers are 
removed, and therefore, we return 1.
 */
