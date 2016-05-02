class comp {
public:
    bool operator()(const pair<int, int> & a, const pair<int, int> & b) {
        return a.second > b.second;
    }
};

// Works. O(nlog(k)).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto n : nums) m[n] ++;
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> minQ;
        for (auto e : m) {  // klog(k) + (n-k)log(k) = nlog(k)
            minQ.push(pair<int, int>(e.first, e.second));
            if (minQ.size() > k) minQ.pop();
        }
        
        vector<int> ans;
        while (! minQ.empty()) ans.push_back(minQ.top().first), minQ.pop();
        return ans;
    }
};


/**
Top K Frequent Elements  
Difficulty: Medium

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

 */
