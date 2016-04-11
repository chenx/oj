//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/12/2012
// @Last modified: 12/13/2012
//

// Works. 
// Use new specification: index is 0-based.
class Solution6 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m; // value,index
        for (int i = 0; i < n; ++ i) {
            if (m.find(nums[i]) == m.end()) m[target - nums[i]] = i;
            else return vector<int>({m[nums[i]], i});
        }
        return vector<int>({-1, -1});
    }
};    
    
// Be careful of the use of map<int, int>, its iterator, insert, and first/second.
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> s;
        for (int i = 0; i < numbers.size(); i ++) {
            map<int, int>::iterator it = s.find(numbers[i]);
            if (it != s.end()) {
                result.push_back((*it).second + 1);
                result.push_back(i + 1);                    
                //return result;
            }
            else {
                s.insert(pair<int, int>(target - numbers[i], i));
            }
        }
        return result;
    }
};


//
// This also works, and is better in syntax.
//
class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        unordered_map<int, int> ht; // [num, index]
        
        for (int i = 0; i < numbers.size(); ++ i) {
            if (ht.find(numbers[i]) != ht.end()) {
                ans.push_back(ht[numbers[i]] + 1);
                ans.push_back(i+1);
                break;
            }
            else {
                ht[target - numbers[i]] = i;
            }
        }
        
        return ans;
    }
};

// Both functions in this class work. 1/23/2016
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        
        unordered_map<int, int> m; // (value, index)
        for (int i = 0; i < nums.size(); ++ i) {
            if (m.find(nums[i]) != m.end()) {
                v.push_back(m[nums[i]]);
                v.push_back(i+1);
                break;
            }
            else {
                m[target - nums[i]] = i + 1;
            }
        }
        
        return v;
    }
    
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> v;
        
        unordered_map<int, int> m; // (value, index)
        for (int i = 0; i < nums.size(); ++ i) {
            if (m.find(target - nums[i]) != m.end()) {
                v.push_back(m[target - nums[i]]);
                v.push_back(i+1);
                break;
            }
            else {
                m[nums[i]] = i + 1;
            }
        }
        
        return v;
    }
};

// Works. Tested.
class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // num, index
        
        for (int i = 0; i < nums.size(); ++ i) {
            if (! m.count(nums[i])) { 
            // if (m.find(nums[i]) == m.end()) { // this works too.
                m[target - nums[i]] = i;
            }
            else {
                return vector<int>({m[nums[i]], i});
            }
        }
        
        return vector<int>();
    }
};


// Works. Tested.
// Sort, then run 2 points towards each other. O(nlog(n)).
// But not recommended, for both efficiency and conciseness.
class Solution5 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<pair<int, int>> m; // num, index
        for (int i = 0; i < n; ++ i) {
            m.push_back(pair<int, int>(nums[i], i));
        }
        
        sort(m.begin(), m.end(), comp);
        
        int L = 0, R = n - 1;
        while (L < R) {
            int sum = m[L].first + m[R].first;
            if (sum == target) return vector<int>({m[L].second, m[R].second});
            else if (sum < target) ++ L;
            else -- R;
        }
        
        return vector<int>();
    }
    
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }
};



/**
Two Sum
Difficulty: Medium

Given an array of integers, find two numbers such that they add up 
to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. Please 
note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
 */
