// Works too.
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return -1;
        
        sort(coins.begin(), coins.end());
        vector<int> ans(amount + 1, INT_MAX);
        ans[0] = 0;
        
        for (int i = 1; i <= amount; ++ i) {
            for (int j = 0; j < coins.size(); ++ j) {
                if (i < coins[j]) break;
                else if (i == coins[j]) {
                    ans[i] = 1; 
                    break; 
                }
                else {
                    if (ans[i - coins[j]] != INT_MAX) {
                        ans[i] = min(ans[i], 1 + ans[i - coins[j]]);
                    }
                }
            }
        }
        
        if (ans[amount] == INT_MAX) ans[amount] = -1;
        return ans[amount];
    }
};

// Works too.
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return -1;
        
        sort(coins.begin(), coins.end());
        vector<int> ans(amount + 1, -1);
        ans[0] = 0;
        
        for (int i = 1; i <= amount; ++ i) {
            for (int j = 0; j < coins.size(); ++ j) {
                if (i < coins[j]) break;
                else if (i == coins[j]) {
                    ans[i] = 1; 
                    break; 
                }
                else {
                    if (ans[i - coins[j]] != -1) 
                        if (ans[i] == -1 || ans[i] > 1 + ans[i - coins[j]]) 
                            ans[i] = 1 + ans[i - coins[j]];
                }
            }
        }
        
        return ans[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        vector<int> ans(1 + amount, 0);
        sort(coins.begin(), coins.end());
        
        for (int i = 1; i <= amount; ++ i) {
            for (int j = 0; j < coins.size(); ++ j) {
                if (i < coins[j]) break;
                if (i == coins[j]) {
                    ans[i] = 1;
                    break;
                }
                else {
                    if (ans[i - coins[j]] > 0 &&  
                        (ans[i] == 0 || ans[i] > 1 + ans[i - coins[j]])) {
                        ans[i] = 1 + ans[i - coins[j]];
                    }
                }
            }
        }
        
        return ans[amount] == 0 ? -1 : ans[amount];
    }
};


/**
Coin Change
Difficulty: Medium

You are given coins of different denominations and a total amount of 
money amount. Write a function to compute the fewest number of coins 
that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin. 
 */
