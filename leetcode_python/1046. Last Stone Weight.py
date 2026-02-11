import heapq

# Time: O(nlogn), Space: O(n), n = len(stones)
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # use maxHeap.
        maxHeap = []
        for stone in stones:
            heapq.heappush(maxHeap, (-stone, stone))

        while len(maxHeap) > 1:
            a, b = heapq.heappop(maxHeap)
            c, d = heapq.heappop(maxHeap)
            diff = abs(d - b)
            if diff > 0:
                heapq.heappush(maxHeap, (-diff, diff))
        
        # if input is [1, 1], then maxHeap size becomes 0 after first operation.
        return maxHeap[0][1] if len(maxHeap) > 0 else 0


/**
1046. Last Stone Weight
Solved
Easy
Topics
conpanies iconCompanies
Hint

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
 */
