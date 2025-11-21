// From: https://leetcode.com/problems/total-hamming-distance/editorial/
// Loop over the bits!
// Time complexity: O(n⋅log​V)≃O(n).
// Space complexity: O(log​V)→O(1) extra space
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.empty()) return 0;

        int ans = 0, n = nums.size();
        vector<int> cnt(32, 0);         // count of elements with a particular bit ON

        for (auto num : nums) {         // loop over every element
            int i = 0;
            while (num > 0) {           // check every bit
                cnt[i] += (num & 0x1);
                num >>= 1;
                i++;
            }
        }

        for (auto& k : cnt) {           // loop over every bit count
            ans += k * (n - k);
        }

        return ans;
    }
};

/**
477. Total Hamming Distance
Medium

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.
 */
