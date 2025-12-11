// Same as Solution2.
class Solution3 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (arr[mid] - (mid + 1) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;
    }
};

// From: https://leetcode.com/problems/kth-missing-positive-number/editorial/
// Binary search.
// O(log n) time.
// O(1) space.
class Solution2 {
    public int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            // If number of positive integers
            // which are missing before arr[pivot]
            // is less than k -->
            // continue to search on the right.
            if (arr[pivot] - pivot - 1 < k) {
                left = pivot + 1;
            // Otherwise, go left.
            } else {
                right = pivot - 1;
            }
        }

        // At the end of the loop, left = right + 1,
        // and the kth missing is in-between arr[right] and arr[left].
        // The number of integers missing before arr[right] is
        // arr[right] - right - 1 -->
        // the number to return is
        // arr[right] + k - (arr[right] - right - 1) = k + left
        return left + k;
    }
}

// From: https://leetcode.com/problems/kth-missing-positive-number/editorial/
// O(n) time.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int num : arr) {
            if (num <= k) ++ k;
            else break;
        }
        return k;
    }
};


/**
1539. Kth Missing Positive Number
Easy

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 */
