// Works. Tested. Better than Solution.
// This goes through all rows of 2D vector.
// By: X.C. 4/14/2016
class Vector2D4 {
private:
    vector<vector<int> > base;
    int row, col;

    void getNext() {
        ++ col;
        for (; row < base.size(); ++ row) {
            if (col < base[row].size()) break;
            else col = 0;
        }
    }

public:
    Vector2D(vector<vector<int> >& vec2d) {
        base = vec2d;

        row = 0;
        col = -1;
        getNext();
    }

    int next() {
        if (! hasNext()) return 0;

        int val = base[row][col];
        getNext();
        return val;
    }

    bool hasNext() {
        return row < base.size();
    }
};


// Should work, tested locally. Same as Vector2D2. Re-written to be more clean.
// Just flattern the 2D array to 1D at initialization.
class Vector2D3 {
private:
    vector<int> base;
    int index;

public:
    Vector2D(vector<vector<int> >& vec2d) {
        for (int i = 0; i < vec2d.size(); ++ i)
            for (int j = 0; j < vec2d[i].size(); ++ j)
                base.push_back(vec2d[i][j]);

        index = 0;
    }

    int next() {
        if (! hasNext()) return 0;
        return base[index ++];
    }

    bool hasNext() {
        return index < base.size();
    }
};


// The 2 solutions below are from: http://www.cnblogs.com/jcliBlogger/p/4704781.html
// Also see: https://leetcode.com/discuss/questions/oj/flatten-2d-vector

// This works too. Simpler.
class Vector2D2 {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        int row = vec2d.size();
        for (int r = 0; r < row; r++) {
            int col = vec2d[r].size();
            for (int c = 0; c < col; c++)
                data.push_back(vec2d[r][c]);
        }
        idx = 0;
    }
 
    int next() {
        return data[idx++];
    }
 
    bool hasNext() {
        return idx < data.size();
    }
private:
    vector<int> data;
    int idx;
};
 
 

// Works. Tested.
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        r = c = 0;
        row = vec2d.size();
        col = (row == 0 ? -1 : data[r].size());
        skipEmptyVector();
    }
 
    int next() {
         int elem = data[r][c];
         if (c == col - 1) {
             r++;
             c = 0;
             col = data[r].size();
         }
         else c++;
         skipEmptyVector();
         return elem;
    }

    bool hasNext() {
        return col != -1 && (r < row && c < col);
    }
    
private:
    vector<vector<int>> data;
    int row, col, r, c;
    void skipEmptyVector(void) {
        while (!col) {
            r++;
            col = data[r].size();
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

/**
Flatten 2D Vector
Difficulty: Medium

Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]

By calling next repeatedly until hasNext returns false, the order 
of elements returned by next should be: [1, 2, 3, 4, 5, 6].
 */
