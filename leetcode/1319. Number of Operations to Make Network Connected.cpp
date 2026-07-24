class Solution {
    class UnionFind {
        public:
        void add(int x) {
            if (parent.contains(x)) return;

            parent[x] = x;
            rank[x] = 0;
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void get_union(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            
            int rx = rank[x], ry = rank[y];
            if (rx < ry) {
                parent[x] = y;
            } else if (ry < rx) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x] ++;
            }
        }

        const unordered_map<int, int>& get_parent_map() const {
            return parent;
        }
        
        private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        int count = n - 1; // number of connections needed.
        UnionFind uf;
        for (auto& conn : connections) {
            uf.add(conn[0]);
            uf.add(conn[1]);
            if (uf.find(conn[0]) != uf.find(conn[1])) {
                count --;
                uf.get_union(conn[0], conn[1]);
            }
        }
        return count;

    }
};

/**
1319. Number of Operations to Make Network Connected
Solved
Medium
Topics
conpanies iconCompanies
Hint

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network 
where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach 
any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly 
connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. 
If it is not possible, return -1.

 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 */
