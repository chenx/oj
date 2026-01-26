class MedianFinder:

    def __init__(self):
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num: int) -> None:
        if (len(self.minHeap) > 0 and num >= self.minHeap[0]):
            heapq.heappush(self.minHeap, num)
        else:
            heapq.heappush_max(self.maxHeap, num)
        
        sizeDiff = len(self.minHeap) - len(self.maxHeap)
        if sizeDiff == 2:
            heapq.heappush_max(self.maxHeap, self.minHeap[0])
            # self.minHeap.pop(). # This works too, but better use heappop().
            heapq.heappop(self.minHeap)
        elif sizeDiff == -2:
            heapq.heappush(self.minHeap, self.maxHeap[0])
            # self.maxHeap.pop()  # This removes maxHeap[-1], but it should pop maxHeap[0]
            heapq.heappop_max(self.maxHeap)

    def findMedian(self) -> float:
        sizeDiff = len(self.minHeap) - len(self.maxHeap)
        if sizeDiff == 1:
            return self.minHeap[0]
        elif sizeDiff == -1:
            return self.maxHeap[0]
        else:
            return 0 if len(self.minHeap) == 0 else ((1.0 * self.minHeap[0] + self.maxHeap[0]) / 2.0);


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

/**
295. Find Median from Data Stream
Hard

The median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value, and the median is the mean of the two middle values.

    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far. Answers within 10-5 of 
        the actual answer will be accepted.
 */
