// From: https://leetcode.com/problems/move-pieces-to-obtain-a-string/editorial/
// Time: O(n), Space: O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0; // Pointer for start string and target string

        while (i < n || j < n) {
            while (i < n && start[i] == '_') {
                i++; // Skip underscores in start
            }
            while (j < n && target[j] == '_') {
                j++; // Skip underscores in target
            }
            // If one string is exhausted, both should be exhausted
            if (i == n || j == n) {
                return i == n && j == n;
            }

            // Check if the pieces match and follow movement rules
            if (start[i] != target[j] ||
                (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                return false;

            i++;
            j++;
        }

        return true;
    }
};

/**
2337. Move Pieces to Obtain a String
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

    The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if 
        there is a blank space directly to its left, and a piece 'R' can move to the right only if 
        there is a blank space directly to its right.
    The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.

Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. 
Otherwise, return false.

 

Example 1:

Input: start = "_L__R__R_", target = "L______RR"
Output: true
 */
