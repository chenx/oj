// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return false;

        set<vector<int>> pointSet;
        int minX = INT_MAX, maxX = INT_MIN;
        for (auto& p : points) {
            pointSet.insert(p);
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
        }

        double midX = (minX + maxX) / 2.0;
        
        for (const auto& p : points) {
            int reflectionX = (midX > p[0]) ? (p[0] + 2*(midX - p[0])) : (p[0] - 2*(p[0] - midX));
            vector<int> reflection = {reflectionX, p[1]};
            if (! pointSet.contains(reflection)) return false;
        }
        return true;
    }
};


/**
356. Line Reflection
Medium

Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points 
symmetrically.

In other words, answer whether or not if there exists a line that after reflecting all points over the given line, 
the original points' set is the same as the reflected ones.

Note that there can be repeated points.
 */
