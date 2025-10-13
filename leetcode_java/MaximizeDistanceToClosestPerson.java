// https://leetcode.com/problems/maximize-distance-to-closest-person/editorial/
class Solution {
    public int maxDistToClosest(int[] seats) {
        int n = seats.length;
        int prev = -1, future = 0, maxDist = 0;

        for (int i = 0; i < n; ++ i) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while ((future < n && seats[future] == 0) || future < i) {
                    ++ future;
                }

                int left = prev == -1 ? n : i - prev;
                int right = future == n ? n : future - i;
                maxDist = Math.max(maxDist, Math.min(left, right));
            }
        }
        return maxDist;
    }
}


/**
849. Maximize Distance to Closest Person
Medium

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting 
in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
 */
