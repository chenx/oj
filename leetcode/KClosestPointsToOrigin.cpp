struct comp {
    bool operator()(pair<vector<int>, int>& a, pair<vector<int>, int>& b) {
        return a.second < b.second;
    }
};

// Better than Solution 1.
class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, comp> maxHeap;

        for (int i = 0; i < points.size(); ++ i) {
            auto p = points[i];
            maxHeap.push({ p, p[0]*p[0] + p[1]*p[1] });
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ans;
        while (! maxHeap.empty()) {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, comp> maxHeap;

        int i = 0, len = (points.size() > k) ? k : points.size();
        for (; i < len; ++ i) {
            auto point = points[i];
            int dist = point[0]*point[0] + point[1]*point[1];
            maxHeap.push(pair<vector<int>, int>(points[i], dist));
        }

        for (int i = len; i < points.size(); ++ i) {
            auto point = points[i];
            int dist = point[0]*point[0] + point[1]*point[1];
            if (dist < maxHeap.top().second) {
                maxHeap.pop();
                maxHeap.push(pair<vector<int>, int>(points[i], dist));
            }
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;
    }
};

/**
973. K Closest Points To Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 */
