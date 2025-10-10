// From https://leetcode.com/problems/super-egg-drop/editorial/
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
