//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 12/27/2012
//

// NOTE: 
// for findLeftMost(), ret starts from nums.size();
// for findRightMost(), ret starts from 0.

// Works. Tested.
class Solution3 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        ans[0] = findLeftMost(nums, target);
        ans[1] = findLeftMost(nums, target + 1) - 1;
        
        if (ans[0] < 0 || ans[0] >= nums.size() || nums[ans[0]] != target) 
            ans[0] = ans[1] = -1;
            
        return ans;
    }
    
    int findLeftMost(vector<int> &nums, int target) {
        int L = 0, R = nums.size() - 1, ret = nums.size(); 
        while (L <= R) {
            int M = L + (R-L)/2;
            if (nums[M] >= target) {
                ret = M;
                R = M - 1;
            }
            else {
                L = M + 1;
            }
        }
        return ret;
    }
};

// Works. Tested.
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        ans[0] = findRightMost(nums, target - 1) + 1;
        ans[1] = findRightMost(nums, target);

        if (ans[1] < 0 || ans[1] >= nums.size() || nums[ans[1]] != target) 
            ans[0] = ans[1] = -1;
            
        return ans;
    }
    
    int findRightMost(vector<int> &nums, int target) {
        int L = 0, R = nums.size() - 1, ret = -1;
        while (L <= R) {
            int M = L + (R-L)/2;
            if (nums[M] <= target) {
                ret = M;
                L = M + 1;
            }
            else {
                R = M - 1;
            }
        }
        return ret;
    }
};

class Solution {
public:
    // Find target w/ the largest index x,
    // and find target-1 w/ the largest index y.
    // Range is then [Y+1, x]
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> v(2);
        
        v[0] = bsearch(A, 0, n-1, target - 1) + 1;
        v[1] = bsearch(A, 0, n-1, target); 
        
        if (v[1] == -1 || A[v[1]] != target) {
            v[0] = -1;
            v[1] = -1;
        }

        return v;
    }
    
    // Return the element e with the largest index, s.t. e <= k.
    // http://heartfire.cc/wp/search-for-a-range/
    int bsearch(int a[], int left, int right, int k) {
        int mid, ret = -1;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (a[mid] <= k) {
                left = mid + 1;
                ret = mid;                
            } else {
                right = mid - 1;
            }
        }
        
        return ret;
    }
    
    // This works too. Is the opposite of the above.
    vector<int> searchRange2(int A[], int n, int target) {
        vector<int> v(2);
        
        v[0]  = bsearch2(A, 0, n-1, target);
        v[1] = bsearch2(A, 0, n-1, target + 1) - 1;
        
        if (v[0] == n || A[v[0]] != target) { // note v[0] == n.
            v[0] = -1;
            v[1] = -1;
        }

        return v;
    }
    
    // Return the element e with the smallest index, s.t. e >= k.
    int bsearch2(int a[], int left, int right, int k) {
        int mid, ret = right + 1; // be careful of this!
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (a[mid] >= k) {
                right = mid - 1;
                ret = mid;                
            } else { // a[mid] >= k, note it can be =.
                left = mid + 1;
            }
        }
        
        return ret;
    }
    
};

/*
Problem: 
         
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
 */
