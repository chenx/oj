// BFS. O(n^2) time, O(1) space.
class Solution {
    int n = 0;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        if (n <= 1) return n;
        
        int ct = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (isConnected[i][j] == 1) {
                    ++ ct;
                    markCells(isConnected, i, j);
                }
            }
        }
        return ct;
    }

    void markCells(vector<vector<int>>& isConnected, int i, int j) {
        isConnected[i][j] = isConnected[j][i] = -1;
        for (int k = j + 1; k < n; ++ k) {
            if (isConnected[i][k] == 1) {
                markCells(isConnected, i, k);
            }
        }
        for (int k = 0; k < n; ++ k) {
            if (isConnected[j][k] == 1) {
                markCells(isConnected, j, k);
            }
        }
    }
};

/**
547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are 
directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
 */
