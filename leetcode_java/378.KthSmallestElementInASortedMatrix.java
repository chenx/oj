// Time Complexity: let X=min(K,N);X+Klog(X)
// Space Complexity: O(X) which is occupied by the heap.
class Solution2 {
  public int kthSmallest(int[][] matrix, int k) {
    int N = matrix.length;

    PriorityQueue<int[]> minHeap = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);

    // Preparing our min-heap
    for (int r = 0; r < Math.min(N, k); r++) {
      minHeap.add(new int[]{matrix[r][0], r, 0});
    }

    int[] element = minHeap.peek();
    for (; k > 0; -- k) {
      element = minHeap.poll();
      int r = element[1], c = element[2];

      if (c < N - 1) {
        minHeap.add(new int[]{matrix[r][c + 1], r, c + 1});
      }
    }

    return element[0];
  }
}


// From https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/editorial/
class MyHeapNode {
  int row;
  int column;
  int value;

  public MyHeapNode(int v, int r, int c) {
    this.value = v;
    this.row = r;
    this.column = c;
  }

  public int getValue() {
    return this.value;
  }

  public int getRow() {
    return this.row;
  }

  public int getColumn() {
    return this.column;
  }
}

class MyHeapComparator implements Comparator<MyHeapNode> {
  public int compare(MyHeapNode x, MyHeapNode y) {
    return x.value - y.value;
  }
}

class Solution {
  public int kthSmallest(int[][] matrix, int k) {
    int N = matrix.length;

    PriorityQueue<MyHeapNode> minHeap =
        new PriorityQueue<MyHeapNode>((a, b) -> a.value - b.value);
        //  new PriorityQueue<MyHeapNode>(Math.min(N, k), new MyHeapComparator());

    // Preparing our min-heap
    for (int r = 0; r < Math.min(N, k); r++) {
      minHeap.add(new MyHeapNode(matrix[r][0], r, 0));
    }

    MyHeapNode element = minHeap.peek();
    for (; k > 0; -- k) {
      element = minHeap.poll();
      int r = element.getRow(), c = element.getColumn();

      if (c < N - 1) {
        minHeap.add(new MyHeapNode(matrix[r][c + 1], r, c + 1));
      }
    }

    return element.getValue();
  }
}

/**
378. Kth Smallest Element in a Sorted Matrix
Medium

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 */
