/*
 * Given an array and a window size k. The window slides from head to tail of
 * the array. Get the max element in window each time.
 * http://leetcode.com/2011/01/sliding-window-maximum.html
 
3, 4, 5, 7, 3, 5, 2, 9
k = 3
print  ¡°5 7 7 7 5 9¡±

http://poj.org/problem?id=2823
http://www.cppblog.com/csu-yx/archive/2012/09/02/189137.html
http://www.leetcode.com/2011/01/sliding-window-maximum.html

A natural way most people would think is to try to maintain the queue size the same as 
the window¡¯s size. Try to break away from this thought and try to think outside of the box. 
Removing redundant elements and storing only elements that need to be considered in the 
queue is the key to achieve the efficient O(n) solution below.

void maxSlidingWindow(int A[], int n, int w, int B[]) {
  deque Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w) // slide outside of window now.
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];
}

The above algorithm could be proven to have run time complexity of O(n). 
This is because each element in the list is being inserted and then removed at most once. 
Therefore, the total number of insert + delete operations is 2n.
 */
