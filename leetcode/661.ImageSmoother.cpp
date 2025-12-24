// Time: O(mn)
// Space: O(1)
class Solution2 {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size(), cols = img[0].size();

        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                img[i][j] |= getAvg(img, i, j) << 8;
            }
        }

        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                img[i][j] >>= 8;
            }
        }

        return img;
    }

    int getAvg(vector<vector<int>>& img, int i, int j) {
        int count = 1, sum = img[i][j];
        add(img, i-1, j-1, count, sum);
        add(img, i-1, j, count, sum);
        add(img, i-1, j+1, count, sum);

        add(img, i, j-1, count, sum);
        add(img, i, j+1, count, sum);

        add(img, i+1, j-1, count, sum);
        add(img, i+1, j, count, sum);
        add(img, i+1, j+1, count, sum);

        return sum / count;
    }

    void add(vector<vector<int>>& img, int i, int j, int& count, int& sum) {
        if (i < 0 || i >= img.size() || j < 0 || j >= img[0].size()) return;
        ++ count;
        sum += (img[i][j] & 0xFF);
    }
};

// Time: O(mn)
// Space: O(1) if not consider result.
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size(), cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                result[i][j] = getAvg(img, i, j);
            }
        }
        return result;
    }

    int getAvg(vector<vector<int>>& img, int i, int j) {
        int count = 1, sum = img[i][j];
        add(img, i-1, j-1, count, sum);
        add(img, i-1, j, count, sum);
        add(img, i-1, j+1, count, sum);

        add(img, i, j-1, count, sum);
        add(img, i, j+1, count, sum);

        add(img, i+1, j-1, count, sum);
        add(img, i+1, j, count, sum);
        add(img, i+1, j+1, count, sum);

        return sum / count;
    }

    void add(vector<vector<int>>& img, int i, int j, int& count, int& sum) {
        if (i < 0 || i >= img.size() || j < 0 || j >= img[0].size()) return;
        ++ count;
        sum += img[i][j];
    }
};

/**
661. Image Smoother
Easy

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by 
rounding down the average of the cell and the eight surrounding cells (i.e., the average of the 
nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, 
we do not consider it in the average (i.e., the average of the four cells in the red smoother).

Given an m x n integer matrix img representing the grayscale of an image, return the image after 
applying the smoother on each cell of it.

 

Example 1:

Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 */
