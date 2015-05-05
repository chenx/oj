//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/8/2012
// @Last modified: 4/4/2013
//

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1) return;
        
        int tmp;

        int x10 = 0, y10 = 0,
            x20 = n-1, y20 = 0,
            x30 = n - 1, y30 = n - 1,
            x40 = 0, y40 = n - 1;   // initialize 4 corners.
        while (n > 1) {
            int x1 = x10, y1 = y10, // upper left
                x2 = x20, y2 = y20, // bottom left
                x3 = x30, y3 = y30, // bottom right
                x4 = x40, y4 = y40; // upper right
            while (y1 < y40) {
                tmp = matrix[x1][y1];
                matrix[x1][y1] = matrix[x2][y2];
                matrix[x2][y2] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x4][y4];
                matrix[x4][y4] = tmp;
                
                ++ y1, -- x2, -- y3, ++ x4;
            }

            // update 4 corners.
            ++ x10, ++ y10,
            -- x20, ++ y20,
            -- x30, -- y30,
            ++ x40, -- y40;
            n -= 2;
        }
    }
};


/**
 * This also works and is much clearer. From CCI (Cracking the Coding Interview) 5ed, p189.
 * Note the use of layer, first, last and offset. Can draw a image on board before going on.

  ------------------------
  |   | i |              |
  ------------------------
  |   |              | i |
  |   |              |   |
  |   |              |   |
  |   |                  |
  | i |                  |
  ------------------------
  |              | i |   |
  ------------------------
  
  the coordinates of the 4 cells are (note first == layer):
  (layer, i), (last-offset, layer), (last, last-offset), (i, last)
*/
class Solution2 {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        
        for (int layer = 0; layer < n/2; ++ layer) {
            int first = layer;
            int last =  n - 1 - layer;
            
            for (int i = first; i < last; ++ i) {
                int offset = i - first;
                int tmp = matrix[first][i];
                matrix[first][i] = matrix[last - offset][first]; // L -> U
                matrix[last - offset][first] = matrix[last][last - offset]; // B -> L
                matrix[last][last - offset] = matrix[i][last]; // R -> B
                matrix[i][last] = tmp; // T -> R
            }
            
        }
    }
};


/*
Problem:

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

 */
