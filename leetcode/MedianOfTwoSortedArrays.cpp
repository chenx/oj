//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 1/8/2013
//

// This also works. 11/29/2015
// Signature is changed, so use offset here. This is easier to adapt for Java. 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len & 1 == 1) {
            return getKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), 1 + len/2);
        }
        else {
            return (getKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len/2) +
                getKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), 1 + len/2)) / 2.0;
        }
    }
    
    int getKth(vector<int>& nums1, int offset1, int m, vector<int>& nums2, int offset2, int n, int k) {
        if (m > n) return getKth(nums2, offset2, n, nums1, offset1, m, k);
        if (m == 0) return nums2[offset2 + k-1];
        if (k == 1) return min(nums1[offset1], nums2[offset2]);
        
        int p1 = min(k/2, m);
        int p2 = k - p1;
        
        if (nums1[offset1 + p1 - 1] < nums2[offset2 + p2 - 1]) {
            return getKth(nums1, offset1 + p1, m - p1, nums2, offset2, n, k - p1);
        }
        else {
            return getKth(nums1, offset1, m, nums2, offset2 + p2, n - p2, k - p2);
        }
    }
};

// This works! And so simple!
// From: http://blog.csdn.net/sunjilong/article/details/8254130
class Solution2 {  
public:  
     double findKth(int a[], int m, int b[], int n, int k)  
     {  
         if (m > n) return findKth(b, n, a, m, k);  
         if (m == 0) return b[k-1];  
         if (k == 1) return min(a[0], b[0]);  
       
         int pa = min(k/2, m), pb = k - pa;  
           
         if (a[pa-1] < b[pb-1])   // Note: it's a[pa-1] and b[pb-1].
             return findKth(a+pa, m-pa, b, n, k-pa);  
         else   
             return findKth(a, m, b+pb, n-pb, k-pb);  
     }  
       
     double findMedianSortedArrays(int A[], int m, int B[], int n) {  
         int total = m+n;  
            
         if (total&0x1)  
             return findKth(A, m, B, n, total/2+1);  // Note: it's total/2 + 1.
         else  
             return (findKth(A, m, B, n, total/2) + findKth(A, m, B, n, total/2+1))/2;  
     }  
};

// This works too!
// From http://blog.csdn.net/tingmei/article/details/8090450
class Solution {  
public:  
    int fink(int A[], int m, int B[], int n, int k)  
    {  
        if (m <= 0)  
            return B[k-1];  
        if (n <= 0)  
            return A[k-1];  
              
        int i = ((double)m/(m+n)) * k - 1;  
        int j = (k-1) - i;  
      
        int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);  
        int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);  
        int Ai   = ((i == m) ? INT_MAX : A[i]);  
        int Bj   = ((j == n) ? INT_MAX : B[j]);  
    
        if (Bj_1 <= Ai && Ai <= Bj)  
            return Ai;  
        else if (Ai_1 <= Bj && Bj <= Ai)  
            return Bj;  
      
        //A[i] is too small, get rid of lower part of A and higher part of B  
        if (Ai < Bj)  
            return fink(A+i+1, m-i-1, B, j, k-i-1);  
          
        //B[j] is too small, get rid of higher part of A and lower part of B  
        else //if(i > 0 && B[j] < A[i-1])   
            return fink(A, i, B+j+1, n-j-1, k-j-1);  
    }  
      
    double findMedianSortedArrays(int A[], int m, int B[], int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int total = m + n;  
        if (total % 2 != 0)  
            return fink(A, m, B, n, total/2+1);  
        else  
        {  
            double a = fink(A, m, B, n, total/2);  
            double b = fink(A, m, B, n, total/2+1);  
            return (a + b)/2.0;  
        }  
    }  
};  


// This does NOT work.
class Solution_bad {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0) {
            if (n == 0) return 0;
            
            if (n % 2 == 1) return B[n/2];
            else return (B[n/2] + B[n/2 + 1])/2;
        }
        
        int ai, bi;
        if ( (m + n) % 2 == 1 ) { // middle 1.
            for (ai = 0; ai < m; ++ ai) {
                bi = (n+m-1)/2 - ai;
                if (bi < 0 || bi >= n) continue;
                
                if (ai == m-1 && A[ai] <= B[bi]) {
                    return B[bi];
                }
                else if (A[ai] <= B[bi] && B[bi] <= A[ai + 1]) {
                    return B[bi];
                }
            }
        } else { // average of middle 2.
            for (ai = 0; ai < m; ++ ai) {
                bi = (n+m)/2 - 1 - ai;
                if (bi < 0 || bi >= n) continue;
                
                if (ai == m-1 && A[ai] <= B[bi]) {
                    return (A[ai] + B[bi]) / 2;
                }
                else if (A[ai] <= B[bi] && B[bi] <= A[ai + 1]) {
                    return (A[ai] + B[bi]) / 2;
                }
            }
        }
        
        return findMedianSortedArrays(B, n, A, m);
    }
};

////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Solution {
public:
    // O(m+n). This works.
    // if m+n is odd, return (m+n)/2.
    // else, use average (use_avg == 1), return (m+n)/2 - 1 and (m+n)/2.
    // Note: use 2.0 for float calculation.
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int use_avg = 0, mid = (m+n) / 2;
        if ((m + n) % 2 == 0) { mid -= 1; use_avg = 1; }
        
        int ct = 0, i = 0, j = 0, v;
        while (i < m && j < n) {
            if (A[i] < B[j]) { v = A[i]; i ++; }
            else { v = B[j]; j ++; }
            if (ct == mid) {
                if (use_avg) { 
                    if (i < m && j < n) return (v + min(A[i], B[j])) / 2.0;  
                    if (i < m) return (v + A[i]) / 2.0;
                    if (j < n) return (v + B[j]) / 2.0;
                    return v;
                }
                else return v;
            }
            ct ++; // Note this is in the end.
        }
        
        while (i < m) { 
            if (ct == mid) {
                if (use_avg) return (A[i] + A[i+1]) / 2.0;
                else return A[i];
            }
            i ++; 
            ct ++;
        }
        while (j < n) {
            if (ct == mid) {
                if (use_avg) return (B[j] + B[j+1]) / 2.0;
                else return B[j];
            }            
            j ++; 
            ct ++;
        }
        
        return 0;
    }


    // O(log m) * O(log n). 
    // This does not work yet. Code is messy.
    // e.g. http://www.leetcode.com/2011/03/median-of-two-sorted-arrays.html#comment-771
    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        if (m == 0) return getM(B, n);
        if (n == 0) return getM(A, m);
        
        if (A[m - 1] <= B[0]) { return getM2(A, m, B, n); }
        if (B[n - 1] <= A[0]) { return getM2(B, n, A, m); }
        
        double med;
        
        int v = findM(A, m, B, n, & med);
        if (v >= 0) return med;
        
        v = findM(B, n, A, m, & med);
        if (v >= 0) return med;
    }
    
    double getM2(int A[], int m, int B[], int n) {
        if (m < n) {
            if ((m + n) % 2 == 1) { return B[(n-m-1)/2]; }
            else return (B[(n-m)/2 - 1] + B[(n-m)/2]) / 2.0;
        }
        else if (n < m) {
            if ((m + n) % 2 == 1) { return A[(m-n+1)/2]; }
            else return (A[(m-n)/2 - 1] + A[(m-n)/2]) / 2.0;            
        }
        else { // m == n
            return (A[m-1] + B[0]) / 2.0;
        }
    }
    
    double getM(int A[], int m) {
        if (m % 2 == 0) {
            return (A[m/2 - 1] + A[m/2]) / 2.0;
        }
        else return A[m/2];
    }
    
    double medOf4(int a, int b, int c, int d) {
        int mx = max(a, max(b, max(c, d)));
        int mn = min(a, min(b, min(c, d)));
        return (a + b + c + d - mx - mn) / 2;
    }
    
    // find B[bi] in A[].
    int findM(int A[], int m, int B[], int n, double * median) {
        int ai, bi, bl = 0, br = n-1, v;
        
        while(bl <= br) {
            bi = (bl + br) / 2;
            ai = bsearch(A, 0, m-1, B[bi]);
            v = ai + bi - (n+m)/2;
            if (v == 0) {
                if ((m + n) % 2 == 1) *median = B[bi];
                else if (m%2 == 1 && n%2 == 1 && B[bi] < A[ai]) *median = medOf4(A[ai-1], A[ai], B[bi], B[bi+1]);
                else *median = medOf4(A[ai-1], A[ai], B[bi-1], B[bi]);
                //if ( (n + m) % 2 == 0) { * median = (B[bi] + A[ai - 1]) / 2.0; }
                //else { * median = A[ai]; }
                return bi;
            } else if (v > 0) { // bi too large
                br = bi - 1;
            } else {
                bl = bi + 1;
            }
        }
        return -1;        
    }
    
    int bsearch(int A[], int left, int right, int k) {
        int mid;
        if (left > right) return -1;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == k) return mid;
            else if (A[mid] > k) right = mid - 1;
            else left = mid + 1;
        }
    
        return left; // insertion point. A[left-1] < k < A[left]
    }
};

int main() {
    int A[] = {1};
    int m = sizeof(A) / sizeof(int);
    int B[] = {2,3};
    int n = sizeof(B) / sizeof(int);
    
    Solution s;
    printf("ans: %f\n", s.findMedianSortedArrays(A, m, B, n));
    
    return 0;
}


/*
Problem:
        
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time 
complexity should be O(log (m+n)).
 */
