//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/29/2012
// @Last modified: 12/29/2012
//

class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, p = 0;

        while (p <= j) {
            if (nums[p] == 0) {
                swap(nums[i ++], nums[p ++]);
            } else if (nums[p] == 2) {
                swap(nums[p], nums[j --]);
            } else {
                ++ p;
            }
        }
    }
};


class Solution {
public:
    // O(n). Algorithm by Edsger Dijkstra. 
    // http://en.wikipedia.org/wiki/Dutch_national_flag_problem
    void sortColors(int A[], int n) {
        int i = 0, j = n-1, p = 0;
        
        while (p <= j) {
            if (A[p] == 0) {
                if (p != i) swap(A[p], A[i]);
                p ++;
                i ++;
            }
            else if (A[p] == 2) {
                swap(A[p], A[j]);
                j --; // note now A[p] can be 0 or 1, so keep it.
            }
            else { 
                p ++; 
            }
        }
    }
          
    // This works, but is O(1.5n).
    // http://heartfire.cc/wp/sort-colors/
    void sortColors2(int A[], int n) {
        int i = 0, j = n-1;
        
        // move all 2s to the right.
        while (i < j) {
            while (A[j] == 2 && i < j) j --;
            while (A[i] < 2 && i < j)  i ++;
            if (i < j)  swap(A[i], A[j]);
        }
 
        // move all 0s to the left.
        i = 0;
        while (i < j) {
            while (A[j] == 1 && i < j) j--;
            while (A[i] == 0 && i < j) i++;
            if (i < j) swap(A[i], A[j]);
        }
                
    }
    
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

// This does not work.
class Solution2 {
public:
    void sortColors(int A[], int n) {
        qs(A, 0, n - 1);
    }
    // not work yet.
    void qs(int A[], int left, int right) {
        int i = left, j = right;
        if (left >= right) return;
        
        while (i <= j) {
            while (A[i] < 1) i ++;
            while (A[j] > 1) j --;
            if (i < j) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                i ++;
                j --;
            } else {
                i ++;
            }
        }        
        //qs(A, left, j);
        //qs(A, j + 1, right);
    }
};

