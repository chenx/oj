/**
Let's think through this step by step. If we have multiple rabbits all saying "2", each is claiming to be 
part of a group of 3 rabbits. Could they all be the same color? Well, if we have 3 or fewer rabbits saying 
"2", they could all be the same color (one group of 3). But if we have 4 rabbits saying "2", we'd need at 
least 2 color groups since one group can only hold 3 rabbits.

This leads us to a greedy approach: for rabbits giving the same answer x, we should pack them into groups 
of size x + 1 as efficiently as possible. If we have v rabbits giving answer x, and each color group holds 
x + 1 rabbits, we need ceil(v / (x + 1)) groups.

The ceiling division can be calculated as (v + x) // (x + 1), and since each group contains x + 1 rabbits, 
the total number of rabbits for this answer is ceil(v / (x + 1)) * (x + 1), which equals ((v + x) // (x + 1)) * (x + 1).
 */

// From: https://algo.monster/liteproblems/781
//
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // Map to store frequency of each answer
        // Key: number of other rabbits with same color (as reported)
        // Value: count of rabbits reporting this number
        unordered_map<int, int> frequencyMap;
      
        // Count the frequency of each answer
        for (int answer : answers) {
            ++ frequencyMap[answer];
        }
      
        // Calculate minimum number of rabbits
        int minRabbits = 0;
      
        // Process each unique answer and its frequency
        for (auto& [otherRabbits, frequency] : frequencyMap) {
            // If a rabbit says there are 'otherRabbits' other rabbits with same color,
            // then there are at most (otherRabbits + 1) rabbits in that color group
            int groupSize = otherRabbits + 1;
          
            // Calculate minimum number of groups needed for 'frequency' rabbits
            // reporting the same answer
            // Formula: ceiling(frequency / groupSize) * groupSize
            // which equals (frequency + groupSize - 1) / groupSize * groupSize
            int numGroups = (frequency + groupSize - 1) / groupSize;
            minRabbits += numGroups * groupSize;
        }
      
        return minRabbits;
    }
};


// From: https://leetcode.com/problems/rabbits-in-forest/editorial/
// Time Complexity: O(N), where N is the number of rabbits that answered.
// Space Complexity: O(N).
//
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> count(1000);
        for (int x: answers) count[x]++;

        int ans = 0;
        for (int k = 0; k < 1000; ++k) {
            ans += floorMod(-count[k], k+1) + count[k];
        }
        return ans;
    }

    int floorMod(int x, int y) {
        int result = x % y;
        // If the result has a different sign than y, adjust it.
        // This handles cases where x % y is negative when y is positive,
        // or positive when y is negative (though this is less common with C++'s % behavior).
        if ((result < 0 && y > 0) || (result > 0 && y < 0)) {
            result += y;
        }
        return result;
    }
};


/**
781. Rabbits in Forest
Medium

There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" 
and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

 

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Example 2:

Input: answers = [10,10,10]
Output: 11
 */
