class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            mp.put(i, 1 + mp.getOrDefault(i, 0));
        }

        Queue<Integer> maxHeap = new PriorityQueue<>(
            (a, b) -> { return mp.get(a) - mp.get(b); } );

        for (int v : mp.keySet()) {
            maxHeap.add(v);
            if (maxHeap.size() > k) maxHeap.poll();
        }

        int[] ret = new int[maxHeap.size()];
        int count = 0;
        while (! maxHeap.isEmpty()) {
            ret[count ++] = maxHeap.poll();
        }
        return ret;
    }
}

/**
347. Top K Frequent Elements
Medium

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
 */
