//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 12/20/2012
//

#include <iostream>
using namespace std;


// This also works and passes the large test set!
class Solution5 {
public:
    int jump(int A[], int n) {
        int ok[n];
        for (int i = 0; i < n; ++ i) ok[i] = -1;
        ok[n-1] = 0;
        
        for (int i = n-2; i >= 0; -- i) {
            for (int j = A[i]; j > 0; -- j) {
                if (ok[i + j] >= 0) {
                    if (ok[i] == -1 || ok[i] > 1 + ok[i + j]) {
                        ok[i] = 1 + ok[i + j];
                        if (ok[i] == 2) break; // this is needed to pass the large test set.
                    }
                }
            }
        }
        
        return ok[0];
    }
};


// This works too. Uses DP. Better method! Easier to code and understand.
class Solution4 {
public:
    int jump(int A[], int n) {
        int can[n];
        for (int i = 0; i < n-1; ++ i) can[i] = -1;
        can[n-1] = 0;
        
        for (int i = n-2; i >= 0; -- i) {
            if (i + A[i] >= n-1) {
                can[i] = 1;
            } else {
                for (int j = A[i]; j > 0; -- j) {
                // this works too, but time out for the last test case of the large test set.
                //for (int j = 1; j <= A[i]; ++ j) { 
                    if (can[i + j] > 0) {
                        if (can[i] < 0 || can[i] > 1 + can[i+j]) {
                            can[i] = 1 + can[i+j];
                        }
                        if (can[i] == 2) break;
                    }
                }
            } // end of if-else
        }
        
        return can[0];   
    }
};

// This works too. Slightly modified from Solution.
class Solution2 {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;
        
        int M[n]; // to record min steps.
        for (int i = 0; i < n; i ++) M[i] = -1;
        
        int ans = doJump(A, n, 0, M);        
        
        // M contains the min step for each element to reach end.
        return ans;
    }
    
    
    int doJump(int A[], int n, int p, int M[]) {
        if (A[p] == 0) return -1; // loop.
        if (M[p] != -1) return M[p]; // return existing value.
                
        int len = A[p];
        
        if (p + len >= n - 1) {
            M[p] = 1;
            return 1; // number of steps can't be smaller than this.
        }
        
        int minSteps = -1, min_i, steps;
        for (int i = p + len, end = p + 1; i >= end; i --) {
            steps = doJump(A, n, i, M);
            if (steps > 0) {
                if (minSteps < 0 || minSteps > steps) { 
                    minSteps = steps; min_i = i; 
                }
            }
            if (minSteps == 1) break; // can't be smaller than 1. cut branch.
        }
        
        if (minSteps < 0) return -1;
        
        //printf("A[%d]=%d -> A[%d]=%d : %d\n", p, A[p], min_i, A[min_i], 1+minSteps);
        M[p] = 1 + minSteps;
        return M[p];
    }    
};

// This works.
class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;
        
        int * M = new int[n]; // to record min steps.
        for (int i = 0; i < n; i ++) M[i] = -1;
        
        int ans = doJump(A, n, 0, M);        
        
        // M contains the min step for each element to reach end.
        //for (int i = 0; i < n; i ++) printf("%d ", M[i]); puts("");
        return ans;
    }
    
    
    int doJump(int A[], int n, int p, int M[]) {
        if (A[p] == 0) return -1; // loop.
        if (M[p] != -1) return M[p]; // return existing value.
                
        int len = A[p];
        
        if (p + len >= n - 1) {
            M[p] = 1;
            //printf("A[%d]=%d -> A[%d]=%d : %d\n", p, A[p], n-1, A[n-1], 1);
            return 1; // number of steps can't be smaller than this.
        }
        
        int minSteps = -1, min_i, steps;
        for (int i = p + len, end = p + 1; i >= end; i --) {
            steps = doJump(A, n, i, M);
            if (steps > 0) {
                if (minSteps < 0) { minSteps = steps; min_i = i; }
                else if (minSteps > steps) { minSteps = steps; min_i = i; }
            }
            if (minSteps == 1) break; // can't be smaller than 1. cut branch.
        }
        
        if (minSteps < 0) return -1;
        
        //printf("A[%d]=%d -> A[%d]=%d : %d\n", p, A[p], min_i, A[min_i], 1+minSteps);
        M[p] = 1 + minSteps;
        return M[p];
    }    
};


// This works too. Don't understand the code yet.
// http://www.mitbbs.com/article_t/JobHunting/32306955.html
class Solution3 {
public:
  int jump(int A[], int n) {
        int p = 0, q = 0, i = 0;
        while(q < n-1) {
            int m = q;
            for(; p <= q; ++p)
                m = max(m, p + A[p]);
            if(m == q) return -1; // in case cannot reach end
            q = m;
            ++i;
        }
        return i;
    }
};

int main() {
    Solution4 s;
    int A[] = {6,2,6,1,7,9,3,5,3,7,2,8,9,4,7,7,2,2,8,4,6,6,1,3}; //should be 4.
    int n = sizeof(A) / sizeof(int);
    cout << s.jump(A, n) << endl;
    return 0;
}
