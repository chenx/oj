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
