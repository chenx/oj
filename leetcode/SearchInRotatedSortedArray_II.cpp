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
