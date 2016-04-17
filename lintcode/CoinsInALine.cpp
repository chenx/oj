// O(1) time and space. Works.
// If n = 3m, first player will always lose.
// If n = 3m + 1 or 3m - 1, first player just picks 1 or 2, and left 3m, 
// so second player loses.
class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        return n % 3 != 0;
    }
};


/**
Coins in a Line

There are n coins in a line. Two players take turns to take one or two coins 
from right side until there are no more coins left. The player who take the 
last coin wins.

Could you please decide the first play will win or lose?
Have you met this question in a real interview?
Example

n = 1, return true.

n = 2, return true.

n = 3, return false.

n = 4, return true.

n = 5, return true.
Challenge

O(n) time and O(1) memory

 */
