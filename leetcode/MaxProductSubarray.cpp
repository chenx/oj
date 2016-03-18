// Works too. Tested.
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxp = INT_MIN, p = 1;
        for (int i = 0; i < n; ++ i) {
            if (p == 0) p = 1;
            p *= nums[i];
            maxp = max(maxp, p);
        }
        
        p = 1;
        for (int i = n-1; i >= 0; -- i) {
            if (p == 0) p = 1;
            p *= nums[i];
            maxp = max(maxp, p);
        }
        
        return maxp;
    }
};

// 10/16/2014
// Note: the array is separately by several segments by 0.
// Get the max from each segment, then get the global max from local max.
// You need a second round from back to front, for there may be neg products (e.g., -1, 3, 5).
// This works.
class Solution {
public:
    int maxProduct(int A[], int n) {
        int mp = A[0], p = A[0];
        for (int i = 1; i < n; ++ i) {
            if (p == 0) p = 1;
            p *= A[i];
            mp = max(mp, p);
        }
        
        mp = max(mp, A[n-1]);
        p = A[n-1];
        for (int i = n-2; i >= 0; -- i) {
            if (p == 0) p = 1;
            p *= A[i];
            mp = max(mp, p);
        }
        
        return mp;
    }
};


/*

Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 

*/
