//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/6/2013
// @Last modified: 1/15/2013
//

//
// This is modified from Solution.firstMissingPositive()
// by combining the while and if in the latter.
//
class Solution2 {
public:
    int firstMissingPositive(int A[], int n) {
        int i;
        for (i = 0; i < n; ++ i) {
            while (A[i] != i + 1 && 
                   A[i] > 0 && A[i] <= n - 1 && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i]-1]); // move A[i] to A[A[i] - 1].
             }
        }
        
        for (int i = 0; i < n; ++ i) {
            if (A[i] != i + 1) return i + 1;
        }
        
        return n + 1;  // Note this should be n + 1.
    }
};


class Solution {
public:
    // http://yewenxing.wordpress.com/2012/03/13/first-missing-positive/
    // The key idea is to put every element in A such that A[i]=i
    int firstMissingPositive(int A[], int n) {
        if (n == 0) return 1;
        // put every pos element i at A[i].
        for (int i = 0; i < n; ++ i) {
            while (A[i] != i + 1) {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]) break;
                // swap A[i] and A[A[i] - 1].
                int tmp = A[i];
                A[i] = A[tmp - 1];
                A[tmp - 1] = tmp;
            }
        }
        
        for (int i = 0; i < n; ++ i) {
            if (A[i] != i + 1) return i + 1;
        }
        
        return n + 1;
    }
    
    // same as above. different at while loop presentation.
    int firstMissingPositive2(int A[], int n) {
        for (int i = 0; i < n; ++ i) {
            while (A[i] != i + 1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]) {
                // swap A[i] and A[A[i] - 1].
                int tmp = A[i];
                A[i] = A[tmp - 1];
                A[tmp - 1] = tmp;
            }
        }
        
        for (int i = 0; i < n; ++ i) {
            if (A[i] != i + 1) return i + 1;
        }
        
        return n + 1;
    }    
    
    // Same as above, with different presentation.
    int firstMissingPositive3(int A[], int n) {
        for (int i = 0; i < n; ++ i) {
            if (A[i] > 0 && A[i] <= n &&
                A[i] != i + 1 && A[i] != A[A[i] - 1]) {
                // swap A[i] and A[A[i] - 1].
                int tmp = A[i];
                A[i] = A[tmp - 1];
                A[tmp - 1] = tmp;
                -- i; // Note this! Do this on A[i] again.
            }
        }
        
        for (int i = 0; i < n; ++ i) {
            if (A[i] != i + 1) return i + 1;
        }
        
        return n + 1;
    }    
    
    // This works too.
    int firstMissingPositive4(int A[], int n) {
        //if (n == 0) return 1; // no need.
        int i=0;
        while (i<n) {
            if (A[i]>=0 && A[i]<n) {
                if (A[i]!=i && A[i]!=A[A[i]]) {
                    int temp = A[A[i]];
                    A[A[i]] = A[i];
                    A[i] = temp;
                    continue;
                }
            }
            i++;
        }
    
        for (i=1; i<n; i++) {
            if (i!=A[i]) return i;
        }
    
        if (A[0]==n) return n+1;
    
        return n;
    }
        
};
