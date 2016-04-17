// NOTE: cannot use unordered_map. Must use map!
// Or there is compile error.
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Comp {
public:
    bool operator()(const Point & a, const Point & b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
};

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 1) return points.size(); // ok without this.
        
        vector<Point> pts;
        map<Point, int, Comp> ptsCount;
        for (auto p : points) {
            ptsCount[p] ++;
            if (ptsCount[p] == 1) pts.push_back(p);
        }
        
        if (pts.size() <= 1) return points.size();
        
        map<vector<double>, vector<Point>> mpt;
        map<vector<double>, int> mct;
        
        for (int i = 0; i < pts.size() - 1; ++ i) {
            for (int j = i + 1; j < pts.size(); ++ j) {
                Point & a = pts[i], & b = pts[j];
                
                vector<double> line(2);
                if (a.x == b.x) {
                    line[0] = INT_MAX;
                    line[1] = a.x;
                }
                else {
                    line[0] = 1.0 * (a.y - b.y) / (a.x - b.x);
                    line[1] = a.y - a.x * line[0];
                }
                
                if (! find(mpt[line], a)) {
                    mpt[line].push_back(a);
                    mct[line] += ptsCount[a];
                }
                if (! find(mpt[line], b)) {
                    mpt[line].push_back(b);
                    mct[line] += ptsCount[b];
                }
            }
        }
        
        int maxCt = 0;
        for (auto m : mct) maxCt = max(maxCt, m.second);
        return maxCt;
    }
    
    bool find(vector<Point> & v, Point & pt) {
        for (auto p : v) {
            if (p.x == pt.x && p.y == pt.y) return true;
        }
        return false;
    }
};


/**
Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that 
lie on the same straight line.

Example

Given 4 points: (1,2), (3,6), (0,0), (1,3).

The maximum number is 3.

 */
