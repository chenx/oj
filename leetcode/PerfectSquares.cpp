// Works too.
class Solution {
public:
    int numSquares3(int n) {
        if (n <= 0) return 0;
        vector<int> cand;
        for (int i = 1; i * i <= n; ++ i) {
            cand.push_back(i * i);
        }
        
        vector<int> v(1+n, 0);
        for (int i = 1; i <= n; ++ i) {
            for (int j = 0; j < cand.size(); ++ j) {
                if (i < cand[j]) break;
                else if (i == cand[j]) {
                    v[i] = 1;
                    break;
                }
                else {
                    if (v[i - cand[j]] > 0) {
                        if (v[i] == 0 || v[i] > 1 + v[i - cand[j]]) {
                            v[i] = 1 + v[i - cand[j]];
                        }
                    }
                }
            }
        }
        
        return v[n];
    }
};

// This works too. But not as good as Solution below.
class Solution2 {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        vector<int> coins;
        for (int i = 1; i * i <= n; ++ i) {
            coins.push_back(i * i);
        }
        
        vector<int> ans(n+1); // default to 0.
        ans[1] = 1;
        for (int i = 2; i <= n; ++ i) {
            for (int j = 0, lenj = coins.size(); j < lenj; ++ j) {
                if (i == coins[j]) {
                    ans[i] = 1;
                    break;
                }
                else if (i > coins[j]) {
                    if (ans[i - coins[j]] > 0) {
                        if (ans[i] == 0) ans[i] = 1 + ans[i - coins[j]];
                        else ans[i] = min(ans[i], 1 + ans[i - coins[j]]);
                    }
                }
            }
        }
        
        return ans[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        vector<int> coins;
        for (int i = 1; i * i <= n; ++ i) {
            coins.push_back(i * i);
        }
        
        vector<int> ans(n+1); // default to 0.
        for (int i = 1; i <= n; ++ i) {
            ans[i] = i;
            for (int j = 0, lenj = coins.size(); j < lenj; ++ j) {
                if (i == coins[j]) {
                    ans[i] = 1;
                    break;
                }
                else if (i > coins[j]) {
                    if (ans[i - coins[j]] > 0) {
                        ans[i] = min(ans[i], 1 + ans[i - coins[j]]);
                    }
                }
            }
        }
        
        return ans[n];
    }
};

/**
Perfect Squares
Difficulty: Medium

Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
given n = 13, return 2 because 13 = 4 + 9. 
 */
