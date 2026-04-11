// This does not work, because set<string> does not allow duplicate edges.
/*
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;

        unordered_map<string, set<string>> outBound;
        for (const auto& ticket : tickets) {
            string from = ticket[0], to = ticket[1];
            outBound[from].insert(to);
        }

        dfs(result, outBound, "JFK");
        reverse(result.begin(), result.end());

        return result;
    }

    void dfs(vector<string>& result, unordered_map<string, set<string>>& outBound, string start) {
        while (! outBound[start].empty()) {
            string airport = *outBound[start].begin();
            outBound[start].erase(airport);
            dfs(result, outBound, airport);
        }
        result.push_back(start);
    }
};
*/

// Works. Hierholzer’s algorithm for finding an Eulerian path.
// vector + reverse-sorted + pop_back
// Let V = number of nodes, E = number of edges. Here only E matters.
// Time: O(E * logE). Build graph: O(E), sort: O(E*logE), DFS: O(E)
// Space: O(E), for outBound graph and DFS.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;

        unordered_map<string, vector<string>> outBound;
        for (const auto& ticket : tickets) {
            string from = ticket[0], to = ticket[1];
            outBound[from].push_back(to);
        }
        for (auto& [from, to] : outBound) {
            sort(to.begin(), to.end(), std::greater<string>());
        }

        dfs(result, outBound, "JFK");
        reverse(result.begin(), result.end());

        return result;
    }

    void dfs(vector<string>& result, unordered_map<string, vector<string>>& outBound, string start) {
        while (! outBound[start].empty()) {
            string airport = *outBound[start].rbegin();
            outBound[start].pop_back();
            dfs(result, outBound, airport);
        }
        result.push_back(start);
    }
};


/**
332. Reconstruct Itinerary
Solved
Hard
Topics
conpanies iconCompanies

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and 
the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical 
order when read as a single string.

    For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
 */
