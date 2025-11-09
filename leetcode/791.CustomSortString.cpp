class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> map;
        for (char c : s) ++ map[c];

        string ans;
        for (char c : order) {
            while (map[c] > 0) {
                ans += c;
                -- map[c];
            }
        }

        for (auto [c, count] : map) {
            while (map[c] > 0) {
                ans += c;
                -- map[c];
            }
        }
        return ans;
    }

    string customSortString2(string order, string s) {
        sort(s.begin(), s.end(), [order](char c1, char c2) {
            return order.find(c1) < order.find(c2);
        });
        return s;
    }
};

/**
791. Custom Sort String
Medium

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs 
before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
 */
