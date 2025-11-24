// From: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/editorial
// Let n be the length of the string.
// Time complexity: O(n * sqrt(n)).
// Space complexity: O(n).
// We use an array pre to mark the position of the nearest 0 before each position, so the space complexity is O(n).
//
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1); // number of 0s
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0';
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};



/**
3234. Count the Number of Substrings With Dominant Ones
Medium

You are given a binary string s.

Return the number of

with dominant ones.

A string has dominant ones if the number of ones in the string is greater than or equal to the 
square of the number of zeros in the string.
 */
