

bool equal(double a, double b) {
    return abs(a - b) <= 0.0000001;
}

// This works!
// The idea is:
// for each point, enumerate all the other points, get the slopes;
// when this ends, sort the slopes, and get largest consecutive sequence
// of equal slope -- the largest number of line passing this point.
// Get the max for all the points.
    int maxPointsOnLine(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = points.size();
        if (n <= 2) { return n; }

        int max = -1;
        for (int i = 0; i < n; ++ i) {
            vector<double> slopes;
            for (int j = 0; j < n; ++ j) {
                if (i == j) continue;
                
                Point &a = points[i];
                Point &b = points[j];
            
                double slope;
                if (equal(a.x, b.x)) {
                    slope = numeric_limits<double>::max(); 
                }
                else {
                    slope = ((double)(a.y - b.y))/(a.x - b.x); // Must cast to double.
                }
                
                slopes.push_back(slope);
            }
            
            sort(slopes.begin(), slopes.end());
            double s = slopes[0];
            int ct = 2; // note this is 2.
            for (int k = 1; k < slopes.size(); ++ k) {
                if (equal(s, slopes[k])) {
                    ++ ct;
                    if (ct > max) max = ct;
                }
                else {
                    ct = 2; // note this is 2.
                    s = slopes[k];
                }
            }
        }
                
        return max;
    }


/*
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}
};

#define INT_MAX 10000000

bool equal(double a, double b) {
    return abs(a - b) <= 0.00000001;
}

bool find(vector<Point> s, Point p) {
    for (vector<Point>::iterator it = s.begin(); it != s.end(); ++ it) {
        if (equal((*it).x, p.x) && equal((*it).y, p.y)) {
            return true;
        }   
    }
    
    return false;
}

// to compare customized class Point.
struct comp {
    bool operator() (const Point &a, const Point &b) {
        if (equal(a.x, b.x)) {
            if (equal(a.y, b.y)) return false;
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};


struct compLine{
    bool operator() (const vector<double> &a, const vector<double> &b) {
        if (equal(a[0], b[0])) {
            if (equal(a[1], b[1])) return false;
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }    
};

// This times out for large input.
// This is slow because of the use of map.
class Solution {
public:
    int maxPointsOnLine(vector<Point> &points) {
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
        cout << "number of points: " << pts.size() << endl;
        
        map<vector<double>, vector<Point>, compLine> m; // first param: Line. second param: points on line.
        map<vector<double>, int, compLine> mct; // first param: line, second param: count of points on line.
        for (int i = 0, n = pts.size(); i < n-1; ++ i) {
            cout << "i = " << i << endl;
            for (int j = i+1; j < n; ++ j) {
                Point &a = pts[i];
                Point &b = pts[j];
            
                vector<double> L(2);
                if (equal(a.x, b.x)) {
                    L[0] = INT_MAX; 
                    L[1] = a.x;
                }
                else {
                    double slope = ((double)(a.y - b.y))/(a.x - b.x); // Must cast to double.
                    L[0] = slope;
                    L[1] = b.y - b.x * slope;
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
        cout << "number of points: " << pts.size() << ", number of lines: " << mct.size() << endl;
        
        int num = 0;
        for (map<vector<double>, int>::iterator it = mct.begin(); it != mct.end(); ++ it) {
            num = max(num, (*it).second);
        }
        
        return num;
    }
};


int main() {
    vector<Point> p;
    p.push_back(Point(-2521.757,-7291.408));
    p.push_back(Point(-2065.757,-5515.408));
    p.push_back(Point(-2008.757,-5293.408));
    p.push_back(Point(-1514.757,-3369.408));
    p.push_back(Point(-1039.757,-1519.408));
    
    p.push_back(Point(-1020.757,-1445.408));
    p.push_back(Point(-659.757,-39.408));
    p.push_back(Point(-469.757,700.592));
    p.push_back(Point(-260.757,1514.592));
    p.push_back(Point(290.243,3660.592));
    
    p.push_back(Point(632.243,4992.592));
    p.push_back(Point(670.243,5140.592));
    p.push_back(Point(703.656,373.181));
    p.push_back(Point(727.243,5362.592));
    p.push_back(Point(758.656,373.181));
    
    for (double i = 1.1, j = 2.2; i < 500; i += 0.52, j += 0.43) {
        p.push_back(Point(i, j));    
    }
        
    Solution so;
    cout << so.maxPointsOnLine(p) << endl;
    return 0;
}
*/

/*
#define INT_MAX 10000000

bool equal(double a, double b) {
    return abs(a - b) <= 0.0000001;
}

bool find(vector<Point> &s, Point &p) {
    for (vector<Point>::iterator it = s.begin(); it != s.end(); ++ it) {
        if (equal((*it).x, p.x) && equal((*it).y, p.y)) {
            return true;
        }   
    }
    
    return false;    
}

struct compLine{
    bool operator() (const vector<double> &a, const vector<double> &b) {
        if (equal(a[0], b[0])) {
            if (equal(a[1], b[1])) return false;
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }    
};

// This also times out for large input (data set 30).
// Note: In this problem, points are assumed to have no overlap.
    int maxPointsOnLine(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = points.size();
        if (points.size() == 1) { return 1; }
        
        map<vector<double>, vector<Point>, compLine> m; // first param: Line. second param: points on line.
        for (int i = 0, n = points.size(); i < n-1; ++ i) {
            for (int j = i+1; j < n; ++ j) {
                Point &a = points[i];
                Point &b = points[j];
            
                vector<double> L(2);
                if (equal(a.x, b.x)) {
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
                }
                else {
                    if (find(m[L], a) == false) {
                        m[L].push_back(a);
                    }
                    if (find(m[L], b) == false) {
                        m[L].push_back(b);
                    }
                }
            }
        }
        
        int num = 0;
        for (map<vector<double>, vector<Point> >::iterator it = m.begin(); it != m.end(); ++ it) {
            int x = (*it).second.size();
            if (num < x) num = x;
        }
        
        return num;
    }

*/
