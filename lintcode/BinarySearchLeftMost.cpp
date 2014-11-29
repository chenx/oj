//
// This works.
//
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int L = 0, R = array.size(), ret = -1;
        
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (array[M] <= target - 1) {
                L = M + 1;
                ret = M;
            }
            else {
                R = M - 1;
            }
        }
        
        ret += 1;
        
        if (ret >= 0 && ret < array.size() && array[ret] == target) return ret;
        return -1;
    }
};

/**
Binary Search 

Binary search is a famous question in algorithm.

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

E.g.,
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge:
If the count of numbers is bigger than MAXINT, can your code work properly?
answer: use long long type for L and R.
 */
