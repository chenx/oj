class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> h;
        for (int i = 0, n = nums.size(); i < n; ++ i) {
            if (h[nums[i]] == 1) return true;
            ++ h[nums[i]];
        }
        
        return false;
    }
};

/*
Contains Duplicate 

Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct. 
 */
