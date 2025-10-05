class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() < 1) return 0;
        deque<int> minQ, maxQ;
        int left = 0, maxLen = 0, i;

        for (i = 0; i < nums.size(); ++ i) {
            while (!maxQ.empty() && maxQ.back() < nums[i]) {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[i]);
            while (!minQ.empty() && minQ.back() > nums[i]) {
                minQ.pop_back();
            }
            minQ.push_back(nums[i]);

            while (maxQ.front() - minQ.front() > limit) {
                if (maxQ.front() == nums[left]) maxQ.pop_front();
                if (minQ.front() == nums[left]) minQ.pop_front();
                ++ left;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};

/**
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that 
the absolute difference between any two elements of this subarray is less than or equal to limit.
 */
