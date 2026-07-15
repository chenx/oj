class Solution3 {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bitCount(32);
        for (int i = 0; i < 32; ++ i) {
            int mask = 1 << i;
            for (int num : nums) {
                if (num & mask) {
                    ++ bitCount[i];
                }
            }
        }

        int sum = 0, n = nums.size();
        for (int ct : bitCount) {
            sum += ct * (n - ct);
        }
        return sum;
    }
};

class Solution2 {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> count(32, 0);

        for (int i = 0; i < 32; ++ i) {
            int mask = 1 << i;
            for (int num : nums) {
                if (num & mask) count[i] ++;
            }
        }

        int sum = 0, n = nums.size();
        for (int ct : count) {
            sum += ct * (n - ct);
        }
        return sum;
    }
};

// From: https://leetcode.com/problems/total-hamming-distance/editorial/
// Loop over the bits!
// Count how many bits are On at each bit. 
// Say k numbers has the on, then n-k numbers has the bit off, the total hamming dist is k(n-k).
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
