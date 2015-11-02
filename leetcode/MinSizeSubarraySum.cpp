class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int begin = 0, end = 1;
        int sum = nums[0];
        int minLen = 0;
        while (begin < len && end < len) {
            if (sum < s) {
                sum += nums[end ++];
            }
            
            while (sum >= s) {
                if (minLen == 0) minLen = end - begin;
                else minLen = min(minLen, end - begin);
                sum -= nums[begin ++];
            }
        }
        
        return minLen;        
    }
};

/**
Minimum Size Subarray Sum
Difficulty: Medium

Given an array of n positive integers and a positive integer s, 
find the minimal length of a subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution 
of which the time complexity is O(n log n).

 */
