//
// This works.
//
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n <= 1) { // This needs separate handling.
            vector<long long> x;
            return x;
        }
        
        vector<long long> ans(n), left(n), right(n);

        left[0] = 1;
        for (int i = 1; i < n; ++ i) {
            left[i] = left[i-1] * nums[i-1];
        }
        
        right[n-1] = 1;
        for (int i = n-2; i >= 0; -- i) {
            right[i] = right[i+1] * nums[i+1];
        }
        
        for (int i = 0; i < n; ++ i) {
            ans[i] = left[i] * right[i];
        }
        
        return ans;
    }
};


/**
Product of Array Exclude Itself 

Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B without divide operation.

E.g.,
For A=[1, 2, 3], B is [6, 3, 2]
 */