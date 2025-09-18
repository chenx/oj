// Works too.
class Solution5 {
public:
    int maxPoints(vector<vector<int>>& points) {
        set<vector<int>> pts;

        for (auto& pt : points) pts.insert(pt);
        int n = pts.size();
        if (n <= 1) return n;
        points = vector<vector<int>>(pts.begin(), pts.end());

        map<vector<double>, set<vector<int>>> m;  // (slope, y_insection), point on line

        for (int i = 0; i < n - 1; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                vector<int> &a = points[i], &b = points[j];
                vector<double> line(2);

                if (a[0] == b[0]) {
                    line[0] = INT_MAX;
                    line[1] = a[0];
                } else {
                    line[0] = 1.0 * (b[1] - a[1]) / (b[0] - a[0]);
                    line[1] = a[1] - line[0] * a[0];
                }

                m[line].insert(a);
                m[line].insert(b);
            }
        }

        int maxVal = 0;
        for (auto& e : m) {
            if (e.second.size() > maxVal) {
                maxVal = e.second.size();
            }
        }
        return maxVal;
    }
};

// Works too. Best so far.
// Adapted from Solution3, use set instead of vector for mpt.second. 
class Solution4 {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();

        vector<vector<int>> pts;
        map<vector<int>, int> ptsCount;
        for (vector<int>& p : points) {
            ++ ptsCount[p];
            if (ptsCount[p] == 1) pts.push_back(p);
        }
        
        int n = pts.size();
        if (n == 1) return 1;

        map<vector<double>, set<vector<int>>> mpt; // (slope, y_insection), point on line
        map<vector<double>, int> mct;  // point, count

        for (int i = 0; i < n - 1; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                vector<int>& a = pts[i], &b = pts[j];

                vector<double> line(2);
                if (a[0] == b[0]) {
                    line[0] = INT_MAX;
                    line[1] = a[0];
                } else {
                    line[0] = 1.0 * (b[1] - a[1]) / (b[0] - a[0]);
                    line[1] = a[1] - line[0] * a[0];
                }

                if (!mpt[line].contains(a)) {
                    mpt[line].insert(a);
                    mct[line] += ptsCount[a]; 
                }
                if (!mpt[line].contains(b)) {
                    mpt[line].insert(b);
                    mct[line] += ptsCount[b]; 
                }
            }
        } 

        int maxCount = 0;
        for (auto e : mct) maxCount = max(maxCount, e.second);
        return maxCount;
    }
};

// Works. Tested. Sorting no needed.
// struct comp {
//     bool operator()(const vector<int>& a, const vector<int>& b) const {
//         if (a[0] == b[0]) return a[1] < b[1];
//         return a[0] < b[0];
//     }
// };

class Solution3 {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();

        vector<vector<int>> pts;
        // map<vector<int>, int, comp> ptsCount;  // no need to sort.
        map<vector<int>, int> ptsCount;
        for (vector<int>& p : points) {
            ++ ptsCount[p];
            if (ptsCount[p] == 1) pts.push_back(p);
        }
        // sort(pts.begin(), pts.end(), comparePoint); // no need to sort.
        
        int n = pts.size();
        if (n == 1) return 1;

        map<vector<double>, vector<vector<int>>> mpt; // (slope, y_insection), point on line
        map<vector<double>, int> mct;  // point, count

        for (int i = 0; i < n - 1; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                vector<int>& a = pts[i], &b = pts[j];

                vector<double> line(2);
                if (a[0] == b[0]) {
                    line[0] = INT_MAX;
                    line[1] = a[0];
                } else {
                    line[0] = 1.0 * (b[1] - a[1]) / (b[0] - a[0]);
                    line[1] = a[1] - line[0] * a[0];
                }

                if (!findPoint(mpt[line], a)) {
                    mpt[line].push_back(a);
                    mct[line] += ptsCount[a]; 
                }
                if (!findPoint(mpt[line], b)) {
                    mpt[line].push_back(b);
                    mct[line] += ptsCount[b]; 
                }
            }
        } 

        int maxCount = 0;
        for (auto e : mct) maxCount = max(maxCount, e.second);
        return maxCount;
    }

    bool findPoint(vector<vector<int>>& mpt, vector<int>& point) {
        for (auto& pt : mpt) {
            if (pt[0] == point[0] && pt[1] == point[1]) return true;
        }
        return false;
    }

    // static bool comparePoint(const vector<int>& a, const vector<int>& b) {
    //     if (a[0] == b[0]) return a[1] < b[1];
    //     return a[0] < b[0];
    // }
};

// Works too. Tested. Simplified form Solution.
// Note:
// 1) should use map instead of unordered_map, when use custom Comp.
// 2) line type should be vector<double>, not vector<int>.
struct Comp {
    bool operator()(const Point & a, const Point & b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
};

class Solution2 {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 1) return points.size();
        
        vector<Point> pts;
        map<Point, int, Comp> ptsCount;  // Note: sorting by Comp is not needed.
        for (auto p : points) {
            ptsCount[p] ++;
            if (ptsCount[p] == 1) pts.push_back(p);
            // can use below too, but less efficient.
            //if (! find(pts, p)) pts.push_back(p);
        }
        if (pts.size() == 1) return points.size();
        
        int len = pts.size();
        map<vector<double>, vector<Point>> mpt; // line(slope, y-interception), points on line.
        map<vector<double>, int> mct; // line, count of points on line.
        
        for (int i = 0; i < len - 1; ++ i) {
            for (int j = i + 1; j < len; ++ j) {
                Point &a = pts[i], &b = pts[j];
                
                vector<double> line(2);
                if (a.x == b.x) {
                    line[0] = INT_MAX;
                    line[1] = a.x;
                }
                else {
                    line[0] = 1.0 * (a.y - b.y) / (a.x - b.x);
                    line[1] = a.y - line[0] * a.x;
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
        
        int maxCount = 0;
        for (auto ct : mct) maxCount = max(maxCount, ct.second);
        return maxCount;
    }
    
    bool find(vector<Point> & pts, Point & p) {
        for (auto pt : pts) {
            if (p.x == pt.x && p.y == pt.y) return true;
        }
        return false;
    }
};
// End of Solution 2.


#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


bool find(vector<Point> s, Point p) {
    for (vector<Point>::iterator it = s.begin(); it != s.end(); ++ it) {
        if ((*it).x == p.x && (*it).y == p.y) {
            return true;
        }   
    }
    
    return false;
}

// to compare customized class Point.
struct comp {
    bool operator() (const Point &a, const Point &b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = points.size();

        // Remove duplicate points.
        map<Point, int, comp> count;
        vector<Point> pts;
        for (int i = 0; i < n; ++ i) {
            ++ count[points[i]];
            if (count[points[i]] == 1) { pts.push_back(points[i]); }
        }
        if (pts.size() == 1) { return count[points[0]]; }
        
        map<vector<double>, vector<Point> > m; // first param: Line. second param: points on line.
        map<vector<double>, int> mct; // first param: line, second param: count of points on line.
        for (int i = 0, n = pts.size(); i < n-1; ++ i) {
            for (int j = i+1; j < n; ++ j) {
                Point &a = pts[i];
                Point &b = pts[j];
            
                vector<double> L(2);
                if (a.x == b.x) {
                    L[0] = INT_MAX; 
                    L[1] = a.x;
                }
                else {
                    double delta = ((double)(a.y - b.y))/(a.x - b.x); // Must cast to double.
                    L[0] = delta;
                    L[1] = b.y - b.x * delta;
                }

                if (m[L].size() == 0) {
                    m[L].push_back(a);
                    m[L].push_back(b);
                    mct[L] = count[a] + count[b];
                }
                else {
                    if (find(m[L], a) == false) {
                        m[L].push_back(a);
                        mct[L] += count[a];
                    }
                    if (find(m[L], b) == false) {
                        m[L].push_back(b);
                        mct[L] += count[b];
                    }
                }
            }
        }
        
        int num = 0;
        for (map<vector<double>, int>::iterator it = mct.begin(); it != mct.end(); ++ it) {
            num = max(num, (*it).second);
        }
        
        return num;
    }
};

int main() {
    vector<Point> p;
//    p.push_back(Point(0,0));
//    p.push_back(Point(0,0));
//    p.push_back(Point(-1,-1));
//    p.push_back(Point(2,2));
p.push_back(Point(0,9));
p.push_back(Point(138,429));
p.push_back(Point(115,359));
p.push_back(Point(115,359));
p.push_back(Point(-30,-102));
p.push_back(Point(230,709));
p.push_back(Point(-150,-686));
p.push_back(Point(-135,-613));
p.push_back(Point(-60,-248));
p.push_back(Point(-161,-481));

p.push_back(Point(207,639));
p.push_back(Point(23,79));
p.push_back(Point(-230,-691));
p.push_back(Point(-115,-341));
p.push_back(Point(92,289));
p.push_back(Point(60,336));
p.push_back(Point(-105,-467));
p.push_back(Point(135,701));
p.push_back(Point(-90,-394));
p.push_back(Point(-184,-551));

p.push_back(Point(150,774));
        
    Solution so;
    cout << so.maxPoints(p) << endl;
    return 0;
}




