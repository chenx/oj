// Time: O(nlog(n) + m)
// Space: O(m)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> positionMap; // <element, position in arr2>
        for (int i = 0; i < arr2.size(); ++ i) positionMap[arr2[i]] = i;  // O(m) Time/Space.

        auto comp = [&](int a, int b) { // pass in position by reference. O(n) Time.
            if (positionMap.contains(a) && positionMap.contains(b)) {
                return positionMap[a] < positionMap[b];
            } else if (positionMap.contains(a)) {
                return true; // a < b
            } else if (positionMap.contains(b)) {
                return false; // a > b
            } else {
                return a < b;
            }
        };
        sort(arr1.begin(), arr1.end(), comp);
        return arr1;
    }
};


/**
1122. Relative Sort Array
Easy

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 */
