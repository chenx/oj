// From: https://www.designgurus.io/answers/detail/3453-separate-squares-i-3sep4sq
// Time O(n·log((maxY−minY)/ε)) ≈ O(n·60)
// Space O(1) extra
//
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = DBL_MAX, high = DBL_MIN;
        for (auto s : squares) {  // O(n)
            low = min(low, s[1]);
            high = max(high, s[1] + s[2]);
        }
        for (int iter = 0; iter < 60; iter++) {  // O(60)
            double mid = (low + high) / 2, diff = 0;
            for (auto s : squares) {  // O(n)
                double y = s[1], l = s[2], top = y + l;
                if (mid <= y)       diff += l*l;
                else if (mid >= top) diff -= l*l;
                else                 diff += (top - mid)*l - (mid - y)*l;
            }
            if (diff > 0) low = mid;
            else          high = mid;

            if ((high - low) < 0.00001) break;
        }
        return low;
    }

    double min(double a, double b) {
        return a < b ? a : b;
    }

    double max(double a, double b) {
        return a > b ? a : b;
    }
};


/**
3453. Separate Squares I
Medium

You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of 
the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above 
the line equals the total area of the squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted multiple times.

 

Example 1:

Input: squares = [[0,0,1],[2,2,1]]

Output: 1.00000

Explanation:

Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. 
The lowest option is 1.

Example 2:

Input: squares = [[0,0,2],[1,1,1]]

Output: 1.16667
 */
