class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size() - 1;
        for (--m, --n; m >= 0 && n >= 0; ) {
            nums1[k --] = nums1[m] > nums2[n] ? nums1[m --] : nums2[n --];
        }
        while (n >= 0) {
            nums1[k --] = nums2[n --];
        }
    }
};

//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

// Works too.
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        for (-- m, -- n; m >= 0 && n >= 0; ) {
            if (nums1[m] > nums2[n]) {
                nums1[i --] = nums1[m --];
            } else {
                nums1[i --] = nums2[n --];
            }
        }

        while (n >= 0) {
            nums1[i --] = nums2[n --];
        }
    }
};

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // merge B into A. backward.[m --]
        int k = m + n - 1;
        -- n, -- m;
        while (n >= 0 && m >= 0) {
            if (A[m] > B[n]) A[k --] = A[m --];
            else A[k --] = B[n --];
        }
        
        //while (m >= 0) {} // do nothing
        while (n >= 0) { A[k --] = B[n --]; }
    }
};

