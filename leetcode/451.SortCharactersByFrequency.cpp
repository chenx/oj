// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    string frequencySort(string s) {
        map<char, int> frequency;
        for (char ch : s) ++ frequency[ch];

        map<int, vector<char>> bucket;
        int maxFreq = 0;
        for (auto [ch, count] : frequency) {
            bucket[count].push_back(ch);
            maxFreq = max(maxFreq, count);
        }

        string result;
        for (int i = maxFreq; i > 0; -- i) {
            for (auto ch : bucket[i]) {
                result += string(i, ch);
            }
        }

        return result;
    }
};

// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frequency;
        for (char ch : s) ++ frequency[ch];

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (frequency[a] != frequency[b]) {
                return frequency[a] > frequency[b];
            }
            return a < b;
        });
        return s;
    }
};


/**
451. Sort Characters By Frequency
Medium

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */
