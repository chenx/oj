// Works.
class Solution4 {
    vector<vector<int>> DP;
public:
    int superEggDrop(int k, int n) {
        DP.resize(k+1, vector<int>(n+1, -1));
        return calc(k, n);
    }

    // F(k, n) = 1 + min{h=1..n}( max(F(k-1, h-1), F(k, n-h)) )
    int calc(int k, int n) {
        if (n == 0) {
            return 0;
        }
        if (k == 1) {
            return n;
        }
        if (DP[k][n] == -1) {
            // int minVal = INT_MAX;
            // for (int h = 1; h <= n; ++ h) {
            //     int val = max(calc(k-1, h-1), calc(k, n-h));
            //     minVal = min(minVal, val);
            // }
            // Reaches min when h = L = R: calc(k-1, h-1) == calc(k, n-h)
            int L = 1, R = n;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                int t1 = calc(k-1, M-1);
                int t2 = calc(k, n-M);

                if (t1 < t2) L = M;
                else if (t1 > t2) R = M;
                else L = R = M;
            }
            DP[k][n] = 1 + max(calc(k-1, L-1), calc(k, n-L)); // L == R, so use R works too.
        }
        return DP[k][n];
    }
};

// Time out for large input.
class Solution3 {
    vector<vector<int>> DP;
public:
    int superEggDrop(int k, int n) {
        DP.resize(k+1, vector<int>(n+1, -1));
        return calc(k, n);
        // return DP[k][n];
    }

    // F(k, n) = 1 + min{h=1..n}( max(F(k-1, h-1), F(k, n-h)) )
    int calc(int k, int n) {
        if (n == 0) {
            DP[k][n] = 0;
            return 0;
        }
        if (k == 1) {
            DP[k][n] = n;
            return n;
        }
        if (DP[k][n] == -1) {
            int minVal = INT_MAX;
            for (int h = 1; h <= n; ++ h) {
                int val = max(calc(k-1, h-1), calc(k, n-h));
                minVal = min(minVal, val);
            }
            DP[k][n] = minVal + 1;
        }
        return DP[k][n];
    }
}


// Dynamic Programming with Binary Search
// Time Complexity: O(KNlogN).
// Space Complexity: O(KN).
class Solution2 {
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    map<int, int> memo;

    // F(k, n) = 1 + min{h=1..n}( max(F(k-1, h-1), F(k, n-h)) )
    int dp(int K, int N) {
        if (!memo.contains(N * 100 + K)) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int L = 1, R = N;
                while (L + 1 < R) {
                    int M = (L + R) / 2;
                    int t1 = dp(K-1, M-1);
                    int t2 = dp(K, N-M);

                    if (t1 < t2) L = M;
                    else if (t1 > t2) R = M;
                    else L = R = M;
                }
                ans = 1 + min(max(dp(K-1, L-1), dp(K, N-L)),
                              max(dp(K-1, R-1), dp(K, N-R)));
            }
            memo[N * 100 + K] = ans;
        }

        return memo[N * 100 + K];
    }
};

// From https://leetcode.com/problems/super-egg-drop/editorial/
// Time Complexity: O(KlogN)
// Space Complexity: O(1)
// F(k, n) = 1 + min{h=1..n}( max(F(k-1, h-1), F(k, n-h)) )
class Solution {
public:
    int superEggDrop(int K, int N) {
        int L = 1, R = N;
        while (L < R) {
            int M = (L + R) / 2;
            if (f(M, K, N) < N)
                L = M + 1;
            else
                R = M;
        }

        return L;
    }

    int f(int x, int K, int N) {
        int ans = 0, r = 1;
        for (int i = 1; i <= K; ++i) {
            r = r * (x-i+1) / i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
    }
};


/**
887. Super Egg Drop

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher 
than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the 
egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.
 */
