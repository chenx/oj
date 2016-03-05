// Works. Tested.
// Use the solution to SuperUglyNumber. 
// Have to use "long long " to avoid overflow.
class Solution3 {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        vector<int> primes = {2,3,5};
        int m = primes.size();
        vector<vector<long long>> v(m);
        for (int i = 0; i < m; ++ i) v[i].push_back(primes[i]);
        
        long long next;
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

// This works too. 
class Solution2 {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        vector<long long> v2;
        vector<long long> v3;
        vector<long long> v5;
        v2.push_back(2);
        v3.push_back(3);
        v5.push_back(5);
        
        long long next = 1;
        for (int i = 2; i <= n; ++ i) {
            long long n2 = v2.empty() ? INT_MAX : v2[0],
                      n3 = v3.empty() ? INT_MAX : v3[0],
                      n5 = v5.empty() ? INT_MAX : v5[0];
            
            next = min(n2, min(n3, n5));
            if (next == n2) {
                v2.erase(v2.begin());
                
                v2.push_back(next * 2);
                v3.push_back(next * 3);
                v5.push_back(next * 5);
            }
            else if (next == n3) {
                v3.erase(v3.begin());

                v3.push_back(next * 3);
                v5.push_back(next * 5);
            }
            else {
                v5.erase(v5.begin());

                v5.push_back(next * 5);
            }
        }
        
        return next;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return -1; // n >= 1.
        
        vector<long long> v2;
        vector<long long> v3;
        vector<long long> v5;
        
        v2.push_back(2);
        v3.push_back(3);
        v5.push_back(5);
        
        long long val = 1;
        for (int i = 1; i < n; ++ i) {
            val = getNext(v2, v3, v5); 
        }
        
        return val;
    }
    
    long long getNext(vector<long long> &v2, vector<long long> &v3, vector<long long> &v5) {
        long long n2 = v2.size() > 0 ? v2[0] : INT_MAX;
        long long n3 = v3.size() > 0 ? v3[0] : INT_MAX;
        long long n5 = v5.size() > 0 ? v5[0] : INT_MAX;
        
        long long next = min(n2, min(n3, n5));
        
        if (next == n2) {
            v2.push_back(next * 2);
            v3.push_back(next * 3);
            v5.push_back(next * 5);
            
            v2.erase(v2.begin());
        }
        else if (next == n3) {
            v3.push_back(next * 3);
            v5.push_back(next * 5);
            
            v3.erase(v3.begin());
        }
        else {
            v5.push_back(next * 5);
            
            v5.erase(v5.begin());
        }
        
        return next;
    }
};

/**
Ugly Number II
Difficulty: Medium

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

    - The naive approach is to call isUgly for every number until you reach the nth one. 
      Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
    - An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
    - The key is how to maintain the order of the ugly numbers. Try a similar approach of 
      merging from three sorted lists: L1, L2, and L3.
    - Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

 */
