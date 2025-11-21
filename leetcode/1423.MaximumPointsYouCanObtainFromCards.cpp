// From: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/editorial/
// Dynamic Programming
// Time complexity: O(k)
// Space complexity: O(k).
class Solution2 {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int frontSetOfCards[k + 1];
        int rearSetOfCards[k + 1];

        frontSetOfCards[0] = rearSetOfCards[0] = 0;  //Intialize 0th index in both the arrays

        for (int i = 0; i < k; i++) {
            frontSetOfCards[i + 1] = cardPoints[i] + frontSetOfCards[i];
            rearSetOfCards[i + 1] = cardPoints[n - i - 1] + rearSetOfCards[i];
        }

        int maxScore = 0;
        // Each i represents the number of cards we take from the front.
        for (int i = 0; i <= k; i++) {
            int currentScore = frontSetOfCards[i] + rearSetOfCards[k - i];
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};


// From: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/editorial/
// Sliding Window
// Equivalent to get min sum of a subarray (length is n - k) in the middle.
//
// Time complexity: O(n). In the problem, we are iterating over the array of cards twice. So the time complexity will be O(2⋅n) = O(n).
// Space complexity: O(1) since no extra space is required.
//
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int startingIndex = 0, presentSubarrayScore = 0;
        int n = cardPoints.size();
        int requiredSubarrayLength = n - k;

        int totalScore = 0; // Total score obtained on selecting all the cards.
        for (int i : cardPoints) {
            totalScore += i;
        }
        
        int minSubarrayScore = totalScore;

        if (k == n) {
            return totalScore;
        }

        for (int i = 0; i < n; i++) {
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            // If a valid subarray (having size cardsPoints.size() - k) is possible.
            if (presentSubarrayLength == requiredSubarrayLength) {
                minSubarrayScore = min(minSubarrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex ++];
            }
        }
        return totalScore - minSubarrayScore;
    }
};


/**
1423. Maximum Points You Can Obtain from Cards
Medium

There are several cards arranged in a row, and each card has an associated number of points. 
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first 
will maximize your total score. The optimal strategy is to take the three cards on the right, giving a 
final score of 1 + 6 + 5 = 12.
 */
