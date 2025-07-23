//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

class Solution2 {
public:
   int searchInsert(vector<int>& nums, int target) {
       int L = 0, R = nums.size() - 1;


       while (L <= R) {
           int mid = L + (R - L)/2;
           if (nums[mid] == target) return mid;
           else if (nums[mid] < target) ++ L;
           else -- R;
       }


       return L;
   }
};


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return left;
    }
};
