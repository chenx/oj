// From: https://leetcode.com/problems/letter-case-permutation/editorial/
// Time Complexity: O(2^N * N), where N is the length of S. This reflects the cost of writing the answer.
// Space Complexity: O(2^N * N).
//
class Solution {
public:
    vector<string> letterCasePermutation(string& s) {
        vector<string> ans;
        ans.push_back("");

        for (char c: s) {
            int n = ans.size();
            if (isalpha(c)) {
                for (int i = 0; i < n; ++i) {
                    ans.push_back(ans[i]);
                    ans[i] += tolower(c);
                    ans[n+i] += toupper(c);
                }
            } else {
                for (int i = 0; i < n; ++i) {
                    ans[i].push_back(c);
                }
            }
        }

        return ans;
    }
};


/**
784. Letter Case Permutation
Medium

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
 */
