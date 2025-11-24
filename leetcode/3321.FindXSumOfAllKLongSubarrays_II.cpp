// From: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/editorial/
// 
// Time complexity: O(nlogn).
// Each insertion or removal operation on an ordered set takes O(logn) time. Since every element in the array nums 
// triggers only a constant number of such operations, the overall time complexity is O(nlogn).
//
// Space complexity: O(n).
// It is the space required for ordered set and hash table.
//
class Helper {
public:
    Helper(int x) {
        this->x = x;
        this->result = 0;
    }

    void insert(int num) {
        if (occ[num]) {
            internalRemove({occ[num], num});
        }
        ++occ[num];
        internalInsert({occ[num], num});
    }

    void remove(int num) {
        internalRemove({occ[num], num});
        --occ[num];
        if (occ[num]) {
            internalInsert({occ[num], num});
        }
    }

    long long get() { return result; }

private:
    void internalInsert(const pair<int, int>& p) {
        if (large.size() < x || p > *large.begin()) {
            result += static_cast<long long>(p.first) * p.second;
            large.insert(p);
            if (large.size() > x) {
                result -= static_cast<long long>(large.begin()->first) *
                          large.begin()->second;
                auto transfer = *large.begin();
                large.erase(transfer);
                small.insert(transfer);
            }
        } else {
            small.insert(p);
        }
    }

    void internalRemove(const pair<int, int>& p) {
        if (p >= *large.begin()) {
            result -= static_cast<long long>(p.first) * p.second;
            large.erase(p);
            if (!small.empty()) {
                result += static_cast<long long>(small.rbegin()->first) *
                          small.rbegin()->second;
                auto transfer = *small.rbegin();
                small.erase(transfer);
                large.insert(transfer);
            }
        } else {
            small.erase(p);
        }
    }

private:
    int x;
    long long result;
    set<pair<int, int>> large, small;
    unordered_map<int, int> occ;
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Helper helper(x);

        vector<long long> ans;
        for (int i = 0; i < nums.size(); ++i) {
            helper.insert(nums[i]);
            if (i >= k) {
                helper.remove(nums[i - k]);
            }
            if (i >= k - 1) {
                ans.push_back(helper.get());
            }
        }
        return ans;
    }
};


/**
3321. Find X-Sum of All K-Long Subarrays II
Hard

You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

    Count the occurrences of all elements in the array.
    Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, 
        the element with the bigger value is considered more frequent.
    Calculate the sum of the resulting array.

Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the

nums[i..i + k - 1].

 

Example 1:

Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

Output: [6,10,12]

Explanation:

    For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
    For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. 
        Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
    For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

Example 2:

Input: nums = [3,8,7,8,7,5], k = 2, x = 2

Output: [11,15,15,15,12]

Explanation:

Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 */
