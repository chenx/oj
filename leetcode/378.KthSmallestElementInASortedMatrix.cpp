class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];  // ">" for minHeap.
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        for (int i = 0; i < matrix.size(); ++ i) {
            minHeap.push({matrix[i][0], i, 0});
        }

        while (! minHeap.empty()) {
            int val = minHeap.top()[0];
            int i = minHeap.top()[1];
            int j = minHeap.top()[2];
            minHeap.pop();

            if (-- k == 0) return val;

            if (j + 1 < matrix[0].size()) {
                minHeap.push({matrix[i][j + 1], i, j + 1});
            }
        }
        return 0;
    }
};


struct comp {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<vector<int>, vector<vector<int>>, comp> minHeap;

        for (int i = 0; i < n; ++ i) {
            minHeap.push({matrix[0][i], 0, i});
        }

        while (! minHeap.empty()) {
            int val = minHeap.top()[0];
            int x = minHeap.top()[1];
            int y = minHeap.top()[2];
            minHeap.pop();
            -- k;
            if (k == 0) return val;

            if (x+1 < n) minHeap.push({matrix[x+1][y], x+1, y});
        }
        return 0;
    }
};


/**
378. Kth Smallest Element in a Sorted Matrix
Medium

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).
 */
