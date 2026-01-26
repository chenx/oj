class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        len1, len2 = len(nums1), len(nums2)

        pairs = []
        minHeap = []
        heapq.heappush(minHeap, (nums1[0] + nums2[0], [0, 0]))
        # used = set((0, 0))  # This will be {0} instead of {{0,0}}
        used = set()
        used.add((0, 0))

        while len(minHeap) > 0 and k > 0:
            k -= 1
            sum, [x, y] = heapq.heappop(minHeap)
            pairs.append([nums1[x], nums2[y]])

            if x+1 < len1 and not (x+1, y) in used:
                used.add((x+1, y))
                heapq.heappush(minHeap, (nums1[x+1] + nums2[y], [x+1, y]))
            if y+1 < len2 and not (x, y+1) in used:
                used.add((x, y+1))
                heapq.heappush(minHeap, (nums1[x] + nums2[y+1], [x, y+1]))
            
        return pairs



/**
373. Find K Pairs with Smallest Sums
Medium

You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/
