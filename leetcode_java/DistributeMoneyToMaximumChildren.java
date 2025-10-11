// From https://algo.monster/liteproblems/2591
class Solution {
    public int distMoney(int money, int children) {
        // Case 1: Not enough money to give at least 1 dollar to each child
        if (money < children) {
            return -1;
        }
      
        // Case 2: Too much money - after giving 8 dollars to each child, 
        // we still have excess that must go to someone (violating the exact 8 dollar rule)
        if (money > 8 * children) {
            return children - 1;
        }
      
        // Case 3: Special edge case - would result in one child getting exactly 4 dollars
        // (which is forbidden), so we need to adjust two children's amounts
        if (money == 8 * children - 4) {
            return children - 2;
        }
      
        // Case 4: General case - calculate maximum number of children who can get exactly 8 dollars
        // Constraint: money - 8x >= children - x (remaining money for remaining children)
        // Solving: x <= (money - children) / 7
        return (money - children) / 7;
    }
}

/**
2591. Distribute Money to Maximum Children
Easy

You are given an integer money denoting the amount of money (in dollars) that you have and another integer 
children denoting the number of children that you must distribute the money to.

You have to distribute the money according to the following rules:

    All money must be distributed.
    Everyone must receive at least 1 dollar.
    Nobody receives 4 dollars.

Return the maximum number of children who may receive exactly 8 dollars if you distribute the money 
according to the aforementioned rules. If there is no way to distribute the money, return -1.
 */
