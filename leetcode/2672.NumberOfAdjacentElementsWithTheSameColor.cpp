// From: https://algo.monster/liteproblems/2672
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> result;

        int count = 0;
        vector<int> colors(n, 0);

        for (int i = 0; i < queries.size(); ++ i) {
            int index = queries[i][0];
            int newColor = queries[i][1];
            int oldColor = colors[index];

            if (oldColor != 0) {
                if (index > 0 && colors[index-1] == oldColor) -- count; // LHS
                if (index < n-1 && colors[index+1] == oldColor) -- count; // RHS
            }

            colors[index] = newColor;

            if (newColor != 0) {
                if (index > 0 && colors[index-1] == newColor) ++ count; // LHS
                if (index < n-1 && colors[index+1] == newColor) ++ count; // RHS
            }

            result.push_back(count);
        }
        return result;
    }
};

/**
2672. Number of Adjacent Elements With the Same Color
Medium

You are given an integer n representing an array colors of length n where all elements are set to 0's meaning uncolored. 
You are also given a 2D integer array queries where queries[i] = [indexi, colori]. For the ith query:

    Set colors[indexi] to colori.
    Count the number of adjacent pairs in colors which have the same color (regardless of colori).

Return an array answer of the same length as queries where answer[i] is the answer to the ith query.
 */
