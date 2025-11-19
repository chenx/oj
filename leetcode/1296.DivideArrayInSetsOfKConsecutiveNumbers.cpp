// From: https://algo.monster/liteproblems/1296
// Time: O(n*log(n) + n*k)
// Space: O(n)
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        sort(nums.begin(), nums.end());

        map<int, int> frequency;
        for (int num : nums) ++ frequency[num];

        for (int num : nums) {
            if (frequency.contains(num)) {
                for (int i = num; i < num + k; ++ i) {
                    if (! frequency.contains(i)) return false;

                    -- frequency[i];
                    if (frequency[i] == 0) frequency.erase(i);
                }
            }
        }
        return true;
    }
};

/**
1296. Divide Array in Sets of K Consecutive Numbers
Medium

Given an array of integers nums and a positive integer k, check whether it is possible to divide this array 
into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.
 */
