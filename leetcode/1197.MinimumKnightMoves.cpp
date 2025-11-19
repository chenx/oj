// DFS (Top-Down Dynamic Programming)
// dfs(x,y) = min( dfs(∣x−2∣,∣y−1∣), dfs(∣x−1∣,∣y−2∣) ) + 1
// From: https://leetcode.com/problems/minimum-knight-moves/editorial/
// Time Complexity: O(∣x⋅y∣)
// Space Complexity: O(∣x⋅y∣)
class Solution3 {
public:
    map<string, int> memo;

    int dfs(int x, int y) {
        string key = to_string(x) + "," + to_string(y);
        if (memo.contains(key)) return memo[key];

        if (x + y == 0) return 0; // at origin.
        if (x + y == 2) return 2; // around origin, takes 2 steps to come to origin.
        
        int ret = min(dfs(abs(x - 1), abs(y - 2)),
                      dfs(abs(x - 2), abs(y - 1))) + 1;
        memo[key] = ret;
        return ret;
    }

    int minKnightMoves(int x, int y) {
        return dfs(abs(x), abs(y));
    }
};

// Same as Solution.
class Solution2 {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);
        int offsets[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                             {-2, 1}, {-1, 2}};

        unordered_set<string> visited;

        queue<vector<int>> queue;
        queue.push({0, 0, 0}); // (x, y, distance)

        while (queue.size() > 0) {
            int currLevelSize = queue.size();
            for (int i = 0; i < currLevelSize; i++) {
                vector<int> curr = queue.front();
                queue.pop();

                if (curr[0] == x && curr[1] == y) {
                    return curr[2];
                }

                for (auto offset : offsets) {
                    vector<int> next = {curr[0] + offset[0], curr[1] + offset[1], curr[2] + 1};
                    if (! visited.contains(to_string(next[0]) + "," + to_string(next[1]))) {
                        visited.insert(to_string(next[0]) + "," + to_string(next[1]));
                        queue.push(next);
                    }
                }
            }
        }
        return -1;
    }
};

// BFS.
// From: https://leetcode.com/problems/minimum-knight-moves/editorial/
// Time Complexity: O((max(∣x∣,∣y∣))^2)
// Space Complexity: O((max(∣x∣,∣y∣))^2)
class Solution {
public:
    int minKnightMoves(int x, int y) {
        int offsets[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                             {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        // - Rather than using the inefficient HashSet, we use the bitmap
        //     otherwise we would run out of time for the test cases.
        // - We create a bitmap that is sufficient to cover all the possible
        //     inputs, according to the description of the problem.
        vector<vector<bool>> visited(607, vector<bool>(607, false));

        queue<vector<int>> queue;
        queue.push({0, 0});
        int steps = 0;

        while (queue.size() > 0) {
            int currLevelSize = queue.size();
            for (int i = 0; i < currLevelSize; i++) {
                vector<int> curr = queue.front();
                queue.pop();

                if (curr[0] == x && curr[1] == y) {
                    return steps;
                }

                for (auto offset : offsets) {
                    vector<int> next = {curr[0] + offset[0], curr[1] + offset[1]};
                    // align the coordinate to the bitmap
                    if (! visited[next[0] + 302][next[1] + 302]) {
                        visited[next[0] + 302][next[1] + 302] = true;
                        queue.push(next);
                    }
                }
            }
            steps++;
        }
        // move on to the next level
        return steps;
    }
};

/**
1197. Minimum Knight Moves
Medium

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal 
direction, then one square in an orthogonal direction.

Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the 
answer exists.
 */
