//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 2/19/2013
//

#include <iostream>
using namespace std;
// This works too, although not so obvious why.
// From: https://leetcode.com/discuss/65622/simple-c-solution
class Solution4 {
public:
    bool canJump(vector<int>& nums) {
        int u = 1;
        for (int i = 0; i < nums.size(); i ++){
            if (-- u < 0) return false;
            u = max(nums[i], u);
        }
        return true;
    }
};

// This works too. 
// From: https://leetcode.com/discuss/69187/simple-c-solution
class Solution3 {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;

        for (int i = target - 1; i >= 0; -- i){
            if (nums[i] + i >= target) target = i;
        }

        return target == 0;
    }
}

// Added 2/19/2013. Better solution. Uses DP.
// Fill can[] table backward.
class Solution2 {
public:
    bool canJump(int A[], int n) {
        int can[n]; // = {0};
        for (int i = 0; i < n; ++ i) can[i] = 0;
        
        for (int i = n-1; i >= 0; -- i) {
            if (i + A[i] >= n-1) {
                can[i] = 1;
            } else {
                for (int j = A[i]; j > 0; -- j) {
                    if (can[i + j] == 1) {
                        can[i] = 1;
                        break;
                    }
                }
            } // end of if-else
        }
        
        return can[0];
    }
};


//
// Major problems: 1) try all possibilities, 2) avoid possible loop.
//

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1) return true;
        return jump(A, n, 0);
    }
    
    bool jump(int A[], int n, int p) {
        //printf("jump: n = %d, p = %d, A[p] = %d\n", n, p, A[p]);
        if (A[p] <= 0) return false; // loop.
        
        int len = A[p];
        A[p] = - A[p]; // label as visited.

        int i = p + len;
        if (i >= n - 1) return true;
        
        //for (int end = p + 1; i >= end; i --) {
        for (; i >= p+1; i --) {
            if (A[i] > 0) {
                if (jump(A, n, i)) return true;
            }
        }
        return false;
    }
    
    // This can pass test, but is incorrect. 
    // e.g., A = {2,2,0,1,4} should be true, but this returns false.
    bool canJump_wrong(int A[], int n) {
        if (n <= 1) return true;
        
        int p = 0;
        while (p < n - 1) {
            printf("p = %d\n", p);
            if (A[p] == 0) return false;
            p += A[p];
        }
        return true;
    }
    
};


int main() {
    Solution s;
    int A[] = {2,1,1,0,0};
//    int A[] = {6,2,6,1,7,9,3,5,3,7,2,8,9,4,7,7,2,2,8,4,6,6,1,3}; //should be 4.
    int n = sizeof(A) / sizeof(int);
    cout << s.canJump(A, n) << endl;
    return 0;
}
