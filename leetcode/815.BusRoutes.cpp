// BFS by routes. Works.
// M is the size of routes, and K is the maximum size of routes[i].
// Time complexity: O(M^2⋅K+M⋅k⋅logK)
// Space complexity: O(M^2+logK)
class Solution6 {
public:
    // Go from a stop, try each route, 
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, unordered_set<int>> routesOfStop;
        for (int i = 0; i < routes.size(); ++ i) {
            for (int busStop: routes[i]) {
                routesOfStop[busStop].insert(i);
            }
        }

        set<int> visited; // visited routes.
        queue<int> q; // queue of routes.

        for (int route : routesOfStop[source]) {
            q.push(route);
            visited.insert(route);
        }

        int distance = 0;
        while (! q.empty()) {
            ++ distance;
            int len = q.size();
            for (int i = 0; i < len; ++ i) {
                int route = q.front();
                q.pop();

                for (int stop : routes[route]) {
                    if (stop == target) {
                        return distance;
                    }
                    
                    for (int nextRoute : routesOfStop[stop]) {
                        if (! visited.contains(nextRoute)) {
                            visited.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

// BFS by bus stops.
// Times out for large input.
// M is the size of routes, and K is the maximum size of routes[i].
// Time complexity: O(M^2⋅K)
// Space complexity: O(M⋅K)
class Solution5 {
public:
    // Go from a stop, try each route, 
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, unordered_set<int>> routesOfStop;
        for (int i = 0; i < routes.size(); ++ i) {
            for (int busStop: routes[i]) {
                routesOfStop[busStop].insert(i);
            }
        }

        set<int> visited; // visited stops.
        queue<int> q; // q of stops.
        q.push(source);
        visited.insert(source);

        int distance = 0;
        while (! q.empty()) {
            ++ distance;
            int len = q.size();
            for (int i = 0; i < len; ++ i) {
                int busStop = q.front();
                q.pop();

                for (int route: routesOfStop[busStop]) {
                    for (int nextBusStop: routes[route]) {
                        if (! visited.contains(nextBusStop)) {
                            if (nextBusStop == target) {
                                return distance;
                            }
                            q.push(nextBusStop);
                            visited.insert(nextBusStop);
                        }
                    }
                }
            }
        }
        return -1;
    }
};


// Works.
// Breadth-First Search (BFS) with Bus Stops as Nodes
// From: https://leetcode.com/problems/bus-routes/editorial/
//
// M is the size of routes, and K is the maximum size of routes[i].
// Time complexity: O(M^2 * K)
// Space: O(MK)
class Solution4 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        map<int, vector<int>> stops;  // <stop, set<route>>
        for (int i = 0; i < routes.size(); ++ i) {  // O(M)
            for (int stop : routes[i]) {  // O(K)
                stops[stop].push_back(i);
            }
        }

        set<int> used;

        queue<pair<int, int>> q;
        for (auto route : stops[source]) {  // O(M)
            q.push({route, 1});
            used.insert(route);
        }

        while (!q.empty()) {  // O(M)
            int route = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (int stop : routes[route]) {  // O(K)
                if (stop == target) return dist;

                auto nextRoutes = stops[stop];
                for (int nextRoute : nextRoutes) {  // O(M)
                    if (used.contains(nextRoute)) continue;
                    used.insert(nextRoute);
                    q.push({nextRoute, dist + 1});
                }
            }
        }

        return -1;
    }
};

// Works.
class Solution3 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if (n <= 1) return 0;
        if (source == target) return 0;

        map<int, vector<int>> ajList;  // <stop, routes> map
        for (int i = 0; i < routes.size(); ++ i) {
            for (auto stop : routes[i]) {
                ajList[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        set<int> usedRoutes;

        for (auto route : ajList[source]) {
            // pair<vector<int>, int>: pair of <route, distance>
            q.push(pair<int, int>(route, 1));
            usedRoutes.insert(route);
        }

        while (!q.empty()) {
            int route = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (find(routes[route].begin(), routes[route].end(), target) != routes[route].end()) {
                return distance;
            }

            // search for the next route.
            // for each bus stop in route, look for other routes that contains it
            // if contains it, push the route to the back of the queue
            for (int stop : routes[route]) {
                for (auto nextRoute : ajList[stop]) {
                    if (usedRoutes.count(nextRoute) > 0) continue;
                    usedRoutes.insert(nextRoute);
                    q.push(pair<int, int>(nextRoute, distance + 1));
                }
            }
        }

        return -1;
    }
};

// Works.
// From https://leetcode.com/problems/bus-routes/editorial
class Solution2 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adjList;
        // Create a map from the bus stop to all the routes that include this
        // stop.
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                // Add all the routes that have this stop.
                adjList[stop].push_back(route);
            }
        }

        queue<int> q;
        unordered_set<int> vis;
        // Insert all the routes in the queue that have the source stop.
        for (auto route : adjList[source]) {
            q.push(route);
            vis.insert(route);
        }

        int busCount = 1;
        while (q.size()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.front();
                q.pop();

                // Iterate over the stops in the current route.
                for (auto stop : routes[route]) {
                    // Return the current count if the target is found.
                    if (stop == target) {
                        return busCount;
                    }

                    // Iterate over the next possible routes from the current
                    // stop.
                    for (auto nextRoute : adjList[stop]) {
                        if (!vis.count(nextRoute)) {
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};

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
