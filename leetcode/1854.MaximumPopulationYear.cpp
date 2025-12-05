// Simplified from Solution, since map is ordered, there is no need to change to vector.
// Time: O(n log(n)), n = logs.size(). Set and map insertion of n elements are log(n) each, due to the balanced tree used.
//   if use unordered_map here, insertion is O(n), but need a sorting step.
// Space: O(m), m = number of different years in logs.
class Solution2 {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> delta; // year, change-of-population.
        for (auto log : logs) {
            ++ delta[log[0]];
            -- delta[log[1]];
        }

        int maxPopulation = 0, population = 0, maxPopulationYear = 0;
        // std::set and std::map in C++ are sorted containers in ASC order by default.
        for (auto [year, change] : delta) {
            population += change;
            if (population > maxPopulation) {
                maxPopulation = population;
                maxPopulationYear = year;
            }
        }
        return maxPopulationYear;
    }
};


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> delta; // year, change-of-population.
        for (auto log : logs) {
            ++ delta[log[0]];
            -- delta[log[1]];
        }

        vector<vector<int>> arr;
        for (auto [year, change] : delta) {
            arr.push_back({year, change});
        }
        // std::set and std::map in C++ are sorted containers in ASC order by default.
        // sort(arr.begin(), arr.end()); // so no sorting is needed here.

        int maxPopulation = 0, population = 0, maxPopulationYear = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            population += arr[i][1];
            if (population > maxPopulation) {
                maxPopulation = population;
                maxPopulationYear = arr[i][0];
            }
        }
        return maxPopulationYear;
    }
};


/**
1854. Maximum Population Year
Easy


You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the 
birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person 
is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note 
that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

 

Example 1:

Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
 */
