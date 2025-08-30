// Version 2. Works too.
class comp {
public:
   bool operator()(const vector<int> & a, const vector<int> & b) {
       return a[1] > b[1];
   }
};

class Solution2 {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> m;  // num, count
       for (int num : nums) m[num] ++;


       // Use minQ, so numbers with lower count are removed.
       priority_queue<vector<int>, vector<vector<int>>, comp> minQ;
       for (auto e : m) {
           // vector<int> v(2);
           // v[0] = e.first; v[1] = e.second;
           minQ.push({e.first, e.second});
           if (minQ.size() > k) minQ.pop();
       }


       vector<int> ans;
       while (!minQ.empty()) {
           ans.push_back(minQ.top()[0]);
           minQ.pop();
       }
       return ans;
   }
};


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
