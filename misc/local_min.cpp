/*
 * Search for local minimal in an un-sorted array.
 *
 * @Author: Xin chen
 * @on: 1/18/2013
 */
#include <iostream>
using namespace std;

// This algorithm assumes no adjacent duplicated number.
// Fails when adjacent duplication exist, e.g., 
// ... 5, 5, 5, ..., no way to tell go left or right.
// In such situation, also can't use other cases such as compare to first/last
// element, e.g., won't work for: 5, ..., 5, 5, 5, ..., 5.
int local_min(int a[], int left, int right) {
   if (left > right) return -1;
   if (left == right) return left;

   int mid, L = left, R = right;
   while (L <= R) {
       //printf("L = %d, R = %d\n", L, R);
       mid = (L + R) / 2; 
       // when mid is at the edge
       if (mid == left) {
           if (a[mid] < a[mid+1]) return mid;
           //return -1; // can't have this!
       } else if (mid == right) {
           if (a[mid] < a[mid-1]) return mid;
           //return -1; // can't have this!
       } else if (a[mid] < a[mid-1] && a[mid] < a[mid+1]) {
           return mid;
       }
       
       if (a[mid] < a[mid+1]) R = mid - 1; // -1 to avoid cycle
       else L = mid + 1; // +1 to avoid cycle
   }
   
   return -1;
}

int main() {
    //int A[] = {100,99,50,7,8,10,5,1,8,3};
    //int A[] = {100,99,50,17,8,3};
    //int A[] = {1,2,3,4,5,6};
    int A[] = {1,1,2,2,2};
    int len = sizeof(A)/sizeof(int);
    
    for (int i = 1; i <= len; ++ i) {
        int mn = local_min(A, 0, i-1);
        if (mn == -1) puts("local min not exist");
        else printf("local min: A[%d] = %d\n", mn, A[mn]);
    }
    return 0;
}

/*

100,99,50,7,8,10,5,1,8,3
O(n)

Time complexity: O(...)

100 1 2 3 4 5 6 7 .
int local_min(int a[], int left, int right) {
   if (left > right) return -1;
   if (left == right) return left;

   int mid, L = left, R = right;
   while (L <= R) {
       mid = (L + R) / 2; // (right - left)/2 + left
       // when mid is at the edge
       if (mid == left) {
            if (a[mid] < a[mid+1]) return mid;
       } else if (mid == right) {
            if (a[mid] < a[mid-1]) return mid;
       } else {
           if (a[mid] > a[mid-1] && a[mid] < a[mid+1]) return mid;
       }

       if (a[mid] < a[mid+1]) R = mid + 1;
       else L = mid;
   }
   return -1;
}


http://coder40.blogspot.com/2010/02/local-minimum-of-array.html
 Local Minimum of an Array
Problem: Given an array a of N distinct integers, design an O(log N) algorithm to find a local minimum: an index i such that a[i-1] > a[i] < a[i+1].

My answer: If a[0] < a[1] or a[N - 2] > a[N - 1] then a[0] or a[N - 1] is the local minimum, respectively. Pick a[mid] where mid = N / 2. If it's not the answer, we have three cases:
   1)  If a[mid - 1] < a[mid] < a[mid + 1], lower half will contain the local minimum.
   2)  If a[mid - 1] > a[mid] > a[mid + 1], upper half will contain the local minimum.
   3)  If a[mid - 1] < a[mid] > a[mid + 1], either half will contain the local minimum.
Search on the new interval recursively.

--> 4) a[mid] is larger than both elements on its 2 sides, then can only choose 1 side at random, or both?
 */
