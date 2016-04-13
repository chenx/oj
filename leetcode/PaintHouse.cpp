// Should work. Tested locally.
class Solution3 {
public:
    int minCost(vector<vector<int>>& costs) { // costs: n * 3
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int len = costs.size();

        vector<int> c(3);
        c[0] = costs[0][0], c[1] = costs[0][1], c[2] = costs[0][2];

        for (int i = 1; i < len; ++ i) {
            vector<int> b = c;
            c[0] = costs[i][0] + min(b[1], b[2]);
            c[1] = costs[i][1] + min(b[0], b[2]);
            c[2] = costs[i][2] + min(b[1], b[0]);
        }

        return min(c[0], min(c[1], c[2]));
    }
};

// Works too. Tested. By: XC
class Solution2 {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int len = costs.size();

        int c0 = costs[0][0], c1 = costs[0][1], c2 = costs[0][2];
        
        for (int i = 1; i < len; ++ i) {
            // Note, it's NOT: c0 = c0 + min(costs[i][1], costs[i][2]);
            int b0 = c0, b1 = c1, b2 = c2;
            c0 = costs[i][0] + min(b1, b2);
            c1 = costs[i][1] + min(b0, b2);
            c2 = costs[i][2] + min(b0, b1);
        }
        
        return min(c0, min(c1, c2));
    }
};

// Works. Tested. By: XC
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int len = costs.size();

        vector<vector<int>> c(len, vector<int>(3, 0));
        
        c[0][0] = costs[0][0];
        c[0][1] = costs[0][1];
        c[0][2] = costs[0][2];
        
        for (int i = 1; i < len; ++ i) {
            // Note, it's NOT: c[i][0] = c[i-1][0] + min(costs[i][1], costs[i][2]);
            c[i][0] = costs[i][0] + min(c[i-1][1], c[i-1][2]);
            c[i][1] = costs[i][1] + min(c[i-1][0], c[i-1][2]);
            c[i][2] = costs[i][2] + min(c[i-1][0], c[i-1][1]);
        }
        
        return min(c[len-1][0], min(c[len-1][1], c[len-1][2]));
    }
};


/**
Paint House
Difficulty: Medium

There are a row of n houses, each house can be painted with one of 
the three colors: red, blue or green. The cost of painting each 
house with a certain color is different. You have to paint all 
the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented 
by a n x 3 cost matrix. For example, costs[0][0] is the cost of 
painting house 0 with color red; costs[1][2] is the cost of painting 
house 1 with color green, and so on... Find the minimum cost to 
paint all houses.

Note:
All costs are positive integers.
 */
