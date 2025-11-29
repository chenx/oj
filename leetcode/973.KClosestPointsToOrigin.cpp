// Quick Select.
// See: https://leetcode.com/problems/k-closest-points-to-origin/editorial/
// O(n) time.
// O(1) space.
class Solution4 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();
        while (pivotIndex != k) {
            // Repeatedly partition the vector while narrowing in on the kth element.
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    };

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist) left++;
        return left;
    };

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
    
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};


class Solution3 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [&](vector<int> a, vector<int> b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);

        for (auto point : points) {
            maxHeap.push(point);
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> result;
        while (! maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};


// Time complexity: O(N⋅logk)
// Space complexity: O(k)
class Solution2 {
    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> maxHeap;

        for (auto point : points) {
            maxHeap.push(point);
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> result;
        while (! maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};


struct comp {
    bool operator()(pair<vector<int>, int>&a, pair<vector<int>, int>&b) {
        return a.second < b.second;
    }
};

class Solution {
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


/**
973. K Closest Points to Origin
Medium

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 */
