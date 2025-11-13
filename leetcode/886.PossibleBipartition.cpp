// DFS
class Solution3 {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int, set<int>> adj;
        for (auto e : dislikes) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        vector<int> colors(n+1, -1);

        for (int i = 1; i <= n; ++ i) {
            if (colors[i] == -1) {
                if (! dfs(colors, adj, i)) return false;
            }
        }
        return true;
    }

    bool dfs(vector<int>& colors, map<int, set<int>>& adj, int i) {
        if (colors[i] == -1) {
            colors[i] = 0;
        }

        for (int neighbor : adj[i]) {
            if (colors[neighbor] == colors[i]) return false;
            if (colors[neighbor] == -1) {
                colors[neighbor] = 1 - colors[i];
                if (! dfs(colors, adj, neighbor)) return false;
            }
        }
        return true;
    }
};

// BFS
class Solution2 {
    bool bfs(vector<int>& colors, int i, map<int, vector<int>>& adj) {
        queue<int> q;
        q.push(i);
        colors[i] = 0;

        while (! q.empty()) {
            int next = q.front();
            q.pop();

            for (int neighbor : adj[next]) {
                if (colors[neighbor] == colors[next]) return false;
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[next];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int, vector<int>> adj;  // use map instead of vector.
        for (auto e : dislikes) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> colors(n+1, -1);

        for (int i = 1; i <= n; ++ i) {
            if (colors[i] == -1) {
                if (! bfs(colors, i, adj)) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool bfs(int source, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(source);
        color[source] = 0;  // Start with marking source as `RED`.

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : adj[node]) {
                // If there is a conflict, return false.
                if (color[neighbor] == color[node]) return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        vector<int> color(n + 1, -1); // 0 stands for red and 1 stands for blue.
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run BFS.
                if (!bfs(i, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
};
