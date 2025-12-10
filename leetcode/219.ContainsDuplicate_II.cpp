// See: https://leetcode.com/problems/contains-duplicate-ii/editorial/
// Time: O(n)
// Space: O(min(n, k))
class Solution4 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.contains(nums[i])) return true;
            set.insert(nums[i]);
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }
};

// Works.
class Solution3 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++ i) {
            if (m.contains(nums[i])) {
                if (i - m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

// Works. Easier to understand.
class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i ++) {
            int n = nums[i];
            if (m.find(n) == m.end()) {
                m[n] = i;
            } else {
                if (i - m[n] <= k) return true;
                else m[n] = i;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> h; // (value, index) pairs.
        for (int i = 0, n = nums.size(); i < n; ++ i) {
            if (h[nums[i]] > 0 && (i + 1 - h[nums[i]] <= k)) return true;
            h[nums[i]] = i + 1; // update index.
        }
        
        return false;
    }
};

/*
Contains Duplicate II

Given an array of integers and an integer k, find out whether there are 
two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k. 
*/
