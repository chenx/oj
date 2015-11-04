// Keep 2 priority queues: maxQ, minQ. 
// All elements in maxQ are less than elements in minQ.
// Insert new element to corresponding side, then balance the size of the 2 queues.
class MedianFinder {

    // Adds a number into the data structure.
    public void addNum(int num) {
        int v1 = maxQ.size() == 0 ? Integer.MIN_VALUE : maxQ.peek();
        int v2 = minQ.size() == 0 ? Integer.MAX_VALUE : minQ.peek();
        
        if (num <= v1) { maxQ.add(num); }
        else if (num >= v2) { minQ.add(num); }
        else { maxQ.add(num); }
        
        if (maxQ.size() - minQ.size() == 2) {
            int v = maxQ.peek();
            maxQ.remove(v);
            minQ.add(v);
        }
        else if (minQ.size() - maxQ.size() == 2) {
            int v = minQ.peek();
            minQ.remove(v);
            maxQ.add(v);
        }
    }

    // Returns the median of current data stream
    public double findMedian() {
        if (maxQ.size() == minQ.size()) {
            if (maxQ.size() == 0) return -1;
            return (maxQ.peek() + minQ.peek()) / 2.0;
        }
        else if (maxQ.size() >= minQ.size()) {
            return maxQ.peek();
        }
        else {
            return minQ.peek();
        }
    }
    
    /** 
     * You can also declare maxQ like this:
      
       maxQ = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) { 
                if (a < b) return 1;
                else if (a > b) return -1;
                return 0;
            }
        });
        maxQ = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) { return a == b ? 0 : (a < b ? 1 : -1); }
        });
        maxQ = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) { return a < b ? 1 : -1; }
        });

        And delcare minQ like this:
        
        minQ = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) { return a > b ? 1 : -1; }
        });
        minQ = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) { return a == b ? 0 : (a > b ? 1 : -1); }
        });
        
     *  Reference: http://stackoverflow.com/questions/11003155/change-priorityqueue-to-max-priorityqueue
     */
    public MedianFinder() {
        maxQ = new PriorityQueue<Integer>(Collections.reverseOrder());
        minQ = new PriorityQueue<Integer>(); // can also add a initial size parameter: P.Q.<Integer>(10);
    }
    
    private PriorityQueue<Integer> minQ;
    private PriorityQueue<Integer> maxQ;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf = new MedianFinder();
// mf.addNum(1);
// mf.findMedian();

/**
Find Median from Data Stream
Difficulty: Hard

Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.
Examples:

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.

For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

 */
 
