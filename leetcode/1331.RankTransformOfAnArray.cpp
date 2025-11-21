// Simplified from Solution.
class Solution2 {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        if (n == 1) return {1};

        vector<vector<int>> pos; // <num, index>
        for (int i = 0; i < n; ++ i) {
            pos.push_back({arr[i], i});
        }
        sort(pos.begin(), pos.end()); // order by first value.

        int rank = 1;
        arr[pos[0][1]] = 1;
        for (int i = 1; i < n; ++ i) {
            if (pos[i-1][0] < pos[i][0]) {
                ++ rank;
            }
            arr[pos[i][1]] = rank;
        }

        return arr;
    }
};


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        if (n == 1) return {1};

        vector<vector<int>> pos; // <num, index, rank>
        for (int i = 0; i < n; ++ i) {
            pos.push_back({arr[i], i, 0});
        }
        sort(pos.begin(), pos.end()); // order by first value.

        int rank = 1;
        pos[0][2] = 1;
        for (int i = 1; i < n; ++ i) {
            if (pos[i-1][0] < pos[i][0]) {
                pos[i][2] = ++ rank;
            } else { // pos[i-1] == pos[i]
                pos[i][2] = rank;
            }
        }

        for (int i = 0; i < n; ++ i) {
            arr[pos[i][1]] = pos[i][2];
        }
        return arr;
    }
};


/**
1331. Rank Transform of an Array
Easy

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.
 */
