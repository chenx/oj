public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> Q = new LinkedList<Integer>();

        int i, len = nums.length, ct = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        for (i = 0; i < k; ++ i) {
            while(! Q.isEmpty() && nums[Q.peekLast()] <= nums[i]) Q.removeLast();
            Q.addLast(i);
        }
        
        for (i = k; i < len; ++ i) {
            ans.add(nums[Q.peekFirst()]);
            while(! Q.isEmpty() && nums[Q.peekLast()] <= nums[i]) Q.removeLast();
            while(! Q.isEmpty() && Q.peekFirst() <= i - k) Q.removeFirst();
            Q.addLast(i);
        }
        if (! Q.isEmpty()) ans.add(nums[Q.peekFirst()]);
        
        // if use ans as int[], will have error on size for edge case.
        int[] arr = new int[ans.size()];
        for (i = 0, len = ans.size(); i < len; ++ i) {
            arr[i] = ans.get(i);
        }
        
        return arr;
    }
}

/**
Sliding Window Maximum
Difficulty: Hard

Given an array nums, there is a sliding window of size k 
which is moving from the very left of the array to the 
very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

    How about using a data structure such as deque (double-ended queue)?
    The queue size need not be the same as the window’s size.
    Remove redundant elements and the queue should store only elements that 
    need to be considered.

 */
