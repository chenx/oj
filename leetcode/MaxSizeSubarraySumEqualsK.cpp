// Works.
// Explanation: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/editorial/ 
class Solution2 {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> pos; // <int, index in nums>
        pos[0] = -1;
        int maxLen = 0;
        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); ++ i) {
            prefixSum += nums[i];
            if (! pos.contains(prefixSum)) pos[prefixSum] = i;
            if (pos.contains(prefixSum - k)) {
                maxLen = max(maxLen, i - pos[prefixSum - k]);
            }
        }
        return maxLen;
    }
};

// Works. Tested. O(n).
// From: https://leetcode.com/discuss/84037/c-easy-understand-solution-with-comment
// O(n) complexity.
// Core idea: for the same cumulative sum value, we
// only keep it's first appearance, so at last the
// subarray is guaranteed to be the longest.
// Also, note the brilliant idea of using the sum value
// as the key of the map.
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;  // for the case m[sum] = k.
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (!m.count(sum)) m[sum] = i;
            //if (m.find(sum) == m.end()) m[sum] = i;
            if (m.count(sum - k)) maxLen = max(maxLen, i - m[sum - k]);
            //if (m.find(sum - k) != m.end()) maxLen = max(maxLen, i - m[sum - k]);
        }
        return maxLen;
    }
};

/**
Maximum Size Subarray Sum Equals k
Difficulty: Easy

Given an array nums and a target value k, find the maximum length 
of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
 */
