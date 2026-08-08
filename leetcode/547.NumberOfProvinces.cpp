class Solution5 {
    class UnionFind {
        public:
        UnionFind(): count(0) {}

        void add(int x) {
            if (parent.contains(x)) return;

            parent[x] = x;
            rank[x] = 0;
            ++ count;
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
            -- count;
        }

        const int size() const {
            return count;
        }
        
        private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        int count;
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf;
        int n = isConnected.size();
        for (int i = 0; i < n; ++ i) {
            uf.add(i);
        }

        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                if (isConnected[i][j] == 1) {
                    uf.get_union(i, j);
                }
            }
        }

        return uf.size();
    }
};

class Solution4 {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf;
        int n = isConnected.size();
        for (int i = 0; i < n; ++ i) {
            uf.add(i);
        }

        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                if (isConnected[i][j] == 1) {
                    uf.get_union(i, j);
                }
            }
        }

        unordered_set<int> groups;
        auto parent_map = uf.get_parent_map();
        for (auto [key, _] : parent_map) {
            groups.insert(uf.find(key));
        }

        return groups.size();
    }
};

class Solution3 {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf;
        int n = isConnected.size();
        for (int i = 0; i < n; ++ i) {
            for (int j = i; j < n; ++ j) {
                if (isConnected[i][j] == 1) {
                    uf.add(i);
                    uf.add(j);
                    uf.get_union(i, j);
                }
            }
        }

        unordered_set<int> groups;
        auto parent_map = uf.get_parent_map();
        for (auto [key, _] : parent_map) {
            groups.insert(uf.find(key));
        }

        return groups.size();
    }
};

// Solution 2 works. Use Union Find. O(n^2 * alpha) time, O(n) space.
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
