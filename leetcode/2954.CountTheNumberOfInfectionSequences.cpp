// See: https://algo.monster/liteproblems/2954

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
int factorial[MAX_N + 1];

// Initialize factorial array at compile time
auto initialize = [] {
    factorial[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    }
    return 0;
}();

// Fast exponentiation with modulo
int modularPower(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int numSick = sick.size();
      
        // Calculate gaps between sick positions
        vector<int> gaps(numSick + 1);
      
        // Gap before first sick position
        gaps[0] = sick[0];
      
        // Gap after last sick position
        gaps[numSick] = n - sick[numSick - 1] - 1;
      
        // Gaps between consecutive sick positions
        for (int i = 1; i < numSick; i++) {
            gaps[i] = sick[i] - sick[i - 1] - 1;
        }
      
        // Total number of healthy positions
        int totalHealthy = accumulate(gaps.begin(), gaps.end(), 0);
      
        // Start with factorial of total healthy positions (all permutations)
        long long answer = factorial[totalHealthy];
      
        // Divide by factorial of each gap size (multinomial coefficient)
        for (int gapSize : gaps) {
            if (gapSize > 0) {
                // Multiply by modular inverse of factorial[gapSize]
                answer = (answer * modularPower(factorial[gapSize], MOD - 2)) % MOD;
            }
        }
      
        // For internal gaps, multiply by 2^(gapSize-1) for ordering choices
        for (int i = 1; i < gaps.size() - 1; ++i) {
            if (gaps[i] > 1) {
                answer = (answer * modularPower(2, gaps[i] - 1)) % MOD;
            }
        }
      
        return answer;
    }
};

/**
Hint 1
Consider infected children as 0 and non-infected as 1, then divide the array into segments with the same value.

Hint 2
For each segment of non-infected children whose indices are [i, j] and indices (i - 1) and (j + 1), if they exist, 
are already infected. Then if i == 0 or j == n - 1, each second there is only one kid that can be infected 
(which is at the other endpoint).

Hint 3
If i > 0 and j < n - 1, we have two choices per second since the children at the two endpoints can both be 
the infect candidates. So there are 2j - i orders to infect all children in the segment.

Hint 4
Each second we can select a segment and select one endpoint from it.

Hint 5
The answer is: S! / (len[1]! * len[2]! * ... * len[m]! * lenstart! * lenend!) * 2k where len[1], len[2], ..., len[m] 
are the lengths of each segment of non-infected children that have an infected child at both endpoints, lenstart 
and lenend denote the number of non-infected children with infected child at one endpoint, S is the total length 
of all segments of non-infected children, and k = (len[1] - 1) + (len[2] - 1) + ... + (len[m] - 1).
 */

/**
2954. Count the Number of Infection Sequences
Hard

You are given an integer n and an array sick sorted in increasing order, representing positions of infected people in a line of n people.

At each step, one uninfected person adjacent to an infected person gets infected. This process continues until everyone is infected.

An infection sequence is the order in which uninfected people become infected, excluding those initially infected.

Return the number of different infection sequences possible, modulo 109+7.

 

Example 1:

Input: n = 5, sick = [0,4]

Output: 4

Explanation:

There is a total of 6 different sequences overall.

    Valid infection sequences are [1,2,3], [1,3,2], [3,2,1] and [3,1,2].
    [2,3,1] and [2,1,3] are not valid infection sequences because the person at index 2 cannot be infected at the first step.
 */
