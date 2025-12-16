// From: https://algo.monster/liteproblems/395
// Time: O(n^2)
// Space: O(n)
class Solution {
    int findLongestValidSubstring(string& s, int k, int left, int right) {
        int charFrequency[26] = {0};
        for (int i = left; i <= right; ++i) {
            charFrequency[s[i] - 'a']++;
        }
          
        // Find a character that appears but doesn't meet the minimum frequency k
        // This character will be used as a separator to split the string
        char separator = 0;
        for (int i = 0; i < 26; ++i) {
            if (charFrequency[i] > 0 && charFrequency[i] < k) {
                separator = 'a' + i;
                break;
            }
        }

        // If no separator found, all characters meet the requirement
        // Return the length of the current range
        if (separator == 0) {
            return right - left + 1;
        }
          
        // Split the string by the separator and recursively process each valid segment
        int currentIndex = left;
        int maxLength = 0;
          
        while (currentIndex <= right) {
            // Skip all consecutive separator characters
            while (currentIndex <= right && s[currentIndex] == separator) {
                ++currentIndex;
            }
              
            // Check if we've reached the end
            if (currentIndex >= right) {
                break;
            }
              
            // Find the end of the current valid segment (before next separator)
            int segmentEnd = currentIndex;
            while (segmentEnd <= right && s[segmentEnd] != separator) {
                ++segmentEnd;
            }
              
            // Recursively find the longest valid substring in this segment
            int segmentLength = findLongestValidSubstring(s, k, currentIndex, segmentEnd - 1);
            maxLength = max(maxLength, segmentLength);
              
            // Move to the next segment
            currentIndex = segmentEnd;
        }
          
        return maxLength;
    }

public:
    int longestSubstring(string s, int k) {
        return findLongestValidSubstring(s, k, 0, s.length() - 1);
    }
};


/**
395. Longest Substring with At Least K Repeating Characters
Medium

Given a string s and an integer k, return the length of the longest substring of s such that the frequency 
of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 */
