// Time: O(V + E)
// Space: O(V)
class Solution3 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) return true;

        queue<int> q;
        for (int k : rooms[0]) {
            q.push(k);
        }

        set<int> visited;
        visited.insert(0);

        while (! q.empty()) {
            int room = q.front();
            q.pop();

            if (! visited.contains(room)) {
                visited.insert(room);
                for (int k : rooms[room]) {
                    q.push(k);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};

class Solution2 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> keys;
        set<int> visited;
        visited.insert(0);

        for (int key : rooms[0]) {
            keys.push(key);
            visited.insert(key);
        }

        while (! keys.empty()) {
            int key = keys.front();
            keys.pop();

            for (int k : rooms[key]) {
                if (! visited.contains(k)) {
                    keys.push(k);
                    visited.insert(k);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};

// BFS
// Time: O(V+E)
// Space: O(V)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.size() <= 1) return true;

        queue<int> q;
        set<int> used;
        for (int v : rooms[0]) {
            q.push(v);
            used.insert(v);
        }

        int count = 1; // for room 0.
        while (! q.empty()) {
            int k = q.front();
            q.pop();
            if (k != 0) ++ count;

            for (int v : rooms[k]) {
                if (! used.contains(v)) {
                    q.push(v);
                    used.insert(v);
                }
            }
        }

        return count == rooms.size();
    }
};

/**
841. Keys and Rooms
Solved
Medium
Topics
conpanies iconCompanies

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is 
to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting 
which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return 
true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 */
