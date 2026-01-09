// Best answer. From Leetcode 101 - A grinding guide.
class Solution9 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int left = 1, right = n-2;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            } else if (nums[mid] > nums[mid-1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};


class Solution8 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid == 0 && nums[0] > nums[1]) return 0;
            if (mid == n-1 && nums[n-1] > nums[n-2]) return n-1;
            if (mid > 0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            // if (nums[mid] > nums[mid+1]) right = mid-1;
            if (mid < n-1 && nums[mid] > nums[mid+1]) right = mid-1;
            else left = mid+1;
        }
        return 0; // don't matter
    }
};

// Works. Test. Best.
// Previous test cases has error for test case [3,4,3,2,1].
class Solution7 {
public:
    int findPeakElement(vector<int>& num) {
        int n = num.size();
        if (n <= 1) return 0;
        if (n == 2) return (num[0] > num[1] ? 0 : 1);
        
        int L = 0, R = n - 1;
        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0 && num[0] > num[1]) return 0;
            if (M == n-1 && num[n-1] > num[n-2]) return n-1;
            if (M > 0 && M < n-1 && num[M] > num[M-1] && num[M] > num[M+1]) return M;
            
            if (num[M] < num[M+1]) L = M+1;
            else R = M; // R = M-1 also works.
        }
        return 0; // does not matter.
    }
};

// Works. Easy to understand. Logically sound.
// But fails for test case [3,4,3,2,1]
class Solution6 {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;
        if (n == 2) return (num[0] > num[1] ? 0 : 1);
        
        int L = 0, R = n - 1;
        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0 && num[0] > num[1]) return 0;
            else if (M == n-1 && num[n-1] > num[n-2]) return n-1;
            else if (num[M] > num[M-1] && num[M] > num[M+1]) return M;
            
            if (num[M] < num[M+1]) L = M+1;
            else R = M-1;
        }
        
        return 0; // does not matter.
    }
};

// Tested. Works. Should be most correct logically (check boundary).
class Solution5 {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return n-1;
        
        int L = 0, R = n-1;
        while (L <= R) {
            int M = L + (R-L)/2;
            
            if (M == 0 && num[0] > num[1]) return 0;
            else if (M == n-1 && num[n-1] > num[n-2]) return n-1;
            else if (M > 0 && M < n-1 && num[M] > num[M-1] && num[M] > num[M+1]) return M;
            
            if (M < n-1 && num[M] < num[M+1]) L = M+1;
            else R = M-1;
        }
        
        return 0;
    }
};

// Works too. Tested.
class Solution4 {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return n-1;
        
        int L = 0, R = n - 1;
        while (L <= R) {
            int M = L + (R-L)/2;
            
            if (M == 0 && num[0] > num[1]) return 0;
            if (M == n-1 && num[n-1] > num[n-2]) return n-1;
            if (num[M-1] < num[M] && num[M] > num[M+1]) return M;
            
            //if (M < n-1 && num[M] < num[M+1]) L = M+1; // works too.
            if (num[M] < num[M+1]) L = M+1;
            else R = M-1;
        }
        
        return 0;
    }
};

// This works too.
class Solution3 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), L = 0, R = n - 1, M;
        
        while (L <= R) {
            M = L + (R - L)/2;
            if (M == 0 && nums[0] > nums[1]) return 0;
            else if (M == n-1 && nums[n-1] > nums[n-2]) return n-1;
            else if (nums[M-1] < nums[M] && nums[M] > nums[M+1]) return M;
            
            if (M > 0 && nums[M-1] > nums[M]) R = M - 1;
            else L = M + 1;
        }
        
        return 0; // "return R;" works too.
    }
};

// This works.
class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int L = 0, R = n - 1;

        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0) { if (nums[0] > nums[M+1]) return 0; }
            else if (M == n - 1) { if (nums[M] > nums[M-1]) return n - 1; }
            else if (nums[M] > nums[M-1] && nums[M] > nums[M+1]) { return M; }
            
            if (M < n - 1 && nums[M] < nums[M + 1]) L = M + 1;
            else R = M - 1; // same as: else if (num[M] < num[M - 1]) R = M - 1;
            
            // This works too. 
            //if (M > 0 && nums[M] < nums[M - 1]) R = M - 1;
            //else L = M + 1;
        }
        
        return 0;        
    }
};

//
// This works.
//
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;

        int L = 0, R = n - 1;

        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0 && num[0] > num[M+1]) { return 0; }
            else if (M == n - 1 && num[M] > num[M-1]) { return n - 1; }
            else if (num[M] > num[M-1] && num[M] > num[M+1]) { return M; }
            
            if (M < n - 1 && num[M] < num[M + 1]) L = M + 1;
            else R = M - 1; // same as: else if (num[M] < num[M - 1]) R = M - 1;
        }
        
        return 0;
    }
};


/**
Find Peak Element 
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note:
Your solution should be in logarithmic complexity.
 */
