class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        int i1 = 0, i2 = 0, i3 = 0;
        while (i1 < arr1.size() && i2 < arr2.size() && i3 < arr3.size()) {
            if (arr1[i1] == arr2[i2] && arr1[i1] == arr3[i3]) {
                result.push_back(arr1[i1]);
                ++ i1, ++ i2, ++ i3;
            } else {
                int minElem = min(arr1[i1], min(arr2[i2], arr3[i3]));
                if (arr1[i1] == minElem) ++ i1;
                else if (arr2[i2] == minElem) ++ i2;
                else ++ i3;
            }
        }
        return result;
    }
};

/**
1213. Intersection of Three Sorted Arrays
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, 
return a sorted array of only the integers that appeared in all three arrays.

 

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

Example 2:

Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []
 */
