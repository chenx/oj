// This works. From: https://leetcode.com/discuss/83472/recommend-beginners-implementation-detailed-explanation
// DP. Recursive.
class Solution3 {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        vector<vector<int>> v(n, vector<int>(n, 0));
        return getMC(nums, v, 0, n-1);
    }
    
    int getMC(vector<int>& nums, vector<vector<int>> &v, int L, int R) {
        if (L + 1 == R) return 0;
        if (v[L][R] > 0) return v[L][R];
        int val = 0;
        for (int i = L + 1; i < R; ++ i) {
            val = max(val, nums[i] * nums[L] * nums[R] + getMC(nums, v, L, i) + getMC(nums, v, i, R));
        }
        v[L][R] = val;
        return val;
    }
}
    
// This works. From: https://leetcode.com/discuss/83802/neat-java-solution
// DP. Iterative.
class Solution2 {
public:
    int maxCoins2(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        vector<vector<int>> v(n, vector<int>(n, 0));
        
        for (int k = 2; k < n; ++ k) {
            for (int L = 0; L + k < n; ++ L) {
                int R = L + k;
                for (int M = L+1; M < R; ++ M) {
                    v[L][R] = max(v[L][R], nums[M] * nums[L] * nums[R] + v[L][M] + v[M][R]);
                }
            }
        }
        return v[0][n-1];
    }
}


// This should work, but exceeds space limit.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() <= 3) {
            int v = 1;
            for (int i = 0; i < nums.size(); ++ i) {
                v *= nums[i];
            }
            return v;
        }
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int v = INT_MIN;
        for (int i = 1; i < nums.size() - 1; ++ i) {
            int val = nums[i] * nums[i-1] * nums[i+1];
            vector<int> nums2 = nums;
            nums2.erase(nums2.begin() + i);
            v = max(v, val + maxCoins(nums2));
        }
        
        return v;
    }
};


/**
Burst Balloons
Difficulty: Hard

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number 
on it represented by array nums. You are asked to burst all the balloons. If 
the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and 
right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you 
    can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

 */


/**
Note:

This Bust Balloons problem (BB) is similar to matrix multiplication problem (MM). 
The elimination process is the same for both.

The difference is:
1) the MM problem finds the min value of the process.
   the BB problem finds the max value.
2) when there are only 3 elements a, b, c,
   the MM problem just returns a*b*c
   the BB problem returns a*b*c + a*c  + max(a, c)
   
E.g., input is [3,1,5,8], MM returns 64 (eliminate 5 first), BB returns 167 (eliminate 1 first).

The algorithm for MM is (from https://en.wikipedia.org/wiki/Matrix_chain_multiplication):

    int MM(vector<int>& p) {
        if (p.size() == 0) return 0;
        if (p.size() == 1) return p[0];
        
        int n = p.size() - 1;
        vector<vector<int>> m(n, vector<int>(n, 0));
        vector<vector<int>> s(n, vector<int>(n, 0));

        for (int ii = 1; ii < n; ii++) {
            for (int i = 0; i < n - ii; i++) {
                int j = i + ii;
                m[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
        return m[0][n-1];
    }
 */
