# Priority Queue

## C++: Default is maxHeap (less<int>)
```
priority_queue<int, vector<int>, less<int>> maxHeap; // Default

priority_queue<int, vector<int>, greater<int>> minHeap;

Functions: push, pop, top, size, empty


priority_queue<ListNode *, vector<ListNode *>, comp> minPQ;
class comp {
 public:   
     bool operator()(const ListNode * a, const ListNode * b) const {
         return a->val > b->val; // min heap.
     }
};

priority_queue<vector<int>, vector<vector<int>>, comp2> maxHeap;
struct comp2 {
   bool operator()(vector<int>&a, vector<int>& b) {
       return a[0] < b[0];
   }
};
```

## Java: Default is minHeap
```
Queue<Integer> minHeap = new PriorityQueue<>(); // default
Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

Comparator:
Queue<Integer> maxHeap = new PriorityQueue<Integer>((a, b) -> a - b);


Methods: 
size(), isEmpty()
add/remove/element (when queue is full/empty, throws an exception)
offer/poll//peek  (when queue is full/empty, returns null)
```

## JavaScript

Have to implement. A quick implementation:

```
// From https://www.reddit.com/r/leetcode/comments/wuxw3s/how_do_you_make_a_priority_queue_in_javascript/
class MyMinHeap {
    constructor(compareFunc) {
        this.compareFunc = compareFunc;
        this.heap = [];
    }
        
    push(val) {
        this.heap.unshift(val);
        // this.heap.push(val); // this works too.
        this.heap.sort(this.compareFunc);
    }
        
    pop() {
        if (this.size === 0) return null;
        return this.heap.shift();
    }
        
    top() {
        if(this.size === 0) return null;
        return this.heap[0];
    }
        
    get size() {
        return this.heap.length;
    }

    empty() {
        return this.heap.length === 0;
    }
};
```

Example usage:
```
var minMeetingRooms = function(intervals) {
    intervals.sort((a, b) => a[0] - b[0]);

    const minHeap = new MyMinHeap((a, b) => a - b);
    for (let i = 0; i < intervals.length; ++ i) {
        if (!minHeap.empty() && intervals[i][0] >= minHeap.top()) minHeap.pop();
        minHeap.push(intervals[i][1]);
    }

    return minHeap.size;
};
```
