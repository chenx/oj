// This works too.
class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] == nums[i-1]) return true;
        }
        
        return false;
    }
};

// This works too.
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0, len = nums.size(); i < len; ++ i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

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
