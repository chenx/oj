// Solvable is target is a multiple of gcd(x, y), and target <= x + y.
// See: https://algo.monster/liteproblems/365
// Time: O(log(min(x, y)))
// Space: O(1)
class Solution2 {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x == 0 || y == 0) return target == x || target == y;
        if (x + y < target) return false;
        if (target == 0) return true;

        return target % gcd(x, y) == 0;
    }
};

// Solution 1: DFS (BFS?)
// Time: O(mn)
// Space: O(mn)
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        using State = pair<int, int>;

        // Stack for DFS traversal of possible states
        stack<State> stateStack;
        stateStack.emplace(0, 0);  // Start with both jugs empty
      
        // Custom hash function for pair<int, int> to use in unordered_set
        auto hashFunction = [](const State& state) { 
            return hash<int>()(state.first) ^ hash<int>()(state.second); 
        };
      
        // Set to track visited states to avoid infinite loops.
        unordered_set<State, decltype(hashFunction)> visitedStates(0, hashFunction); // !!! <---
      
        // DFS to explore all possible states
        while (!stateStack.empty()) {
            State currentState = stateStack.top();
            stateStack.pop();
          
            // Skip if this state has already been visited
            if (visitedStates.count(currentState)) {
                continue;
            }
          
            // Mark current state as visited
            visitedStates.emplace(currentState);
          
            // Extract water amounts in both jugs
            auto [waterInJug1, waterInJug2] = currentState;
          
            // Check if we've reached the target amount
            if (waterInJug1 == z || waterInJug2 == z || waterInJug1 + waterInJug2 == z) {
                return true;
            }
          
            // Generate all possible next states from current states
            // Operation 1: Fill jug1 completely
            stateStack.emplace(x, waterInJug2);
          
            // Operation 2: Fill jug2 completely
            stateStack.emplace(waterInJug1, y);
          
            // Operation 3: Empty jug1
            stateStack.emplace(0, waterInJug2);
          
            // Operation 4: Empty jug2
            stateStack.emplace(waterInJug1, 0);
          
            // Operation 5: Pour from jug1 to jug2
            // Amount to pour = min(water in jug1, space left in jug2)
            int pourAmount1To2 = min(waterInJug1, y - waterInJug2);
            stateStack.emplace(waterInJug1 - pourAmount1To2, waterInJug2 + pourAmount1To2);
          
            // Operation 6: Pour from jug2 to jug1
            // Amount to pour = min(water in jug2, space left in jug1)
            int pourAmount2To1 = min(waterInJug2, x - waterInJug1);
            stateStack.emplace(waterInJug1 + pourAmount2To1, waterInJug2 - pourAmount2To1);
        }
      
        // No valid state found that gives us exactly z liters
        return false;
    }
};


/**
365. Water and Jug Problem
Medium

You are given two jugs with capacities x liters and y liters. You have an infinite water supply. 
Return whether the total amount of water in both jugs may reach target using the following operations:

    Fill either jug completely with water.
    Completely empty either jug.
    Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.

 

Example 1:

Input: x = 3, y = 5, target = 4

Output: true
 */
