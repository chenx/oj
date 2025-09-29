// Time: O(n) + O(m*n) = O(m*n), Space: O(n)
// n = equations.size(), m = queries.size().
//
// Another solution is Union Find, where Time complexity is O((m+n)*log(n)). See
// https://leetcode.com/problems/evaluate-division/editorial
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> mp;

        for (int i = 0, n = equations.size(); i < n; ++ i) {
            mp[equations[i][0]].push_back(pair<string, double>(equations[i][1], values[i]));
            mp[equations[i][1]].push_back(pair<string, double>(equations[i][0], 1.0 / values[i]));
        }

        for (int i = 0; i < queries.size(); ++ i) {
            string x = queries[i][0], y = queries[i][1];
            if (!mp.contains(x) || !mp.contains(y)) {  // Needs to go first. see below.
                ans.push_back(-1.0);
                continue;
            }
            if (x == y) {  // If x == y but x is undefined, still return -1.0 above.
                ans.push_back(1.0);
                continue;
            }

            unordered_set<string> visited;
            visited.insert(x);
            queue<pair<string, double>> q;
            for (auto& v : mp[x]) {
                q.push(v);
                visited.insert(v.first);
            }

            bool found = false;
            while (!q.empty()) {
                auto v = q.front();  // use "auto&" will cause error.
                q.pop();

                if (v.first == y) {
                    ans.push_back(v.second);
                    found = true;
                    break;
                }

                for (auto& u : mp[v.first]) {
                    if (!visited.contains(u.first)) { // need this, otherwise there is cycle.
                        q.push(pair<string, double>(u.first, v.second * u.second));
                    }
                }
            }
            if (!found) {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }
};

/**
399. Evaluate Devision

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] 
and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer 
for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and 
that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.
 */
