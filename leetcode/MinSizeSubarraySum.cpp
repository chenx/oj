// Works. Tested.
class Solution3 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int begin = 0, end = 0, sum = 0, minLen = n + 1;
        while (end < n) {
            if (sum < s) {
                sum += nums[end ++];
            }
            
            while (sum >= s) {
                minLen = min(minLen, end - begin);
                sum -= nums[begin ++];
            }
        }
        
        return minLen == n + 1 ? 0 : minLen;        
    }
};

// Works too. By: XC. O(n).
class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int i = 0, j = 0, sum = nums[0], minLen = INT_MAX;
        
        while (true) {
            if (sum < s) {
                if (j == nums.size() - 1) break;
                else sum += nums[++ j];
            }
            else {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i ++];
            }
        }

        if (minLen == INT_MAX) minLen = 0;
        return minLen;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int begin = 0, end = 1;
        int sum = nums[0];
        int minLen = 0;
        while (end < len) {
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
