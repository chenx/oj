// Works. O(n+m). Use set to avoid duplicate automatically.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (auto n : nums1) s.insert(n); 
        
        set<int> ans;
        for (auto n : nums2) {
            if (s.find(n) != s.end()) ans.insert(n);
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};


/**
Intersection of Two Arrays
Difficulty: Easy

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.
*/
