class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = A.size()/2 - 1; i >= 0; i --) movedown(A, i);
    }
    
    void movedown(vector<int> &h, int n) {
      int child, tmp = h[n]; // move tmp down if it's larger than child.
      while ((child = getChild(h, n)) != -1 && tmp > h[child]) {
        h[n] = h[child];
        n = child;
      }
      h[n] = tmp;
    }
    
    int getChild(vector<int> &h, int n) {
      int left = 2 * n + 1;   /* left child. */
      int right = left + 1;   /* right child. */
    
      if (left >= h.size()) return -1; /* n is a leaf */
      if (right == h.size()) return left; /* n has only left child */
    
      return (h[left] < h[right]) ? left : right;
    }

};

/**
Heapify

Given an integer array, heapify it into a min-heap array.
For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] 
is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

Have you met this question in a real interview?
Clarification

What is heap?

    Heap is a data structure, which usually have three methods: push, pop and top. 
    where "push" add a new element the heap, "pop" delete the minimum/maximum 
    element in the heap, "top" return the minimum/maximum element.


What is heapify?

    Convert an unordered integer array into a heap array. If it is min-heap, 
    for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].


What if there is a lot of solutions?

    Return any of them.

Example

Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.
Challenge

O(n) time complexity

 */
