//
// Given a k-sorted array, sort it.
// OR: given an array of n unsorted integers, and each number is at most k
// positions away from its final sorted position, given an efficient 
// sorting algorithm.
//
// Idea: 
// First sort the initial 2k elements [1, 2k], this is O(k log k).
// Now first k elements are in final place, but 2nd k elements not yet.
// Next sort 2k elements in range [k+1, 3k], ... 
// In the end, there are n/k such interations. 
// Total time: O (k logk * (n/k)) = O (n logk). But k is constant, so it's O(n).
// Space: O(1).
//
// Idea 2:
// Each cells 2K+1 apart are sorted. This is equivalent to merge sorted lists: (also O(nlogk))
//   0, 2k, 4k, ...
//   1, 2k+1, 4k+1, ...
//   2, 2k+2, 4k+2, ...
//   ...
//   2k-1, 4k-1, 6k-1, ...
//
// In implementation details:
// 1) Use insertion sort. Inner cycle will run at most k times. 
//    Overall O(nk) time, O(1) space.
// 2) Use a min heap of size k+1. 
//    - Create a Min Heap of size k+1 with first k+1 elements. This will take O(k) time
//    - One by one remove min element from heap, put it in result array, and add a new element to heap from remaining elements.
//    Removing an element and adding a new element to min heap will take Logk time. So overall complexity will be O(k) + O((n-k)*logK)
//
// [1] http://stackoverflow.com/questions/2726785/interview-q-sorting-an-almost-sorted-array-elements-misplaced-by-no-more-than
// [2] http://www.geeksforgeeks.org/nearly-sorted-algorithm/
// 
// @By: Xin Chen
// @Created on: 3/22/2013
// @Last modified: 3/22/2013
//

// Method 1)
/* Function to sort an array using insertion sort*/
void insertionSort(int A[], int size)
{
   int i, key, j;
   for (i = 1; i < size; i++)
   {
       key = A[i];
       j = i-1;
 
       /* Move elements of A[0..i-1], that are greater than key, to one
          position ahead of their current position.
          This loop will run at most k times */
       while (j >= 0 && A[j] > key)
       {
           A[j+1] = A[j];
           j = j-1;
       }
       A[j+1] = key;
   }
}


// Method 2)

#include<stdio.h>
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
 
// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int heap_size; // size of min heap
public:
    // Constructor
    MinHeap(int a[], int size);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to remove min (or root), add a new value x, and return old root
    int replaceMin(int x);
 
    // to extract the root which is the minimum element
    int extractMin();
};
 
// Given an array of size n, where every element is k away from its target
// position, sorts the array in O(nLogk) time.
int sortK(int arr[], int n, int k)
{
    // Create a Min Heap of first (k+1) elements from
    // input array
    int *harr = new int[k+1];
    for (int i = 0; i <=k; i++)
        harr[i] = arr[i];
    MinHeap hp(harr, k+1);
 
    // i is index for remaining elements in arr[] and ti
    // is target index of for cuurent minimum element in
    // Min Heapm 'hp'.
    for(int i = k+1, ti = 0; ti < n; i++, ti++)
    {
        // If there are remaining elements, then place
        // root of heap at target index and add arr[i]
        // to Min Heap
        if (i < n)
            arr[ti] = hp.replaceMin(arr[i]);
 
        // Otherwise place root at its target index and
        // reduce heap size
        else
            arr[ti] = hp.extractMin();
    }
}
 
// FOLLOWING ARE IMPLEMENTATIONS OF STANDARD MIN HEAP METHODS FROM CORMEN BOOK
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    int root = harr[0];
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
    }
    return root;
}
 
// Method to change root with given value x, and return the old root
int MinHeap::replaceMin(int x)
{
    int root = harr[0];
    harr[0] = x;
    if (root < x)
        MinHeapify(0);
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// A utility function to print array elements
void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortK(arr, n, k);
 
    printf("Following is sorted array\n");
    printArray (arr, n);
 
    return 0;
}
