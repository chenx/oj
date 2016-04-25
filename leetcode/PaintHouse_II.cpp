// Should work. Tested locally only.
class Solution2 {
public:
    int minCost(vector<vector<int> >& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int len = costs.size(), k = costs[0].size();

        vector<int> c(k);
        for (int i = 0; i < k; ++ i) c[i] = costs[0][i];
        //vector<int> c = costs[0]; // this should work too.

        for (int i = 1; i < len; ++ i) {
            vector<int> b = c;
            for (int j = 0; j < k; ++ j) {
                c[j] = costs[i][j] + getMin(b, j);
            }
        }

        return getMin(c, -1); // note this, simplified code.
    }

    int getMin(vector<int> & b, int j) {
        int v = INT_MAX; // Note this! Cannot initialize to v = b[0].
        for (int i = 0; i < b.size(); ++ i) {
            if (i == j) continue;
            v = min(v, b[i]);
        }
        return v;
    }
};


// Works. Tested. O(nk^2). By: XC
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int n = costs.size();
        int k = costs[0].size();

        vector<int> c(k);
        for (int j = 0; j < k; ++ j) c[j] = costs[0][j];

        for (int i = 1; i < n; ++ i) {
            vector<int> b = c;
            
            for (int j = 0; j < k; ++ j) {
                c[j] = costs[i][j] + getMin(b, j);
            }
        }
        
        int min_val = INT_MAX;
        for (int i = 0; i < c.size(); ++ i) {
            min_val = min(min_val, c[i]);
        }
        
        return min_val;
    }
    
    int getMin(vector<int> & b, int j) {
        int min_val = INT_MAX;
        for (int i = 0; i < b.size(); ++ i) {
            if (i == j) continue;
            min_val = min(min_val, b[i]);
        }
        return min_val;
    }
};


/**
Paint House II
Difficulty: Hard

There are a row of n houses, each house can be painted with 
one of the k colors. The cost of painting each house with a 
certain color is different. You have to paint all the houses 
such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is 
represented by a n x k cost matrix. For example, costs[0][0] 
is the cost of painting house 0 with color 0; costs[1][2] is 
the cost of painting house 1 with color 2, and so on... Find 
the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
 */
