/**
 * Give a matrix, one can go down or right. Print out all paths. FB.
 * By: X.C. 1/27/2015
 */
#include <iostream>
#include <vector>
using namespace std;

// This works.
class Solution {
public:
    void printPaths(const vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            cout << "no path" << endl;
            return;
        }
    
        vector<vector<char> > paths;
        vector<char> path;
        getPaths(matrix, path, 0, 0);
    }
    
    // Compared to getPath2(), this passes path as reference, saves memory, better.
    void getPaths(const vector<vector<char> > &matrix, vector<char> &path, int x, int y) {
        path.push_back(matrix[x][y]);
    
        if (x < matrix.size() - 1) { // go to next row.
            getPaths(matrix, path, x + 1, y);
        }
    
        if ( y < matrix[0].size() - 1) { // go to next column.
            getPaths(matrix, path, x, y + 1);
        }
    
        if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
            printPath(path);
        }
        
        // erase last element.
        //path.erase(path.end() - 1); // this works too.
        path.pop_back();
    }

    // This passes path by copy, so is more memory expensive.
    void getPaths2(const vector<vector<char> > &matrix, vector<char> path, int x, int y) {
        path.push_back(matrix[x][y]);
    
        if (x < matrix.size() - 1) { // go to next row.
            getPaths2(matrix, path, x + 1, y);
        }
    
        if ( y < matrix[0].size() - 1) { // go to next column.
            getPaths2(matrix, path, x, y + 1);
        }
    
        if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
            printPath(path);
        }
    }
    
    void printPath(vector<char> &path) {
        for (int i = 0, n = path.size(); i < n; ++ i) {
            if (i > 0) cout << "->";
            cout << path[i];
        }
        cout << endl;
    }
};

int main() {
    Solution so;
    vector<vector<char> > matrix(2, vector<char>(3));
    matrix[0][0] = 'a';
    matrix[0][1] = 'b';
    matrix[0][2] = 'c';
    matrix[1][0] = 'd';
    matrix[1][1] = 'e';
    matrix[1][2] = 'f';
    so.printPaths(matrix);
    return 0;
}

