/**
 * Given a matrix, one can go down or right. Print out all paths. FB.
 * For solutions below, getPath() and getPath6() are the best.
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
        getPaths6(matrix, path, 0, 0);
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
    
    // Different from getPath() and getPath2() that the end condition test
    // is put to front.
    void getPaths3(const vector<vector<char> > &matrix, vector<char> path, int x, int y) {
        if (x == matrix.size()-1 && y == matrix[0].size()-1) {
            path.push_back(matrix[x][y]);
            printPath(path);
            //path.pop_back();
            return;
        }
        else if (x == matrix.size() || y == matrix[0].size()) {
            return;
        }

        path.push_back(matrix[x][y]);
    
        if (x < matrix.size()) { // go to next row.
            getPaths3(matrix, path, x + 1, y);
        }
    
        if ( y < matrix[0].size()) { // go to next column.
            getPaths3(matrix, path, x, y + 1);
        }
           
        // erase last element.
        //path.erase(path.end() - 1); // this works too.
        //path.pop_back();
    }
    
    // Same as getPath3(), but optimized by passing path as reference 
    // to save space, correspondingly you need to pop_back() from path.
    void getPaths4(const vector<vector<char> > &matrix, vector<char> &path, int x, int y) {
        if (x == matrix.size()-1 && y == matrix[0].size()-1) {
            path.push_back(matrix[x][y]);
            printPath(path);
            path.pop_back();
            return;
        }
        else if (x == matrix.size() || y == matrix[0].size()) {
            return;
        }

        path.push_back(matrix[x][y]);
    
        if (x < matrix.size()) { // go to next row.
            getPaths4(matrix, path, x + 1, y);
        }
    
        if ( y < matrix[0].size()) { // go to next column.
            getPaths4(matrix, path, x, y + 1);
        }
           
        // erase last element.
        //path.erase(path.end() - 1); // this works too.
        path.pop_back();
    }       
    
    // This is optimized from getPath4(). This works too! Better.
    void getPaths5(const vector<vector<char> > &matrix, vector<char> path, int x, int y) {
        if (x == matrix.size()-1 && y == matrix[0].size()-1) {
            path.push_back(matrix[x][y]);
            printPath(path);
            return;
        }

        path.push_back(matrix[x][y]);
    
        if (x < matrix.size() - 1) { // go to next row.
            getPaths5(matrix, path, x + 1, y);
        }
    
        if ( y < matrix[0].size() - 1) { // go to next column.
            getPaths5(matrix, path, x, y + 1);
        }
    }     
    
    // This works too. Optimized from getPath5() by passing path as reference
    // and saving memory.
    void getPaths6(const vector<vector<char> > &matrix, vector<char> &path, int x, int y) {
        if (x == matrix.size()-1 && y == matrix[0].size()-1) {
            path.push_back(matrix[x][y]);
            printPath(path);
            path.pop_back();
            return;
        }

        path.push_back(matrix[x][y]);
    
        if (x < matrix.size() - 1) { // go to next row.
            getPaths6(matrix, path, x + 1, y);
        }
    
        if ( y < matrix[0].size() - 1) { // go to next column.
            getPaths6(matrix, path, x, y + 1);
        }
           
        // erase last element.
        //path.erase(path.end() - 1); // this works too.
        path.pop_back();
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

