// Should work. Not tested in lc. Self-tested for n = 1 to 100.
// By: XC. 3/4/2016
class Solution4 {
public:
    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > ans;
        vector<int> v;
        helper(ans, n, v);
        return ans;
    }

    void helper(vector<vector<int> > &ans, int n, vector<int> &v) {
        for (int i = 2; i * i <= n; ++ i) {
            if (n % i == 0) {
                if (! v.empty() && i < v.back()) continue;
                vector<int> u = v;
                u.push_back(i);
                ans.push_back(u);
                ans.back().push_back(n/i);
                helper(ans, n/i, u);
            }
        }
    }
};


// Should work. Tested locally, not in lc.
class Solution3 {
public:
    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > ans;

        for (int i = 2; i * i <= n; ++ i) {
            if (n % i != 0) continue;

            vector<int> v(2); v[0] = i; v[1] = n / i;
            ans.push_back(v);

            vector<vector<int> > tmp = getFactors(n / i);
            for (int j = 0; j < tmp.size(); ++ j) {
                vector<int> & t = tmp[j];
                if (i <= t[0]) {
                    t.insert(t.begin(), i);
                    ans.push_back(t);
                }
            }
        }

        return ans;
    }
};


// Works. Tested. Simplified from Solution.
// Easiest to understand so far.
class Solution2 {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > ans;
        for (int i = 2; i * i <= n; i++) {
            if (n % i != 0) continue;

            ans.push_back(vector<int> {i, n / i});
            auto tmp = getFactors(n / i); // tmp: vector<vector<int>>
            for (auto j : tmp) {          // j: vector<int>
                if (i <= j.front()) {
                    j.insert(j.begin(), i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

// Works. Tested. From: https://leetcode.com/discuss/66903/share-my-short-c-solution
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > ans;
        for (int i = 2; i * i <= n; i++) {
            if (n % i != 0) {
                continue;
            }
            ans.push_back(vector<int> {i, n / i});
            auto tmp = getFactors(n / i); // vector<vector<int>>
            for (auto j : tmp) {          // j: vector<int>
                j.push_back(i);
                sort(j.begin(), j.end());
                if (find(ans.begin(), ans.end(), j) == ans.end()) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

/**
Factor Combinations
Difficulty: Medium

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible 
combinations of its factors.

Note: 
Each combination's factors must be sorted ascending, for example: 
The factors of 2 and 6 is [2, 6], not [6, 2].

You may assume that n is always positive.
Factors should be greater than 1 and less than n.

Examples: 
input: 1
output: 
[]

input: 37
output: 
[]

input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 */
