// From: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/editorial/
// Time: O(n) worst case, O(logn) best case.
// Space: O(1)
class Solution2 {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int end = n - 1, start = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }

            // which array does pivot belong to.
            bool pivotArray = nums[start] <= nums[mid];
            // which array does target belong to.
            bool targetArray = nums[start] <= target;

            if (pivotArray ^ targetArray) {
                // If pivot and target exist in different sorted arrays, recall 
                // that xor is true only when both the operands are distinct
                if (pivotArray) {
                    start = mid + 1;  // pivot in the first, target in the second
                } else {
                    end = mid - 1;  // target in the first, pivot in the second
                }
            } else {  // If pivot and target exist in same sorted array
                if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

class Solution {
public:
    // O(n).
    // From: http://askmecode.wordpress.com/2012/09/11/search-in-rotated-sorted-array-ii/
    // Reference: http://leetcode.com/2010/04/searching-element-in-rotated-array.html
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        
        while (left <= right) {
            mid = (right - left) / 2 + left;
            
            if (A[mid] == target) {
                return true;
            }
            else if (A[left] < A[mid]) { // left side is sorted.
                if (target >= A[left] && target < A[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else if (A[left] > A[mid]) { // right side is sorted.
                if (target <= A[right] && target > A[mid]) left = mid + 1;
                else right = mid - 1;
            }
            else {
                left ++;
            }
        }        
        return false;
    }
};

