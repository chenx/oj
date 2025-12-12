class Solution3 {
    int getDistance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> pairs; // <distance, worker, bike>

        for (int i = 0; i < workers.size(); ++ i) {
            for (int j = 0; j < bikes.size(); ++ j) {
                int distance = getDistance(workers[i], bikes[j]);
                pairs.push_back( {distance, i, j} );
            }
        }
        // sort(pairs.begin(), pairs.end());
        sort(pairs.begin(), pairs.end(), [&](vector<int>& a, vector<int>& b) {
            // Must compare all 3.
            if (a[0] == b[0]) {
                if (a[1] == b[1]) return a[2] < b[2];
                return a[1] < b[1];
            } 
            return a[0] < b[0]; 
        });

        vector<int> workerStatus(workers.size(), -1); // bike number assigned to each worker
        vector<int> bikeIsUsed(bikes.size(), -1); // worker number assigned to each bike.

        int count = 0;
        for (auto& pair : pairs) {
            int dist = pair[0], workerIndex = pair[1], bikeIndex = pair[2];
            if (workerStatus[workerIndex] == -1 && bikeIsUsed[bikeIndex] == -1) {
                workerStatus[workerIndex] = bikeIndex;
                bikeIsUsed[bikeIndex] = workerIndex;
                ++ count;
            }

            if (count == bikes.size()) break;
        }
        return workerStatus;
    }
};


// Same as Solution.
class Solution2 {
    int getDistance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int, int, int>> pairs; // <distance, worker, bike>

        for (int i = 0; i < workers.size(); ++ i) {
            for (int j = 0; j < bikes.size(); ++ j) {
                int distance = getDistance(workers[i], bikes[j]);
                pairs.push_back( {distance, i, j} );
            }
        }
        sort(pairs.begin(), pairs.end());
        // Or use something like this, but needs to compare all 3 like in Solution3: 
        // sort(pairs.begin(), pairs.end(), [&](tuple<int, int, int>& a, tuple<int, int, int>& b) { return get<0>(a) < get<0>(b); });

        vector<int> workerStatus(workers.size(), -1); // bike number assigned to each worker
        vector<int> bikeIsUsed(bikes.size(), -1); // worker number assigned to each bike.

        int count = 0;
        for (auto [dist, workerIndex, bikeIndex] : pairs) {
            if (workerStatus[workerIndex] == -1 && bikeIsUsed[bikeIndex] == -1) {
                workerStatus[workerIndex] = bikeIndex;
                bikeIsUsed[bikeIndex] = workerIndex;
                ++ count;
            }

            if (count == bikes.size()) break;
        }
        return workerStatus;
    }
};


class Solution {
public:
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }

    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // List of WorkerBikeTuples's to store all the possible triplets
        vector<tuple<int, int, int>> allTriplets;
        
        // Generate all the possible pairs
        for (int worker = 0; worker < workers.size(); worker++) {
            for (int bike = 0; bike < bikes.size(); bike++) {
                int distance = findDistance(workers[worker], bikes[bike]);        
                allTriplets.push_back({distance, worker, bike});
            }
        }
        
        // Sort the triplets. By default, each sorting will prioritize the
        // Tuple's first value, then second value, and finally the third value
        sort(allTriplets.begin(), allTriplets.end());  
        
        // Initialize all values to false, to signify no bikes have been taken
        vector<int> bikeStatus(bikes.size(), false);
        // Initialize all index to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        // Keep track of how many worker-bike pairs have been made
        int pairCount = 0;
        
        for (auto[dist, worker, bike] : allTriplets) { 
            // If both worker and bike are free, assign them to each other
            if (workerStatus[worker] == -1 && !bikeStatus[bike]) {
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
                pairCount++;
                
                // If all the workers have the bike assigned, we can stop
                if (pairCount == workers.size()) {
                    return workerStatus;
                }
            }
        }
        
        return workerStatus;
    }
};


/**
1057. Campus Bikes
Medium

On a campus represented on the X-Y plane, there are n workers and m bikes, with n <= m.

You are given an array workers of length n where workers[i] = [xi, yi] is the position of the ith worker. 
You are also given an array bikes of length m where bikes[j] = [xj, yj] is the position of the jth bike. 
All the given positions are unique.

Assign a bike to each worker. Among the available bikes and workers, we choose the (workeri, bikej) pair 
with the shortest Manhattan distance between each other and assign the bike to that worker.

If there are multiple (workeri, bikej) pairs with the same shortest Manhattan distance, we choose the pair 
with the smallest worker index. If there are multiple ways to do that, we choose the pair with the smallest 
bike index. Repeat this process until there are no available workers.

Return an array answer of length n, where answer[i] is the index (0-indexed) of the bike that the ith worker 
is assigned to.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
 */
