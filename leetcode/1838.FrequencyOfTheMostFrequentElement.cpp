// From: https://leetcode.com/problems/frequency-of-the-most-frequent-element/editorial/
// Time: O(nlog(n)). Despite the while loop, each iteration of the for loop is amortized O(1). 
//   The while loop only runs O(n) times across all iterations. This is because each iteration of the while loop increments left
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, ans = 0;
        long curr = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            long target = nums[i];
            curr += target;
            
            while ((i - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            
            ans = max(ans, i - left + 1);
        }
        
        return ans;
    }
};

/**
1838. Frequency of the Most Frequent Element
Medium

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums 
and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
 */
