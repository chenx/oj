
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> count;
        int frogs = 0, maxFrogs = 0;

        for (char ch : croakOfFrogs) {
            if (ch == 'c') {
                ++ count['c'];
            } else if (ch == 'r') {
                if (++ count['r'] > count['c']) return -1;
            } else if (ch == 'o') {
                if (++ count['o'] > count['r']) return -1;
            } else if (ch == 'a') {
                if (++ count['a'] > count['o']) return -1;
            } else if (ch == 'k') {
                if (++ count['k'] > count['o']) return -1;
            }

            if (ch == 'c') {
                ++ frogs;
                maxFrogs = max(frogs, maxFrogs);
            } else if (ch == 'k') {
                -- frogs;
            }
        }

        int n = croakOfFrogs.length();
        if (frogs == 0 && (count['c'] == n/5 && count['r'] == n/5 && count['o'] == n/5 && 
            count['a'] == n/5 && count['k'] == n/5)) {
            return maxFrogs;
        }

        return -1;
    }
};

/**
// From AI:
Key Concepts

    Sequential Process: Each frog completes 'c' -> 'r' -> 'o' -> 'a' -> 'k' in order.
    Overlapping: Multiple frogs can croak simultaneously, hence the need for a minimum count.
    State Tracking: Use counters for each letter to know how many frogs are at each stage. 

Algorithm (Greedy Approach)

    Initialize Counters: countC, countR, countO, countA, countK = 0 and frogs = 0, maxFrogs = 0.
    Iterate Through String: For each character ch in croakOfFrogs:
        Increment Counter: count[ch]++ (using a map or array for 'c', 'r', 'o', 'a', 'k').
        Check Validity:
            If ch is 'r', check countR <= countC. If not, return -1.
            If ch is 'o', check countO <= countR. If not, return -1.
            ...and so on for 'a' and 'k'.
        Update Active Frogs:
            If ch is 'c', frogs++ (new frog starts).
            If ch is 'k', frogs-- (frog finishes).
        Track Maximum: maxFrogs = max(maxFrogs, frogs).
    Final Check: After the loop, if frogs == 0 (all croaks finished) and all counts are equal (or 0), return maxFrogs; 
                 otherwise, return -1. 

Examples

    "croakcroak": One frog does two full croaks. Max active: 1. Result: 1.
    "crcoakroak": Two frogs needed for overlap. Max active: 2. Result: 2.
    "croakcrook": Invalid ('k' before 'o' for the second one). Result: -1. 
 */


/**
1419. Minimum Number of Frogs Croaking
Medium

You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, 
that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to 
print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.

 

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.

Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.
 */
