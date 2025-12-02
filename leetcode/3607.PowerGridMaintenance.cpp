// using PowerGrid = priority_queue<int, vector<int>, greater<int>>; // minHeap.
// using Graph = vector<vector<int>>;

typedef priority_queue<int, vector<int>, greater<int>> PowerGrid;
typedef vector<vector<int>> Graph;

class Solution {
private:
    struct Vertex {
        int vertexId;
        bool offline = false;
        int powerGridId = -1;

        Vertex() {}
        Vertex(int id) : vertexId(id) {}
    };

    vector<Vertex> vertices = vector<Vertex>();

    void traverse(Vertex& u, int powerGridId, PowerGrid& powerGrid, Graph& graph) {
        u.powerGridId = powerGridId;
        powerGrid.push(u.vertexId);
        for (int vid : graph[u.vertexId]) {
            Vertex& v = vertices[vid];
            if (v.powerGridId == -1) {
                traverse(v, powerGridId, powerGrid, graph);
            }
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        Graph graph(c + 1);
        vertices.resize(c + 1);

        for (int i = 1; i <= c; i++) {
            vertices[i] = Vertex(i);
        }

        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        vector<PowerGrid> powerGrids;
        for (int i = 1, powerGridId = 0; i <= c; ++ i) {
            auto& v = vertices[i];
            if (v.powerGridId == -1) {
                PowerGrid powerGrid;
                traverse(v, powerGridId, powerGrid, graph);
                powerGrids.push_back(powerGrid);
                ++ powerGridId;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int op = q[0], x = q[1];
            if (op == 1) {
                if (!vertices[x].offline) {
                    ans.push_back(x);
                } else {
                    auto& powerGrid = powerGrids[vertices[x].powerGridId];
                    while (!powerGrid.empty() && vertices[powerGrid.top()].offline) {
                        powerGrid.pop();
                    }
                    ans.push_back(!powerGrid.empty() ? powerGrid.top() : -1);
                }
            } else if (op == 2) {
                vertices[x].offline = true;
            }
        }
        return ans;
    }
};


// See: https://leetcode.com/problems/power-grid-maintenance/editorial/
// Approach 2: DFS/BFS + Priority Queue
// Let m be the length of connections, i.e., the number of edges in the graph; q is the length of queries.
// Time complexity: O(m+clogc+q).
// Space complexity: O(c+m).
class Vertex {
public:
    int vertexId;
    bool offline = false;
    int powerGridId = -1;

    Vertex() {}
    Vertex(int id) : vertexId(id) {}
};

using PowerGrid = priority_queue<int, vector<int>, greater<int>>;
using Graph = vector<vector<int>>;

class Solution {
private:
    vector<Vertex> vertices = vector<Vertex>();

    void traverse(Vertex& u, int powerGridId, PowerGrid& powerGrid,
                  Graph& graph) {
        u.powerGridId = powerGridId;
        powerGrid.push(u.vertexId);
        for (int vid : graph[u.vertexId]) {
            Vertex& v = vertices[vid];
            if (v.powerGridId == -1) traverse(v, powerGridId, powerGrid, graph);
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        Graph graph(c + 1);
        vertices.resize(c + 1);

        for (int i = 1; i <= c; i++) {
            vertices[i] = Vertex(i);
        }

        for (auto& conn : connections) {
            graph[conn.at(0)].push_back(conn.at(1));
            graph[conn.at(1)].push_back(conn.at(0));
        }

        vector<PowerGrid> powerGrids;

        for (int i = 1, powerGridId = 0; i <= c; i++) {
            auto& v = vertices[i];
            if (v.powerGridId == -1) {
                PowerGrid powerGrid;
                traverse(v, powerGridId, powerGrid, graph);
                powerGrids.push_back(powerGrid);
                powerGridId++;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int op = q.at(0), x = q.at(1);
            if (op == 1) {
                if (!vertices[x].offline) {
                    ans.push_back(x);
                } else {
                    auto& powerGrid = powerGrids[vertices[x].powerGridId];
                    while (!powerGrid.empty() &&
                           vertices[powerGrid.top()].offline) {
                        powerGrid.pop();
                    }
                    ans.push_back(!powerGrid.empty() ? powerGrid.top() : -1);
                }
            } else if (op == 2) {
                vertices[x].offline = true;
            }
        }
        return ans;
    }
};


/**
3607. Power Grid Maintenance
Medium

You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).

These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element 
connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly 
connected form a power grid.

Initially, all stations are online (operational).

You are also given a 2D array queries, where each query is one of the following two types:

    [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. 
If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid 
as x. If no operational station exists in that grid, return -1.

    [2, x]: Station x goes offline (i.e., it becomes non-operational).

Return an array of integers representing the results of each query of type [1, x] in the order they appear.

Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking 
it offline does not alter connectivity.
 */
