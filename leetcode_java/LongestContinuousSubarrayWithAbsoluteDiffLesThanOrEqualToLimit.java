class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> minQ = new LinkedList<>();
        Deque<Integer> maxQ = new LinkedList<>();
        int left = 0, maxLen = 0;

        for (int i = 0; i < nums.length; ++ i) {
            while (!maxQ.isEmpty() && maxQ.peekLast() < nums[i]) {
                maxQ.pollLast();
            }
            maxQ.add(nums[i]);
            while (!minQ.isEmpty() && minQ.peekLast() > nums[i]) {
                minQ.pollLast();  // pop_back
            }
            minQ.add(nums[i]);  // push_back

            while (maxQ.peekFirst() - minQ.peekFirst() > limit) {
                if (maxQ.peekFirst() == nums[left]) maxQ.pollFirst();
                if (minQ.peekFirst() == nums[left]) minQ.pollFirst();
                ++ left;
            }
            maxLen = Math.max(maxLen, i - left + 1);
        }
        return maxLen;
    }
}

/**
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that 
the absolute difference between any two elements of this subarray is less than or equal to limit.
 */
