
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;
        
        rotate(mat);
        if (mat == target) return true;
        rotate(mat);
        if (mat == target) return true;
        rotate(mat);
        if (mat == target) return true;
        
        return false;
    }

    void rotate(vector<vector<int>> &matrix) {
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


/**
1886. Determine Whether Matrix Can Be Obtained By Rotation
Easy

Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to 
target by rotating mat in 90-degree increments, or false otherwise.
 */
