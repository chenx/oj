// Time: O(n)
// Space: O(26)
class Solution {
public:
    int maxDifference(string s) {
        map<char, int> freq; // <char, frequency>
        for (char ch : s) ++ freq[ch];

        int maxOddFreq = 0, minEvenFreq = INT_MAX;
        for (auto [ch, count] : freq) {
            if (count % 2 == 1) maxOddFreq = max(maxOddFreq, count);
            else minEvenFreq = min(minEvenFreq, count);
        }
        // here it's guaranteed minEvenFreq != 0
        // if (minEvenFreq == INT_MAX) minEvenFreq = 0;
        return maxOddFreq - minEvenFreq;
    }
};


/**
3442. Maximum Difference Between Even and Odd Frequency I
Easy

You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

    a1 has an odd frequency in the string.
    a2 has an even frequency in the string.

Return this maximum difference.

 

Example 1:

Input: s = "aaaaabbc"

Output: 3
 */
