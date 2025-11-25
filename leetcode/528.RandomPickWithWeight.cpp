// Prefix Sums with Binary Search
// See: https://leetcode.com/problems/random-pick-with-weight/editorial/
// Time: O(log n) for pickIndex.
// Space: O(n)
class Solution {
    vector<int> prefixSums;

public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }
    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        return lower_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};


// Prefix Sums with Linear Search
// See: https://leetcode.com/problems/random-pick-with-weight/editorial/
// Time: O(n) for pickIndex.
// Space: O(n)
class Solution {
    vector<int> prefixSum;
    int total;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        if (n == 0) {
            total = 0;
            return;
        }

        prefixSum.resize(n, 0);
        prefixSum[0] = w[0];
        for (int i = 1; i < n; ++ i) {
            prefixSum[i] = prefixSum[i-1] + w[i];
        }
        total = prefixSum[n - 1];
    }
    
    int pickIndex() {
        int v = rand() % total;
        for (int i = 0; i < prefixSum.size(); ++ i) {
            if (v < prefixSum[i]) return i;
        }
        return prefixSum.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */


/**
528. Random Pick with Weight
Medium

You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] 
(inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

    For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the 
    probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
 */
