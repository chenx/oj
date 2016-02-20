// Works too. Tested. Simplified form Solution.
struct comp { // to compare equality of Point.
    bool operator() (const Point &a, const Point &b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
};

class Solution2 {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();

        // Remove duplicate points.
        map<Point, int, comp> count;
        vector<Point> pts;
        for (int i = 0; i < n; ++ i) {
            ++ count[points[i]];
            if (count[points[i]] == 1) { pts.push_back(points[i]); }
        }
        if (pts.size() == 1) { return count[points[0]]; }
        
        map<vector<double>, vector<Point> > mpt; // first param: Line. second param: points on line.
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
                    double delta = (a.y - b.y) * 1.0/(a.x - b.x); // Must cast to double.
                    L[0] = delta;
                    L[1] = b.y - b.x * delta;
                }

                if (find(mpt[L], a) == false) {
                    mpt[L].push_back(a);
                    mct[L] += count[a];
                }
                if (find(mpt[L], b) == false) {
                    mpt[L].push_back(b);
                    mct[L] += count[b];
                }
            }
        }
        
        int num = 0;
        for (auto ct : mct) num = max(num, ct.second);

        return num;
    }
    
    static bool find(vector<Point> s, Point p) {
        for (Point pt : s) {
            if (pt.x == p.x && pt.y == p.y) return true;
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

