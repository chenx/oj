//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/24/2012
//

// Works. Tested. Among the best.
class Solution6 {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] != val) nums[k ++] = nums[i];
        }
        return k;
    }
};

// Solution 2 is better than 1, when e.g., only A[0] != elem, then s1 does n-1 copy,
// but s2 does only 1 swap. 
// Solution 1 is better than 2, when e.g., only A[n-1] != elem, then s2 swaps n-1 times,
// but s1 only does 1 copy.
// Solution3 always better than 1, but code too complex.
// Solution4 is the best.

// This works too! Shortest so far. 1/25/2016.
class Solution5 {
public:
    int removeElement(vector<int>& nums, int val) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            if (nums[L] == val) swap(nums[L], nums[R --]);
            else ++ L;
        }
        
        return L; // or R+1
    }
};

// This works too!
class Solution4 {
public:
    int removeElement(int A[], int n, int elem) {
        int L = 0, R = n - 1;
        
        while (L <= R) {
            if (A[R] == elem) {
                -- R;
            }
            else if (A[L] == elem) {
                swap(A[L ++], A[R --]);
            }
            else {
                ++ L;
            }
        }
        
        return R + 1;
    }
    
};



// This is changed from Solution2. Also works, and is more efficient than Solution 1
// always, but is more complex in code.
class Solution3 {
public:
    int removeElement(int A[], int n, int elem) {
        for (int i = 0; i < n; ++ i) {
                while (A[n-1] == elem) -- n; // this is not necessary, but better.
                if (i >= n) break;
                
                if (A[i] == elem) {
                swap(A[i], A[n-1]); // before this can add "if (i!=n-1) ".
                -- n;
                if (i == n) break; // NOTE this.
                -- i;
            }
        }
        return n;
    }
};

// This works too, and is also good.
// This swaps elem to end of array, and decrements array size.
class Solution2 {
public:
    int removeElement(int A[], int n, int elem) {
        while (A[n-1] == elem) -- n; // this is not necessary, but better.
        for (int i = 0; i < n; ++ i) {
            if (A[i] == elem) {
                swap(A[i], A[n-1]); // before this can add "if (i!=n-1) ".
                -- n;
                if (i == n) break; // NOTE this.
                -- i;
            }
        }
        return n;
    }
};

class Solution {
public:
    // The much better way.
    // Check each elem in sequence, if not equal to elem, copy to current pos k.
    int removeElement(int A[], int n, int elem) {
        int k = 0;
        for (int i = 0; i < n; i ++) {
            if (A[i] != elem) A[k ++] = A[i];
        }
                
        return k;
    }
       
    // This works too but much more complex.
    // Use swap.
    int removeElement2(int A[], int n, int elem) {
        if (n == 0) return 0;
        int i = 0, j = n - 1;
        
        while (i <= j) {
            while (A[j] == elem) {
                j --;
                n --;
            }
            if (j < i) break; // dont forget this!
            
            if (A[i] == elem) {
                swap(A[i], A[j]);
                j --;
                n --;
            }
            else { i ++; }
        }
        return n;
    }
    
    void swap(int &x, int &y) {
        int tmp = x;
        x = y;
        y = tmp;
    }

};
