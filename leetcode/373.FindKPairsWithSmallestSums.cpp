// Similar to Solution. Use vector instead of pair.
//
// m is the size of nums1 and n is the size of nums2.
// Time complexity: O(min(k⋅logk,m⋅n⋅log(m⋅n)))
// Space complexity: O(min(k,m⋅n))
class Solution2 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        minHeap.push({nums1[0] + nums2[0], 0, 0});
        set<vector<int>> visited;

        for (; k > 0 && !minHeap.empty(); -- k) {
            auto top = minHeap.top();
            int sum = top[0], i = top[1], j = top[2];
            minHeap.pop();
            ans.push_back({nums1[i], nums2[j]});
    
            if (i + 1 < n1 && !visited.contains({i + 1, j})) {
                minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }
            if (j + 1 < n2 && !visited.contains({1, j + 1})) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};


// Works. Use MinHeap.
// m is the size of nums1 and n is the size of nums2.
// Time complexity: O(min(k⋅logk,m⋅n⋅log(m⋅n)))
// Space complexity: O(min(k,m⋅n))
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        set<pair<int, int>> visited;

        for (; k > 0 && !minHeap.empty(); -- k) {
            auto top = minHeap.top();
            int sum = top.first, i = top.second.first, j = top.second.second;
            minHeap.pop();
            ans.push_back({nums1[i], nums2[j]});
    
            if (i + 1 < n1 && !visited.contains(pair<int, int>{i + 1, j})) {
                minHeap.push({{nums1[i + 1] + nums2[j]}, {i + 1, j}});
                visited.insert({i + 1, j});
            }
            if (j + 1 < n2 && !visited.contains(pair<int, int>{1, j + 1})) {
                minHeap.push({{nums1[i] + nums2[j + 1]}, {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};

/**
373. Find K Pairs With Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
 */
