// Use Trie.
// See: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/editorial/
// Time: O(a + b)
// Space: O(a)
class TrieNode {
public:
    // Each node has up to 10 possible children (digits 0-9)
    TrieNode* children[10];
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    // Insert a number into the Trie by treating it as a string of digits
    void insert(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        for (char digit : numStr) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    // Find the longest common prefix for a number in arr2 with the Trie
    int findLongestPrefix(int num) {
        TrieNode* node = root;
        string numStr = to_string(num);
        int len = 0;

        for (char digit : numStr) {
            int idx = digit - '0';
            if (node->children[idx]) {
                // Increase length if the current digit matches
                len++;
                node = node->children[idx];
            } else {
                // Stop if no match for the current digit
                break;
            }
        }
        return len;
    }
};

class Solution3 {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        // Step 1: Insert all numbers from arr1 into the Trie
        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        // Step 2: Find the longest prefix match for each number in arr2
        for (int num : arr2) {
            int len = trie.findLongestPrefix(num);
            longestPrefix = max(longestPrefix, len);
        }

        return longestPrefix;
    }
};

// Use a set to store prefixes.
// Let a = arr1.length(), b = arr2.length()
// Time: O(a * 32 + b * 32)
// Space: O(a * 32)
class Solution2 {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixSet;
        for (int a : arr1) {
            while (a > 0) {
                prefixSet.insert(a);
                a /= 10;
            }
        }

        int maxLen = 0;
        for (int b : arr2) {
            while (b > 0) {
                if (prefixSet.contains(b)) {
                    maxLen = max(maxLen, (int) to_string(b).length());
                    break;
                }
                b /= 10;
            }
        }
        return maxLen;
    }
};

// Time: O(a * b * m). a = arr1.length(), b = arr2.length(), m = max length of a string
// Space: O(1)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen = 0;
        for (int a : arr1) {
            for (int b : arr2) {
                maxLen = max(maxLen, getLongestCommonPrefixLen(a, b));
            }
        }
        return maxLen;
    }

    int getLongestCommonPrefixLen(int a, int b) {
        string sa = to_string(a), sb = to_string(b);
        int len = 0;
        for (int i = 0; i < sa.length() && i < sb.length(); ++ i) {
            if (sa[i] == sb[i]) ++ len;
            else break;
        }
        return len;
    }
};


/**
3043. Find the Length of the Longest Common Prefix
Medium

You are given two arrays with positive integers arr1 and arr2.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.

You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

 

Example 1:

Input: arr1 = [1,10,100], arr2 = [1000]
Output: 3
Explanation: There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.

Example 2:

Input: arr1 = [1,2,3], arr2 = [4,4,4]
Output: 0
Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
Note that common prefixes between elements of the same array do not count.
 */
