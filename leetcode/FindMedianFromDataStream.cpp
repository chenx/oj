// Keep 2 priority queues: maxQ, minQ. 
// All elements in maxQ are less than elements in minQ.
// Insert new element to corresponding side, then balance the size of the 2 queues.
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        int v1 = maxQ.empty() ? INT_MIN : maxQ.top();
        int v2 = minQ.empty() ? INT_MAX : minQ.top();
        
        if (num <= v1) { maxQ.push(num); }
        else if (num >= v2) { minQ.push(num); }
        else { maxQ.push(num); }
        
        if (maxQ.size() - minQ.size() == 2) { // note: ">= 2" won't work. why?
            int v = maxQ.top();
            maxQ.pop();
            minQ.push(v);
        }
        else if (minQ.size() - maxQ.size() == 2) {
            int v = minQ.top();
            minQ.pop();
            maxQ.push(v);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxQ.size() == minQ.size()) {
            if (maxQ.size() == 0) return -1;  // underflow.
            return (maxQ.top() + minQ.top()) / 2.0;
        }
        else if (maxQ.size() >= minQ.size()) {
            return maxQ.top();
        }
        else {
            return minQ.top();
        }
    }
    
private:
    priority_queue<int, vector<int>, std::greater<int> > minQ;
    priority_queue<int, vector<int>, std::less<int> > maxQ;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
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
