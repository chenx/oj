class Solution2 {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<vector<int>> projects; // <capital, profit>
        for (int i = 0; i < n; ++ i) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end()); // by capital, profit

        priority_queue<int> maxHeap;
        for (int i = 0, p = 0; i < k; ++ i) {
            for (; p < n && projects[p][0] <= w; ++ p) {
                maxHeap.push(projects[p][1]);
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};

// Works.
// From: https://leetcode.com/problems/ipo/editorial/?envType=study-plan-v2&envId=top-interview-150
// Complexity: Time: O(n log(n)), Space: O(n).
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end(), comp);
        priority_queue<int> q;
        int ptr = 0;
        for (int i = 0; i < k; i++) {
            while (ptr < n && projects[ptr].first <= w) {
                q.push(projects[ptr++].second);
            }
            if (q.empty()) {
                break;
            }
            w += q.top();
            q.pop();
        }
        return w;
    }

    static int comp(pair<int, int>&a, pair<int, int>&b) {
        return a.first < b.first;
    }
};

/**
502. IPO

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, 
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited 
resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best 
way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of 
capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit 
will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return 
the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
 */
