// Time: O(log(n))
// Space: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1, ret = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                ret = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ret == -1 ? letters[0] : letters[ret]; // Note: left = ret in the latter case.
    }
};


// From: https://leetcode.com/problems/find-smallest-letter-greater-than-target/editorial/
// Time: O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left == letters.size() ? letters[0] : letters[left];
    }
};

// From: https://leetcode.com/problems/find-smallest-letter-greater-than-target/editorial/
// Time: O(n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0];
    }
};


/**
744. Find Smallest Letter Greater Than Target
Easy


You are given an array of characters letters that is sorted in non-decreasing order, and a character target. 
There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character 
does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
 */
