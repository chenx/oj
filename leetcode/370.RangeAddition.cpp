// Time: O(n+k)
// Space: O(1)
class Solution2 {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
        vector<int> result(length, 0);

        for (auto& tuple : updates) {
            int start = tuple[0], end = tuple[1], val = tuple[2];

            result[start] += val;
            if (end < length - 1)
                result[end + 1] -= val;
        }

        // partial_sum applies the following operation (by default) for the parameters {x[0], x[n], y[0]}:
        // y[0] = x[0]
        // y[1] = y[0] + x[1]
        // y[2] = y[1] + x[2]
        // ...  ...  ...
        // y[n] = y[n-1] + x[n]

        partial_sum(result.begin(), result.end(), result.begin());

        return result;
    }
};

// Naive.
// Time: O(nk), k is the number of update queries and n is the length of the array. 
// Space: O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
        vector<int> result(length, 0);

        for (auto& tuple : updates) {
            int start = tuple[0], end = tuple[1], val = tuple[2];

            for (int i = start; i <= end; i++) {
                result[i] += val;
            }
        }

        return result;
    }
};


/**
370. Range Addition
Medium

You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. 
In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.
 */
