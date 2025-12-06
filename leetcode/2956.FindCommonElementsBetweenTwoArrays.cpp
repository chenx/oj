// Time: O(m + n)
// Space: O(m + n)
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for (int num : nums1) s1.insert(num);
        for (int num : nums2) s2.insert(num);

        vector<int> result(2, 0);
        for (int num : nums1) {
            if (s2.contains(num)) result[0] ++;
        }
        for (int num : nums2) {
            if (s1.contains(num)) result[1] ++;
        }
        return result;
    }
};


/**
2956. Find Common Elements Between Two Arrays
Easy

You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:

    answer1 : the number of indices i such that nums1[i] exists in nums2.
    answer2 : the number of indices i such that nums2[i] exists in nums1.

Return [answer1,answer2].

 

Example 1:

Input: nums1 = [2,3,2], nums2 = [1,2]

Output: [2,1]
 */
