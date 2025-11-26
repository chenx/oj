// From: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/editorial/
// Use in-place modification.
// Time: O(n)
// Space: O(1)
class Solution3 {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int minValue = *std::min_element(arr.begin(), arr.end());
        int maxValue = *std::max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;
        
        while (i < n) {
            // If arr[i] is at the correct index, move on.
            if (arr[i] == minValue + i * diff) {
                i += 1;
                
            // If arr[i] doesn't belong to this arithmetic sequence, return false.
            } else if ((arr[i] - minValue) % diff != 0) {
                return false;
                
            // Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            } else {
                int j = (arr[i] - minValue) / diff;
                
                // If we find duplicated elements, return False.
                if (arr[i] == arr[j]) {
                    return false;
                }
                
                // Swap arr[i] with arr[j].
                swap(arr[i], arr[j]);
            }
        }
        
        return true;
    }
};


// From: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/editorial/
// Use set.
// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int minValue = *min_element(arr.begin(), arr.end());
        int maxValue = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if (maxValue - minValue == 0) {
            return true;
        }
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        unordered_set<int> numberSet;
        
        for (int i = 0; i < n; i++) {
            if ((arr[i] - minValue) % diff != 0) {
                return false;
            }
            numberSet.insert(arr[i]);
        }
        
        return numberSet.size() == n;
    }
};

// Time: O(n * logn)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return false;

        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for (int i = 2; i < n; ++ i) {
            if (arr[i] - arr[i-1] != diff) return false;
        }
        return true;
    }
};


/**
1502. Can Make Arithmetic Progression From Sequence
Easy

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

 

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 */
