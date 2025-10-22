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
