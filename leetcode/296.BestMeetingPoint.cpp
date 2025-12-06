// Should work. Tested locally.
// Basically same as Solution, but less brackets.
// Time complexity : O(mn+nlogn).
// Space: O(mn)
class Solution2 {
public:
    int minTotalDistance(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<int> row, col;
        for (int i = 0; i < m; ++ i) 
            for (int j = 0; j < n; ++ j)
                if (grid[i][j] == 1)
                    row.push_back(i), col.push_back(j);

        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        int x0 = getMedian(row), y0 = getMedian(col), dist = 0;

        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (grid[i][j] == 1)
                    dist += abs(i - x0) + abs(j - y0);
        
        return dist;
    }

    // This also works, since we only travel on points on the grid:
    // int getMedian(vector<int> &v) {
    //     return v[v.size() / 2];
    // }

    int getMedian(vector<int> &v) {
        int n = v.size();
        if (n == 0) return 0;
        if (n & 1) return v[n/2];
        else return 0.5 * (v[n/2] + v[n/2 - 1]);
    }
};


// Works. Tested.
// The best meeting point is the median.
// for odd numbers, it's the center one; 
// for even numbers, any point between the middle two will do, 
// including any of the 2 middle points.
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<int> xs, ys;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    xs.push_back(i);
                    ys.push_back(j);
                }
            }
        }
        
        // don't forget to sort!
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int x = getMedian(xs), y = getMedian(ys);
        
        int dist = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    dist += abs(i-x) + abs(j-y);
                }
            }
        }
        
        return dist;
    }
    
    int getMedian(vector<int> & v) {
        int n = v.size();
        
        if (n & 1) return v[n/2];
        else return ((v[n/2] + v[n/2 - 1])/2.0);
    }
};

/**
296.Best Meeting Point My Submissions Question
Difficulty: Hard

A group of two or more people wants to meet and minimize the total travel distance. 
You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in 
the group. The distance is calculated using Manhattan Distance, where 
distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 
is minimal. So return 6.

Hint:

Try to solve it in one dimension first. How can this solution apply to the 
two dimension case?
 */
