// From: https://leetcode.com/problems/count-number-of-nice-subarrays/editorial
// Time: O(n)
// Space: O(1)
class Solution2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    
    // Number of subarrays with sum at most k for an array with non-negative elements.
    int atMost(vector<int>& nums, int k) {
        int n = nums.size(), oddCount = 0, niceCount = 0;

        for (int i = 0, begin = 0; i < n; ++ i) {
            if (nums[i] & 1) {
                ++ oddCount;
            }

            while (oddCount > k) {
                if (nums[begin] & 1) -- oddCount;
                ++ begin;
            }
            niceCount += i - begin + 1;
        }
        return niceCount;
    }
};

// From: https://leetcode.com/problems/count-number-of-nice-subarrays/editorial
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefixSum = 0, niceCount = 0;
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1;

        for (int i = 0; i < nums.size(); ++ i) {
            prefixSum += nums[i] % 2;
            if (prefixSumMap.contains(prefixSum - k)) {
                niceCount += prefixSumMap[prefixSum - k];
            }
            prefixSumMap[prefixSum] ++;
        }
        return niceCount;
    }
};

/**
1248. Count Number of Nice Subarrays
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 */
