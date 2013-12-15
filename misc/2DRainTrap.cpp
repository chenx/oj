//
// Go from the outer rim to internal cells, put cells to a priority queue.
// Each time, pop the top of the PQ t, check unchecked cells around it:
//  - if lower, calculate height difference, add water contained in this cell.
//    then push new cells to PQ, set height to that of t.
//  - else, no water added, just push new cells to PQ.
//
// The idea is from a post on mitbbs [4]. It is O(n^2 logn). 
// n^2 for each cell, logn for PQ operations.
// Reference: 
// [1] http://www.mitbbs.com/article_t1/JobHunting/32339819_0_2.html
// [2] http://blog.sina.com.cn/s/blog_b9285de20101j9a7.html
// [3] http://leetcode.com/groups/twitter-interview/forum/topic/rain-water-trap-2d-version/
// [4] http://www.mitbbs.com/article_t1/JobHunting/32338549_0_3.html
//
// Be careful of:
// - definition of priority queue: priority_queue<type, container, comp>
// - definition of comp class and its operator().
// - used of sides[] array to simplify iterator of 4 sides.
//
// @Author: Xin Chen
// @Created on: 3/14/2013
// @Last modified: 3/14/2013
//

#include <iostream>
#include <queue>
using namespace std;

class Cell {
public:
    int x;
    int y;
    int h;
    Cell(int x, int y, int height) : x(x), y(y), h(height) {}
};

class comp {
public:
    bool operator()(const Cell &a, const Cell &b) {
        return a.h > b.h; // for min heap.
    }
};

class Solution {
public:
    int getWater() {
        debug = false;
        const int X = 4, Y = 4;
        int cells[X][Y] = 
        {
            {5,4,4,5},
            {5,3,4,5},
            {4,3,5,6},
            {5,4,3,5}
        }; // answer: 2
        /*{
            {1,2,3,3},
            {4,0,0,3},
            {6,7,8,8}
        }; // answer: 4 */ 
        int used[X][Y];
        memset(used, 0, sizeof(int) * X * Y);
        
        priority_queue<Cell, vector<Cell>, comp> q;
        int water = 0;
        
        // push top and bottom edges.
        for (int i = 0; i < Y; ++ i) {
            q.push( Cell(0, i, cells[0][i]));
            q.push( Cell(X-1, i, cells[X-1][i]));
            used[0][i] = 1;
            used[X-1][i] = 1;
        }
        // push left and right edges.
        for (int i = 1; i < X-1; ++ i) {
            q.push( Cell(i, 0, cells[i][0]));
            q.push( Cell(i, Y-1, cells[i][Y-1]));
            used[i][0] = 1;
            used[i][Y-1] = 1;
        }
        
        //dump(q);
        // The four neighbors to navigate to.
        int sides[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        
        while (! q.empty()) {
            Cell c = q.top(); // if use reference &c, then after q.pop c will be undefined.
            q.pop();
            if (debug) cout << "c:[" << c.x << "," << c.y << ", h=" << c.h << "]" << endl;
            for (int i = 0; i < 4; ++ i) {
                int x1 = c.x + sides[i][0];
                int y1 = c.y + sides[i][1];
                if (isValidCell(x1, y1, X, Y) && ! used[x1][y1]) {
                    water += checkCell(x1, y1, cells[x1][y1], c.h, q);
                    used[x1][y1] = 1;
                    if (debug) cout << " [" << x1 << ", " << y1 << "](" << cells[x1][y1] << "):" << water << endl;
                }
            }
        }
        
        return water;       
    }

private:
    bool debug;
    
    bool isValidCell(int x, int y, int X, int Y) {
        return x >= 0 && x <= X-1 && y >= 0 && y <= Y-1;
    }
    
    int checkCell(int x1, int y1, int h1, int h, priority_queue<Cell, vector<Cell>, comp> &q) {
        int water = 0;
        if (h1 >= h) {
            q.push(Cell(x1, y1, h1)); 
        } else {
            q.push(Cell(x1, y1, h)); // <- Note h is used instead of h1.
            water = h - h1;
        }
        return water;
    }
    
    void dump(priority_queue<Cell, vector<Cell>, comp> q) {
        while (! q.empty()) {
            const Cell & c = q.top();
            cout << c.h << " ";
            q.pop();
        }
        cout << endl;
    }
};

void test() {
    Solution s;
    cout << "Total water contained: " << s.getWater() << endl;
}

int main() {
    test();    
    return 0;
}


/*
   In while loop, could use this:
            if (c.x > 0 && ! used[c.x-1][c.y]) {
                water += checkCell(cells[c.x-1][c.y], c, q);
                used[c.x-1][c.y] = 1;
            }
            else if (c.x < X-1 && ! used[c.x+1][c.y]) {
                water += checkCell(cells[c.x+1][c.y], c, q);
                used[c.x+1][c.y] = 1;
            }
            else if (c.y > 0 && ! used[c.x][c.y-1]) {
                water += checkCell(cells[c.x][c.y-1], c, q);
                used[c.x][c.y-1] = 1;
            }
            else if (c.y < Y-1 && ! used[c.x][c.y+1]) {
                water += checkCell(cells[c.x][c.y+1], c, q);
                used[c.x][c.y+1] = 1;
            }

 */
