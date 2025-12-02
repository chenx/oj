// From: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/editorial/
// Recursion.
// Time complexity: O(2^N) where N is the length of arr.
// Space complexity: O(N) for optSet, optArr, and the max depth of the recursion stack.
class Solution {
public:
    int maxLength(vector<string>& arr) {        
        unordered_set<int> optSet;
        for (auto& word : arr) wordToBitSet(optSet, word);

        vector<int> optArr(optSet.begin(), optSet.end());
        return dfs(optArr, 0, 0);
    }
    
private:    
    void wordToBitSet(unordered_set<int>& optSet, string& word) {
        int charBitSet = 0;
        for (char& c : word) {
            // If the bitset contains a duplicate character
            // then discard this word with an early return
            // otherwise add the character to the bitset
            int mask = 1 << c - 'a';
            if (charBitSet & mask) return;
            charBitSet += mask;
        }

        // Store the length of the word in the unused space
        // then add the completed bitset to our optimized set
        optSet.insert(charBitSet + (word.length() << 26));
    }
    
    int dfs(vector<int>& optArr, int pos, int res) {
        // Separate the parts of the bitset res
        int oldChars = res & ((1 << 26) - 1);
        int oldLen = res >> 26;
        int best = oldLen;
        
        // Iterate through the remaining results
        for (int i = pos; i < optArr.size(); i++) {
            int newChars = optArr[i] & ((1 << 26) - 1);
            int newLen = optArr[i] >> 26;
            
            // If the two bitsets overlap, skip to the next result
            if (newChars & oldChars) continue;
            
            // Combine the two results and trigger the next recursion
            int newRes = newChars + oldChars + (newLen + oldLen << 26);
            best = max(best, dfs(optArr, i + 1, newRes));
        }
        return best;
    }
};


/**
1239. Maximum Length of a Concatenated String with Unique Characters
Medium

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr 
that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without 
changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
 */
