// From: https://leetcode.com/problems/maximize-distance-to-closest-person/editorial/
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), prev = -1, next = 0, maxDist = 0;

        for (int i = 0; i < n; ++ i) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while ((next < n && seats[next] == 0) || next < i) {
                    ++ next;
                }

                int left = prev == -1 ? n : i - prev;
                int right = next == n ? n : next - i;
                maxDist = max(maxDist, min(left, right));
            }
        }
        return maxDist;
    }
};


/**
849. Maximize Distance to Closest Person
Solved
Medium
Topics
conpanies iconCompanies

You are given an array representing a row of seats where seats[i] = 1 represents a person 
sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to 
him is maximized. 

Return that maximum distance to the closest person.

 

Example 1:

Input: seats = [1,0,0,0,1,0,1]
Output: 2
 */
