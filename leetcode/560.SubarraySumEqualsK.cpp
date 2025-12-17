// Space O(n), Time O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        map<int, int> mp;
        mp[0] = 1; // 1 subarray that sums to 0. 1, NOT -1 !!!
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.contains(sum - k)) {
                count += mp[sum - k];
            }
            ++ mp[sum];
        }
        return count;
    }
};

/**
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
 */
