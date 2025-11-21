// Use minHeap.
// Time: O(nlogn)
class Solution2 {
public:
    vector<int> findClosestElements2(vector<int>& arr, int k, int x) {
        priority_queue<vector<int>, vector<vector<int>>, compMinHeap> minHeap;

        for (int i = 0; i < arr.size(); ++ i) {
            minHeap.push({arr[i], abs(arr[i] - x)});
        }

        vector<int> result;
        for (int i = 0; i < k; ++ i) {
            result.push_back(minHeap.top()[0]);
            minHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }

    struct compMinHeap {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] > b[1];
        }
    };
};

// Use maxHeap.
// Time: O(n(logk + logn)) = O(nlogn)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<vector<int>, vector<vector<int>>, comp> maxHeap;

        int i = 0;
        for (; i < k; ++ i) {
            maxHeap.push({arr[i], abs(arr[i] - x)});
        }

        for (; i < arr.size(); ++ i) {
            int diff = abs(arr[i] - x);
            if (diff < maxHeap.top()[1] || (diff == maxHeap.top()[1] && arr[i] < maxHeap.top()[0])) {
                maxHeap.pop();
                maxHeap.push({arr[i], diff});
            }
        }

        vector<int> result;
        while (! maxHeap.empty()) {
            result.push_back(maxHeap.top()[0]);
            maxHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }

    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        }
    };
};


/**
658. Find K Closest Elements
Medium

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b

 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]
 */
