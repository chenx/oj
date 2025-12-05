// From: https://leetcode.com/problems/path-crossing/editorial/
// Since each step is of unit 1, so a node is visited again if self-crossing happens.
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0};
        
        set<vector<int>> visited;
        visited.insert({0, 0});
        
        int x = 0;
        int y = 0;
        
        for (char c : path) {
            pair<int, int> curr = moves[c];
            int dx = curr.first, dy = curr.second;
            x += dx;
            y += dy;
            
            if (visited.contains({x, y})) {
                return true;
            }
            
            visited.insert({x, y});
        }
        
        return false;
    }
};


/**
1496. Path Crossing
Easy

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, 
respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously 
visited. Return false otherwise.

 

Example 1:

Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.

Example 2:

Input: path = "NESWW"
Output: true
 */
