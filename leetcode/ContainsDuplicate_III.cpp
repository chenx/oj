// This works. O(n^2). O(nlog(n)) if nums array is not filled mostly with the same number.
// See: https://leetcode.com/discuss/74439/c-20-ms-solution-beat-95%25
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() <= 1) return false;
        int n = nums.size();
        
        vector<pair<long, int>> v;
        for (int i = 0; i < n; ++ i) v.push_back(pair<long, int>(nums[i], i));
        sort(v.begin(), v.end(), comp);
        
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                if (v[j].first - v[i].first > t) break; // cut branch.
                if (abs(v[j].second - v[i].second) <= k) return true; // use "abs()" here.
            }
        }
        
        return false;
    }
    
    static bool comp(const pair<long, int> &a, const pair<long, int> &b) {
        return a.first < b.first;
    }
};


// This works, but times out for large input. O(n^2).
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                if (abs(nums[i] - nums[j]) <= t && j - i <= k) return true;
            }
        }
        return false;
    }
};


/**
Contains Duplicate III
Difficulty: Medium

Given an array of integers, find out whether there are two distinct indices i and j 
in the array such that the difference between nums[i] and nums[j] is at most t and 
the difference between i and j is at most k. 
 */
