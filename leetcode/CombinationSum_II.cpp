//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//
// Note: one more optimization for this is:
// when target is larger than the sum of all elements in num, then always return empty set.
//


// Works. 
// Same as Solution8 of CombinationSum.cpp, with minor modifications 1) and 2) shown below.
class Solution5 {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        if (cand.size() == 0) return vector<vector<int>>();
        
        // 1) the 5 lines below are addition from CombinationSum.cpp.
        vector<int> candidates;
        unordered_map<int, int> count;
        for (auto c : cand) {
            if (++ count[c] == 1) candidates.push_back(c);
        }
        sort(candidates.begin(), candidates.end());
        
        vector<vector<vector<int>>> ans(1 + target);

        for (int i = 1; i <= target; ++ i) {
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i < candidates[j]) break;
                else if (i == candidates[j]) {
                    vector<int> v(1, i);
                    ans[i].push_back(v);
                    break;
                }
                else {
                    vector<vector<int>> & u = ans[i - candidates[j]];
                    for (int k = 0, len = u.size(); k < len; ++ k) {
                        if (candidates[j] >= u[k].back() && 
                                getCount(u[k], candidates[j]) < count[candidates[j]]) {
                                // 2) the getCount() above is addition from CombinationSum.cpp.
                            ans[i].push_back(u[k]);
                            ans[i].back().push_back(candidates[j]);
                        }
                    }
                }
            }
        }
        
        return ans[target];
    }
    
    int getCount(vector<int> & v, int c) {
        int ct = 0;
        for (int val : v) {
            if (val == c) ++ ct;
        }
        return ct;
    }
};

// Modified from the solution of CombinationSum.
// From: https://github.com/anson627/leetcode/blob/master/CombinationSum/CombinationSum.cpp
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if (num[0] > target) return result;
        vector<int> combination;
        combinationSumHelper(num, target, 0, combination, result);
        return result;
    };

    void combinationSumHelper(vector<int> &num, int target, int i, vector<int> combination, vector<vector<int> > &result) {
        if (target < 0) return;
        if (target == 0) {
                if (find(result.begin(), result.end(), combination) == result.end())
                    result.push_back(combination);
            return;
        }
        if (i == num.size()) return;
        
        combinationSumHelper(num, target, i + 1, combination, result); 
        if ( num[i] <= target ) {
            combination.push_back(num[i]);
            combinationSumHelper(num, target - num[i], i + 1, combination, result);
        }
        
    };
};


// This works if candidates contain no duplication.
// The only change from CombinationSum I is from "if (w[k].back() <= candidates[j])"
// to "if (w[k].back() < candidates[j])".
class Solution2 {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans;
        
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i <= target; ++ i) {
            vector<vector<int> > row;
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i < candidates[j]) continue;
                if (i == candidates[j]) {
                    vector<int> v;
                    v.push_back(i);
                    row.push_back(v);
                    break;
                }
                vector<vector<int> > w = ans[i - candidates[j]];
                if (w.size() > 0) {
                    for (int k = 0; k < w.size(); ++ k) {
                        if (w[k].back() < candidates[j]) {
                            w[k].push_back(candidates[j]);
                            row.push_back(w[k]);
                        }
                    }
                }
            }
            ans.push_back(row);
        }
        return ans[target];
    }
};


// This works!
// Modified from Solution2. Get count of each elem.
// when insert, check if such elem has been used up.
// NOTE: need to check to make sure a combination does not exist!
class Solution3 {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans;
        
        sort(candidates.begin(), candidates.end());
        
        map<int, int> ct;
        for (int i = 0; i < candidates.size(); ++ i) ++ ct[candidates[i]]; // count.
        
        for (int i = 0; i <= target; ++ i) {
            vector<vector<int> > row;
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i < candidates[j]) continue;
                if (i == candidates[j]) {
                    vector<int> v;
                    v.push_back(i);
                    row.push_back(v);
                    break;
                }
                vector<vector<int> > w = ans[i - candidates[j]];
                if (w.size() > 0) {
                    for (int k = 0; k < w.size(); ++ k) {
                        if (w[k].back() <= candidates[j] && 
                            ! usedup(w[k], candidates[j], ct[candidates[j]])) {
                            w[k].push_back(candidates[j]);
                            
                            // NOTE: this check is now needed!
                            if (find(row.begin(), row.end(), w[k]) == row.end()) {
                                row.push_back(w[k]);
                            }
                        }
                    }
                }
            }
            ans.push_back(row);
        }
        return ans[target];
    }
    
    bool usedup(vector<int> &w, int v, int ct) {
        for (int i = w.size() - 1; i >= 0; -- i) {
            if (w[i] != v) break;
            -- ct;
        }
        return ct <= 0;
    }
};


//
// This works too! 
//
class Solution4 {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans(1+target);
        
        map<int, int> ct;
        for (int i = 0; i < candidates.size(); ++ i) {
            ++ ct[candidates[i]];
        }        
        
        for (int i = 1; i <= target; ++ i) {
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i == candidates[j]) {
                    vector<int> v(1);
                    v[0] = candidates[j];
                    if (find(ans[i].begin(), ans[i].end(), v) == ans[i].end()) {
                        ans[i].push_back(v);
                        //break; // don't break, since it's possible that, e.g., [4], and [2,2]. if sorted first, then can break.
                    }
                }
                else if (i > candidates[j]) {
                    vector<vector<int> > w = ans[i - candidates[j]];
                    for (int k = 0; k < w.size(); ++ k) {
                        vector<int> v = w[k];
                        if (ct[candidates[j]] == getCt(v, candidates[j])) {
                            continue;
                        }
                        v.push_back(candidates[j]);
                        sort(v.begin(), v.end());
                        if (find(ans[i].begin(), ans[i].end(), v) == ans[i].end()) 
                        {
                            ans[i].push_back(v);
                        }
                    }
                }
            } // end for
        } // end for
        
        return ans[target];
    }
    
    int getCt(vector<int> v, int val) {
        int ct = 0;
        for (int i = 0; i < v.size(); ++ i) {
            if (v[i] == val) ++ ct;
        }
        return ct;
    }
};


/**
Combination Sum II
Difficulty: Medium

Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending 
    order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 */
