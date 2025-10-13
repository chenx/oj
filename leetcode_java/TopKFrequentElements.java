class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            mp.put(i, 1 + mp.getOrDefault(i, 0));
        }

        Queue<Integer> minHeap = new PriorityQueue<>(
            (a, b) -> { return mp.get(a) - mp.get(b); } );

        for (int v : mp.keySet()) {
            minHeap.add(v);
            if (minHeap.size() > k) minHeap.poll();
        }
        // Or:
        // for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        //     minHeap.add(entry.getKey());
        //     if (minHeap.size() > k) minHeap.poll();
        // }

        int[] ret = new int[k];
        int count = 0;
        while (! minHeap.isEmpty()) {
            ret[count ++] = minHeap.poll();
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
