// Works too. Intuitively based on Patience Sort, but not as good as Solution.
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), L, R, M;
        if (n == 0) return 0;
        
        vector<int> v;
        v.push_back(nums[0]);

        for (int i = 1; i < n; ++ i) { // search for nums[i] in v;
            for (L = 0, R = v.size() - 1; L <= R; ) {
                M = L + (R - L)/2;
                if (nums[i] == v[M]) break;
                if (nums[i] < v[M]) R = M - 1;
                else L = M + 1;
            }
            
            if (L == v.size()) v.push_back(nums[i]);
            else if (nums[i] != v[M]) v[L] = nums[i];
        }
        
        return v.size();
    }
};

// O(n log(n))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
    
        vector<int> B(n); // LIS sequence
        int len = 1;
        B[0] = nums[0];
    
        for (int i = 1; i < n; ++ i) {
            int L = 0, R = len - 1;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (B[M] < nums[i]) L = M + 1;
                else R = M - 1;
            }
    
            B[L] = nums[i];
            if (L == len) ++ len;
        }
    
        return len;
    }
};


/**
Longest Increasing Subsequence
Difficulty: Medium

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you 
to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity? 
 */
