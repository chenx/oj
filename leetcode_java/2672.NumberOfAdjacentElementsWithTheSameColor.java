// From: https://algo.monster/liteproblems/2672
class Solution {
    public int[] colorTheArray(int n, int[][] queries) {
        int queryCount = queries.length;
        int[] colors = new int[n]; // Array to store colors, initially all 0 (uncolored)
        int[] result = new int[queryCount]; // Result array to store count after each query
        int adjacentPairs = 0; // Running count of adjacent elements with same color
      
        for (int queryIndex = 0; queryIndex < queryCount; queryIndex++) {
            int position = queries[queryIndex][0];
            int newColor = queries[queryIndex][1];
          
            // Before changing the color, remove existing adjacent pairs involving this position
          
            // Check if current position and left neighbor form a pair (both colored and same color)
            if (position > 0 && colors[position] > 0 && colors[position - 1] == colors[position]) {
                adjacentPairs--;
            }
          
            // Check if current position and right neighbor form a pair (both colored and same color)
            if (position < n - 1 && colors[position] > 0 && colors[position + 1] == colors[position]) {
                adjacentPairs--;
            }
         
            // After changing the color, add new adjacent pairs involving this position
          
            // Check if new color will form a pair with left neighbor
            if (position > 0 && colors[position - 1] == newColor) {
                adjacentPairs++;
            }
          
            // Check if new color will form a pair with right neighbor
            if (position < n - 1 && colors[position + 1] == newColor) {
                adjacentPairs++;
            }
          
            // Store the current count of adjacent pairs
            result[queryIndex] = adjacentPairs;
          
            // Apply the new color to the position
            colors[position] = newColor;
        }
      
        return result;
    }
}

/**
2672. Number of Adjacent Elements With the Same Color
Medium

You are given an integer n representing an array colors of length n where all elements are set to 0's meaning uncolored. 
You are also given a 2D integer array queries where queries[i] = [indexi, colori]. For the ith query:

    Set colors[indexi] to colori.
    Count the number of adjacent pairs in colors which have the same color (regardless of colori).

Return an array answer of the same length as queries where answer[i] is the answer to the ith query.
 */
