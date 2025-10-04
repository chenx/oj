class comp {
public:
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string& word : words) ++ mp[word];

        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> minHeap;

        int i = 0;
        for (auto& entry : mp) {
            minHeap.push(pair<string, int>(entry));
            mp.erase(entry.first);
            if (++ i == k) break;
        }
        for (auto& entry : mp) {
            if (entry.second > minHeap.top().second) {
                minHeap.pop();
                minHeap.push(pair<string, int>(entry));
            }
        }

        vector<string> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
692. Top K frequent words

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with 
the same frequency by their lexicographical order.
 */
