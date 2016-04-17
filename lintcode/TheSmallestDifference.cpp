// Idea: sort, and merge sort.
class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int minDiff = INT_MAX;
        for (int i = 0, j = 0; i < A.size() && j < B.size(); ) {
            if (A[i] < B[j]) {
                minDiff = min(minDiff, B[j] - A[i ++]);
            }
            else {
                minDiff = min(minDiff, A[i] - B[j ++]);
            }
        }
        return minDiff;
    }
};



/**
The Smallest Difference

Given two array of integers(the first array is array A, the second array 
is array B), now we are going to find a element in array A which is A[i], 
and another element in array B which is B[j], so that the difference between 
A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their 
smallest difference.

Example

For example, given array A = [3,6,7,4], B = [2,8,9,3], return 0
Challenge

O(n log n) time

 */
