#include <vector>
#include <iostream>
using namespace std;


// This works. Is more clear than Solution2 on why.
// O(mn) space, O(mn) time.
class Solution3 {
     int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        int A[row][col];
    
        // 1. when the knight reached the bottom right corner
        A[row-1][col-1] = (dungeon[row-1][col-1] > 0) ? 1 : (1 - dungeon[row-1][col-1]);
    
        // 2. in the last column, bottom-up;
        for(int i = row - 2; i >= 0; --i) {
            A[i][col-1]  = getVal(A[i+1][col-1] - dungeon[i][col-1]); // aboveValue
        }
    
        // 3. in the last row, from right to left
        for(int j = col - 2; j >= 0; --j) {
            A[row-1][j]  = getVal(A[row-1][j+1] - dungeon[row-1][j]); // leftValue
        }
    
        // 4. in other areas, from bottom-right to upper-left
        for(int i = row - 2; i >=0; --i) {
            for(int j = col - 2; j >= 0; --j) {
                int rightValue = getVal(A[i][j+1]-dungeon[i][j]);
                int belowValue = getVal(A[i+1][j]-dungeon[i][j]);
                A[i][j] = min(rightValue, belowValue);
            }
        }
        return A[0][0];
    }
    
    int getVal(int v) { return v > 0 ? v : 1; }
};

// This works. 
// From: https://oj.leetcode.com/discuss/21088/sharing-my-solution-with-o-n-space-o-mn-runtime
// Why start from upper left does not work:
// https://oj.leetcode.com/discuss/20819/who-can-explain-why-from-the-bottom-right-corner-to-left-top
// O(n) space, O(mn) time.
class Solution2 {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
            const int m = dungeon.size();
            const int n = dungeon[0].size();
            vector<int> dp(n + 1, INT_MAX);
            dp[n - 1] = 1; 
            for(int i = m - 1; i >= 0; --i)
                for(int j = n - 1; j >= 0; --j)
                    dp[j] = getMin( min(dp[j], dp[j + 1]) - dungeon[i][j] );
            return dp[0];
        }
        int getMin(int n){
            return n <= 0 ? 1 : n;
        }
};


// This works, but complexity is catalan number, times out for large input.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
        int rows = dungeon.size(), cols = dungeon[0].size();
        int max_minv = INT_MIN;
        cal(dungeon, rows, cols, 0, 0, 0, 0, max_minv);
        return max_minv;
    }
    
    void cal(vector<vector<int> > &dungeon, int rows, int cols, int x, int y, int v, int minv, int & max_minv) {
        v += dungeon[x][y];
        minv = min(minv, v);
        
        if (x == rows - 1 && y == cols - 1) {
            max_minv = max(minv, max_minv);
            return;
        }
        
        if (1 + x < rows) cal(dungeon, rows, cols, x+1, y, v, minv, max_minv);
        if (1 + y < cols) cal(dungeon, rows, cols, x, y+1, v, minv, max_minv);
    }
};


int main() {
    vector<vector<int> > d(3, vector<int>(3));
    
    d[0][0] = -2; d[0][1] = -3, d[0][2] = 3;
    d[1][0] = -5; d[1][1] = -10, d[1][2] = 1;
    d[2][0] = 10; d[2][1] = 30, d[2][2] = -5;
    
    Solution so;
        
    cout << "min HP = " << so.calculateMinimumHP(d) << endl;
    
    return 0;
}

/*
// Java solution. This works too.
// From: https://oj.leetcode.com/discuss/20721/my-ac-java-version-suggestions-are-welcome
public int calculateMinimumHP(int[][] dungeon) {
    if (dungeon == null || dungeon.length == 0 || dungeon[0].length == 0) return 0;

    int m = dungeon.length;
    int n = dungeon[0].length;

    int[][] health = new int[m][n];

    health[m - 1][n - 1] = Math.max(1 - dungeon[m - 1][n - 1], 1);

    for (int i = m - 2; i >= 0; i--) {            
        health[i][n - 1] = Math.max(health[i + 1][n - 1] - dungeon[i][n - 1], 1);
    }

    for (int j = n - 2; j >= 0; j--) {
        health[m - 1][j] = Math.max(health[m - 1][j + 1] - dungeon[m - 1][j], 1);
    }

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int down = Math.max(health[i + 1][j] - dungeon[i][j], 1);
            int right = Math.max(health[i][j + 1] - dungeon[i][j], 1);
            health[i][j] = Math.min(right, down);
        }
    }

    return health[0][0];
}
*/

/**

Dungeon Game

The demons had captured the princess (P) and imprisoned her in the bottom-right 
corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must 
fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at 
any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative 
integers) upon entering these rooms; other rooms are either empty (0's) or 
contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to 
move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is 
able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be 
at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
-2 (K) 	-3 	3
-5 	-10 	1
10 	30 	-5 (P)

Notes:

    The knight's health has no upper bound.
    Any room can contain threats or power-ups, even the first room the knight 
    enters and the bottom-right room where the princess is imprisoned.

 */
