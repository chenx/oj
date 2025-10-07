// Times out.
class Solution {
    vector<vector<int>> findRoute(vector<vector<int>>& routes, int busStop) {
        vector<vector<int>> result;
        for (auto route: routes) {
            for (int stop : route) {
                if (stop == busStop) {
                    result.push_back(route);
                    break;
                }
            }
        }
        return result;
    }

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if (n <= 1) return 0;
        if (source == target) return 0;
        
        queue<pair<vector<int>, int>> q;
        vector<vector<int>> sourceRoutes = findRoute(routes, source);
        // if (sourceRoutes.empty()) return -1; // error
        
        set<int> usedStops;
        usedStops.insert(source);
        set<vector<int>> usedRoutes;

        for (auto route : sourceRoutes) {
            // pair<vector<int>, int>: pair of <route, distance>
            q.push(pair<vector<int>, int>(route, 1));
            usedRoutes.insert(route);
        }

        while (!q.empty()) {
            vector<int> route = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (find(route.begin(), route.end(), target) != route.end()) {
                return distance;
            }

            // search for the next route.
            // for each bus stop in route, look for other routes that contains it
            // if contains it, push the route to the back of the queue
            for (int stop : route) {
                // if (usedStops.count(stop) > 0) continue;
                // usedStops.insert(stop);
                vector<vector<int>> nextRoutes = findRoute(routes, stop);
                for (auto nextRoute : nextRoutes) {
                    if (usedRoutes.count(nextRoute) > 0) continue;
                    usedRoutes.insert(nextRoute);
                    q.push(pair<vector<int>, int>(nextRoute, distance + 1));
                }
            }
        }

        return -1;
    }
};


/**
815. Bus Routes

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

    For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 
    1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. 
You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
 */
