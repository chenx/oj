// https://leetcode.com/problems/russian-doll-envelopes/editorial/
// Time complexity : O(NlogN), where N is the length of the input. Both sorting the array and finding the LIS happen in O(NlogN).
// Space complexity : O(N)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);

        int n = envelopes.size();
        vector<int> secondDim(n);
        for (int i = 0; i < n; ++i) secondDim[i] = envelopes[i][1];
        return lengthOfLIS(secondDim);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> v;
        v.push_back(nums[0]);

        for (int i = 1; i < n; ++ i) {
            if (nums[i] > v[v.size()-1]) {
                v.push_back(nums[i]);
            } else {
                int L = 0, R = v.size()-1;
                while (L <= R) {
                    int M = L+(R-L)/2;
                    if (nums[i] > v[M]) L = M+1;
                    else R = M-1;
                }

                v[L] = nums[i];
            }
        }
        return v.size();
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
};

/**
354. Russian Doll Envelopes
Hard

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and 
the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater 
than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
 */
