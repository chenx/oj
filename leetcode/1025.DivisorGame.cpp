// From: https://algo.monster/liteproblems/1025

class Solution {
public:
    bool divisorGame(int n) {
        // Alice wins if the starting number is even
        return n % 2 == 0;
    }
};

    /**
     * Determines if Alice wins the divisor game.
     * 
     * Game rules:
     * - Players take turns, Alice goes first
     * - On each turn, player chooses x where 1 <= x < n and n % x == 0
     * - Replace n with n - x
     * - Player who cannot make a move loses
     * 
     * Mathematical insight:
     * - If n is even, Alice can always choose x = 1, making n odd for Bob
     * - If n is odd, Alice must choose an odd x (since odd numbers only have odd divisors),
     *   making n - x even for Bob
     * - Therefore, the player with an even number always wins
     * - Since Alice starts first, she wins if and only if n is even
     * 
     * @param n The starting number for the game
     * @return true if Alice wins, false otherwise
     */

/**
1025. Divisor Game
Easy

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

    Choosing any integer x with 0 < x < n and n % x == 0.
    Replacing the number n on the chalkboard with n - x.

Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.
 */
