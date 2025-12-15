// From: https://leetcode.com/problems/largest-divisible-subset/editorial/
// DP.
// Instead of keeping the largest divisible subset for each of the input elements, i.e. EDS(Xi​), we could 
// simply record its size, namely size(EDS(Xi​)). As a result, we reduce the space complexity from O(N2) to O(N).
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        vector<int> dp(n, 0);

        sort(nums.begin(), nums.end());
        int maxSubsetSize = -1, maxSubsetIndex = -1;

        /* Calculate the rest of EDS(X_i) */
        for (int i = 0; i < n; ++i) {
            int subsetSize = 0;

            // Find the size of the largest divisible subset.
            for (int k = 0; k < i; ++k) {
                if (nums[i] % nums[k] == 0 && subsetSize < dp[k]) {
                    subsetSize = dp[k];
                }
            }

            // Extend the found subset with the element itself.
            dp[i] = subsetSize + 1;

            // We reuse this loop to obtain the largest subset size
            //   in order to prepare for the reconstruction of subset.
            if (maxSubsetSize < dp[i]) {
                maxSubsetSize = dp[i];
                maxSubsetIndex = i;
            }
        }

        /* Reconstruct the largest divisible subset  */
        vector<int> subset;
        int currSize = maxSubsetSize, currTail = nums[maxSubsetIndex];
        for (int i = maxSubsetIndex; i >= 0; --i) {
            if (currSize == 0) break;

            if (currTail % nums[i] == 0 && currSize == dp[i]) {
                subset.push_back(nums[i]);
                currTail = nums[i];
                currSize -= 1;
            }
        }

        return subset;
    }
};


/**
368. Largest Divisible Subset
Medium

Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
(answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 */
