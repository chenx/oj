class Solution3 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> outBound; // <from, to, price>
        for (auto& f : flights) {
            outBound[f[0]].push_back({f[1], f[2]});
        }

        queue<tuple<int, int, int>> q; // <airport, price, stops>
        q.push({src, 0, 0});

        vector<int> prices(n, -1);

        while (! q.empty()) {
            auto [airport, price, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto& [nextAirport, nextPrice] : outBound[airport]) {
                int newPrice = price + nextPrice;
                if (prices[nextAirport] == -1 || prices[nextAirport] > newPrice) {
                    prices[nextAirport] = newPrice;
                    q.push({nextAirport, newPrice, stops + 1});
                }
            }
        }

        return prices[dst];
    }
};

// BFS.
// Reference: https://leetcode.com/problems/cheapest-flights-within-k-stops/editorial/
// Time: Let E be the number of flights and N be the number of cities.
// Time / Space complexity: O(N+E⋅K)
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) return 0;

        unordered_map<int, set<pair<int, int>>> outBound; // <src, <dst, price>>
        for (auto& f : flights) {
            outBound[f[0]].insert({f[1], f[2]});
        }

        queue<vector<int>> q; // <airport, price, stops>
        q.push({src, 0, k});

        vector<int> prices(n, -1);

        while (! q.empty()) {
            int airport = q.front()[0];
            int price = q.front()[1];
            int stops = q.front()[2];
            q.pop();

            for (auto& [nextAirport, nextPrice] : outBound[airport]) {
                if (stops >= 0) {
                    int newPrice = price + nextPrice;
                    if (prices[nextAirport] == -1 || prices[nextAirport] > newPrice) {
                        prices[nextAirport] = newPrice;
                        q.push({nextAirport, newPrice, stops - 1});
                    }        
                }
            }
        }

        return prices[dst];
    }
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) return 0;

        unordered_map<int, set<pair<int, int>>> outBound; // <src, <dst, price>>
        for (auto& f : flights) {
            outBound[f[0]].insert({f[1], f[2]});
        }

        queue<tuple<int, int, int>> q; // <airport, price, stops>
        q.push(std::make_tuple(src, 0, k));

        vector<int> prices(n, -1);

        while (! q.empty()) {
            auto [airport, price, stops] = q.front();
            q.pop();

            for (auto& [nextAirport, nextPrice] : outBound[airport]) {
                if (stops >= 0) {
                    int newPrice = price + nextPrice;
                    if (prices[nextAirport] == -1 || prices[nextAirport] > newPrice) {
                        prices[nextAirport] = newPrice;
                        q.push({nextAirport, newPrice, stops - 1});
                    }        
                }
            }
        }

        return prices[dst];
    }
};


/**
787. Cheapest Flights Within K Stops
Solved
Medium
Topics
conpanies iconCompanies

There are n cities connected by some number of flights. You are given an array flights where 
flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst 
with at most k stops. If there is no such route, return -1.

 

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 */
