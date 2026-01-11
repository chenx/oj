// Solution 2 works. Use Union Find. O(n^2) time, O(n) space.
class UnionFind {
private:
    vector<int> parent, rank;
    int count;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        count = size;
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind dsu(n);
        int numberOfComponents = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] && dsu.find(i) != dsu.find(j)) {
                    numberOfComponents--;
                    dsu.union_set(i, j);
                }
            }
        }

        return numberOfComponents;
    }
};

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
