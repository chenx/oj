class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        map<char, int> frequencyMap;
        int maxFrequency = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++ i) {
            frequencyMap[s[i]] ++;
            maxFrequency = max(maxFrequency, frequencyMap[s[i]]);

            // move the start pointer towards right if the current window is invalid
            bool is_valid = (i - start + 1 - maxFrequency) <= k;
            if (!is_valid) {
                frequencyMap[s[start]] --;
                start ++;
            }

            maxLen = i - start + 1; // the window is valid at this point.
        }

        return maxLen;
    }
};


/**
424. Longest Repeating Character Replacement
Solved
Medium
Topics
conpanies iconCompanies

You are given a string s and an integer k. You can choose any character of the string and change it 
to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing 
the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 */
