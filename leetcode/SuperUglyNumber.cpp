// Works too. Optimized from Solution.
class Solution2 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int m = primes.size();
        vector<vector<int>> v(m);
        for (int i = 0; i < m; ++ i) v[i].push_back(primes[i]);
        
        int next;
        for (int i = 2; i <= n; ++ i) {
            next = INT_MAX;
            int minj = 0;
            for (int j = 0; j < m; ++ j) {
                if (next > v[j][0]) {
                    next = v[j][0];
                    minj = j;
                }
            }
            
            v[minj].erase(v[minj].begin());
            for (int k = minj; k < m; ++ k) {
                v[k].push_back(next * primes[k]);
            }
        }
        
        return next;
    }
};

// This works. Modified from the solution of UglyNumbers_II.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        int m = primes.size();
        vector<vector<long long>> v(m);
        
        for (int i = 0; i < m; ++ i) {
            v[i].push_back(primes[i]);
        }
        
        long long next;
        for (int i = 2; i <= n; ++ i) {
            next = INT_MAX;
            for (int j = 0; j < m; ++ j) {
                next = min(next, v[j][0]);
            }
            
            for (int j = 0; j < m; ++ j) {
                if (next == v[j][0]) {
                    v[j].erase(v[j].begin());
                    
                    for (int k = j; k < m; ++ k) {
                        v[k].push_back(next * primes[k]);
                    }
                    
                    break;
                }
            }
        }
        
        return next;        
    }
};

/**
Super Ugly Number
Difficulty: Medium

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors 
are in the given prime list primes of size k. For example, 
[1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of 
the first 12 super ugly numbers given primes = [2, 7, 13, 19] 
of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000. 
 */
