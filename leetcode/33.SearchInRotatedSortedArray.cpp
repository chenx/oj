//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 1/9/2013
//

// Works.
class Solution4 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int L = 0, R = n - 1;
        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (nums[M] == target) return M;
            
            if (nums[M] < nums[R]) { // < or <=, both work here.
                if (nums[M] < target && target <= nums[R]) L = M + 1;
                else R = M - 1;
            }
            else {
                if (nums[L] <= target && target < nums[M]) R = M - 1;
                else L = M + 1;
            }
        }
        
        return -1; // <- note this: not found!
    }
};


class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bsearch_ca_asc(a, left, right, v);
    }
        
    int bsearch_ca_asc(int a[], int left, int right, int v) {
      int mid;
      if (left > right) return -1;
    
      mid = (left + right) / 2;
    
      if (v == a[mid]) {
        return mid;
      } else if ( (a[left] <= a[mid] && (a[left] <= v && v < a[mid]) ) ||
                  (a[left] > a[mid]  && (a[mid] >= v || v > a[right])) ) { // Note: ||
          return bsearch_ca_asc(a, left, mid - 1, v);
      } else {
          return bsearch_ca_asc(a, mid + 1, right, v);
      }
    }  
    
    /*
    // Assume array is ordered DESC.
    int bsearch_ca_desc(int a[], int left, int right, int v) {
      int mid;
      if (left > right) return -1;
    
      mid = (left + right) / 2;
    
      if (v == a[mid]) {
        return mid;
      } else if ( (a[left] <= a[mid] && (a[left] <= v && v < a[mid]) ) ||
                  (a[left] > a[mid]  && (a[mid] >= v || v > a[right])) ) {
          return bsearch_ca_desc(a, mid + 1, right, v);
      } else {
          return bsearch_ca_desc(a, left, mid - 1, v);
      }
    }
    */
    
};


// This works too, iterative version. Better.
// From: http://leetcode.com/2010/04/searching-element-in-rotated-array.html
class Solution2 {
public:
    int search(int A[], int n, int target) {
        return rotated_binary_search(A, n, target);
    }
        
    int rotated_binary_search(int A[], int N, int key) {
      int L = 0;
      int R = N - 1;
     
      while (L <= R) {
        // Avoid overflow, same as M=(L+R)/2
        int M = L + ((R - L) / 2);
        if (A[M] == key) return M;
     
        // the bottom half is sorted
        if (A[L] <= A[M]) {   // NOTE: if use <, then above M = (L+R+1)/2. See Solution3.
          if (A[L] <= key && key < A[M])
            R = M - 1;
          else
            L = M + 1;
        }
        // the upper half is sorted
        else {
          if (A[M] < key && key <= A[R])
            L = M + 1;
          else
            R = M - 1;
        }
      }
      return -1;
    }

};


//
// Slightly modified from Solution 2, on calc of M and "if (A[L} < A[M]) {".
// This is because of the rounding error: 
// if L+R is odd, (L+R)/2 falls on L side.
// but (L+R+1)/2 falls on R side.
//
class Solution3 {
public:
    int search(int A[], int n, int target) {
        return rotated_binary_search(A, n, target);
    }
        
    int rotated_binary_search(int A[], int N, int key) {
      int L = 0;
      int R = N - 1;
     
      while (L <= R) {
        // Avoid overflow, same as M=(L+R)/2
        int M = L + (R - L + 1) / 2;
        if (A[M] == key) return M;
     
        // the bottom half is sorted
        if (A[L] < A[M]) {
          if (A[L] <= key && key < A[M])
            R = M - 1;
          else
            L = M + 1;
        }
        // the upper half is sorted
        else {
          if (A[M] < key && key <= A[R])
            L = M + 1;
          else
            R = M - 1;
        }
      }
      return -1;
    }
};

// This code finds the pivot in a rotated sorted ASC array..
int FindSortedArrayRotationPivot(int A[], int N) {
  int L = 0;
  int R = N - 1;
 
  while (A[L] > A[R]) {
    int M = L + (R - L) / 2;
    if (A[M] > A[R])
      L = M + 1;
    else
      R = M; // NOTE: remember this!
  }
  return L;
}

/*
33. Search in Rotated Sorted Array
Medium

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its 
index, otherwise return -1.

You may assume no duplicate exists in the array.

 */

