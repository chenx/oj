// // Top-down DP
// From: https://leetcode.com/problems/filling-bookcase-shelves/editorial/
// Let N be the length of array books, and W be the shelfWidth.
// Time Complexity: O(N⋅W)
// Space: O(N⋅W)
class Solution2 {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> memo(books.size(), vector<int>(shelfWidth + 1, 0));
        return dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0);
    }

private:
    int dpHelper(vector<vector<int>>& books, int shelfWidth,
                 vector<vector<int>>& memo, int i, int remainingShelfWidth,
                 int maxHeight) {
        // Return height of current shelf
        if (i == books.size()) return maxHeight;
        // Return answer if already computed
        if (memo[i][remainingShelfWidth] != 0) {
            return memo[i][remainingShelfWidth];
        } else {
            vector<int> currentBook = books[i];
            // Calculate the height of the bookcase if we put the
            // current book on the new shelf
            int option1Height =
                maxHeight + dpHelper(books, shelfWidth, memo, i + 1,
                                     shelfWidth - currentBook[0],
                                     currentBook[1]);
            int option2Height = INT_MAX;
            if (remainingShelfWidth >= currentBook[0]) {
                int maxHeightUpdated = max(maxHeight, currentBook[1]);
                option2Height = dpHelper(books, shelfWidth, memo, i + 1,
                                         remainingShelfWidth - currentBook[0],
                                         maxHeightUpdated);
            }
            // Store the smaller result in cache
            memo[i][remainingShelfWidth] = min(option1Height, option2Height);
            return memo[i][remainingShelfWidth];
        }
    }
};


// Bottom-up DP
// From: https://leetcode.com/problems/filling-bookcase-shelves/editorial/
// Let N be the length of array books, and W be the shelfWidth.
// Time Complexity: O(N⋅W)
// Space: O(N)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp[i] will store the minimum height of the bookcase containing all
        // books up to and excluding i
        vector<int> dp(books.size() + 1, 0);

        // Base cases
        dp[0] = 0;
        dp[1] = books[0][1];

        for (int i = 1; i <= books.size(); ++i) {
            // new shelf built to hold current book
            int remainingShelfWidth = shelfWidth - books[i - 1][0];
            int maxHeight = books[i - 1][1];
            dp[i] = dp[i - 1] + maxHeight;

            int j = i - 1;
            // calculate the height when previous books are added onto a new
            // shelf
            while (j > 0 && remainingShelfWidth - books[j - 1][0] >= 0) {
                remainingShelfWidth -= books[j - 1][0];
                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
                j--;
            }
        }

        return dp[books.size()];
    }
};


/**
1105. Filling Bookcase Shelves
Medium

You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. 
You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, 
then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum 
height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

    For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the 
third book on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.
 */
