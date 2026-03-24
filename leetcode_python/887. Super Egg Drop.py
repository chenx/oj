class Solution2:
    def superEggDrop(self, k: int, n: int) -> int:
        def dp(k, n):
            if n == 0:
                return 0
            if k == 1:
                return n
            
            if DP[k][n] == -1:
                minVal = sys.maxsize
                # This also works but time out for large input.
                # for h in range(1, n+1):
                #     minVal = min(minVal, 1 + max(dp(k-1, h-1), dp(k, n-h)))

                L, R = 1, n
                while L + 1 < R:
                    M = L + (R-L)//2
                    t1 = dp(k-1, M-1)
                    t2 = dp(k, n-M)
                    if t1 < t2:
                        L = M
                    elif t1 > t2:
                        R = M
                    else:
                        L = R = M
                        # DP[k][n] = 1 + max(t1, t2) # this doesn't work.
                        break
                DP[k][n] = 1 + max(dp(k-1,L-1), dp(k, n-L))
                
            return DP[k][n]


        # DP[k, n] = min{h = 1..n}( max(DP[k-1, h-1], DP[k, n-h]) )
        DP = [[-1 for _ in range(n+1)] for _ in range(k+1)]
        return dp(k, n)


# Times out for large input.
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        def dp(k, n):
            if n == 0:
                return 0
            if k == 1:
                return n
            
            minVal = sys.maxsize
            for h in range(1, n+1):
                minVal = min(minVal, 1 + max(dp(k-1, h-1), dp(k, n-h)))
            return minVal


        # DP[k, n] = min{h = 1..n}( max(DP[k-1, h-1], DP[k, n-h]) )
        DP = [[-1 for _ in range(n+1)] for _ in range(k+1)]
        return dp(k, n)


/**
887. Super Egg Drop
Solved
Hard
Topics
conpanies iconCompanies

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher 
than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the 
egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.
 */
