// Do the 2 inverts in one step.
class Solution2 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size(), n = image[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int left = 0, right = n - 1; left <= right; ++ left, -- right) {
                int tmp = 1 - image[i][left];
                image[i][left] = 1 - image[i][right];
                image[i][right] = tmp;
            }
        }
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size(), n = image[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int left = 0, right = n - 1; left < right; ++ left, -- right) {
                swap(image[i][left], image[i][right]);
            }
            for (int j = 0; j < n; ++ j) image[i][j] = 1 - image[i][j];
        }
        return image;
    }
};


/**
832. Flipping an Image
Easy

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

    For example, flipping [1,1,0] horizontally results in [0,1,1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

    For example, inverting [0,1,1] results in [1,0,0].

 

Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 */
