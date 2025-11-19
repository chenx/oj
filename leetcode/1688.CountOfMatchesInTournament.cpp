
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution2 {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while (n > 1) {
            if (n % 2 == 1) {
                count += (n-1)/2;
                n = (n-1)/2 + 1;
            } else {
                count += n/2;
                n = n/2;
            }
        }
        return count;
    }
};

// Time complexity: O(1)
// Space complexity: O(1)
class Solution1 {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};

/**
1688. Count of Matches in Tournament
Easy

You are given an integer n, the number of teams in a tournament that has strange rules:

    If the current number of teams is even, each team gets paired with another team. 
        A total of n / 2 matches are played, and n / 2 teams advance to the next round.
    If the current number of teams is odd, one team randomly advances in the tournament, 
        and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.

Return the number of matches played in the tournament until a winner is decided.
 */
