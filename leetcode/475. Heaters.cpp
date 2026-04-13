// Binary search.
// From: https://algo.monster/liteproblems/475
// Time Complexity: O((m + n) * log(m + n) + (m + n) * log(max_distance))
// Space Complexity: O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        auto feasible = [&](int radius) {
            int houseIdx = 0;
            int heaterIdx = 0;

            while (houseIdx < (int)houses.size()) {
                if (heaterIdx >= (int)heaters.size()) {
                    return false;
                }

                int minCoverage = heaters[heaterIdx] - radius;
                int maxCoverage = heaters[heaterIdx] + radius;

                if (houses[houseIdx] < minCoverage) {
                    return false;
                }
                if (houses[houseIdx] > maxCoverage) {
                    heaterIdx++;
                } else {
                    houseIdx++;
                }
            }

            return true;
        };

        int left = 0, right = 1000000000;
        int firstTrueIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (feasible(mid)) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstTrueIndex;
    }
};


/**
475. Heaters
Solved
Medium
Topics
conpanies iconCompanies

Winter is coming! During the contest, your first job is to design a standard heater with a 
fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius 
standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will be the same.

 

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, 
then all the houses can be warmed.

Example 2:

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, 
then all the houses can be warmed.

Example 3:

Input: houses = [1,5], heaters = [2]
Output: 3
 */
