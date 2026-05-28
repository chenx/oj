// From: https://algo.monster/liteproblems/2484
// Time complexity is O(100 × n)
// Space complexity is O(100 × n)
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPalindromes(string s) {
        int n = s.size();
      
        // prefixPairs[i][j][k] = count of pairs (j, k) in s[0...i-1]
        // where j appears before k
        int prefixPairs[n + 2][10][10];
      
        // suffixPairs[i][j][k] = count of pairs (j, k) in s[i...n-1]
        // where j appears after k
        int suffixPairs[n + 2][10][10];
      
        // Initialize arrays to 0
        memset(prefixPairs, 0, sizeof(prefixPairs));
        memset(suffixPairs, 0, sizeof(suffixPairs));
      
        // Convert string to digit array for faster access
        int digits[n];
        for (int i = 0; i < n; ++i) {
            digits[i] = s[i] - '0';
        }
      
        // Build prefix pairs: count all (j, k) pairs where j comes before k
        int digitCount[10] = {0};  // Count of each digit seen so far
        for (int i = 1; i <= n; ++i) {
            int currentDigit = digits[i - 1];
          
            // Copy previous counts
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    prefixPairs[i][j][k] = prefixPairs[i - 1][j][k];
                }
            }
          
            // Add new pairs formed with current digit as the second element
            // For each digit j seen before, (j, currentDigit) forms a new pair
            for (int j = 0; j < 10; ++j) {
                prefixPairs[i][j][currentDigit] += digitCount[j];
            }
          
            digitCount[currentDigit]++;
        }
      
        // Build suffix pairs: count all (j, k) pairs where j comes after k
        memset(digitCount, 0, sizeof(digitCount));
        for (int i = n; i > 0; --i) {
            int currentDigit = digits[i - 1];
          
            // Copy next position counts
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    suffixPairs[i][j][k] = suffixPairs[i + 1][j][k];
                }
            }
          
            // Add new pairs formed with current digit as the second element
            // For each digit j seen after, (j, currentDigit) forms a new pair
            for (int j = 0; j < 10; ++j) {
                suffixPairs[i][j][currentDigit] += digitCount[j];
            }
          
            digitCount[currentDigit]++;
        }
      
        // Count palindromes: for each position i as middle character
        // Count palindromes of form "ab[i]ba" where a and b are digits
        long long totalPalindromes = 0;
        for (int i = 1; i <= n; ++i) {
            for (int firstDigit = 0; firstDigit < 10; ++firstDigit) {
                for (int secondDigit = 0; secondDigit < 10; ++secondDigit) {
                    // Multiply prefix pairs (firstDigit, secondDigit) before position i
                    // with suffix pairs (firstDigit, secondDigit) after position i
                    // This forms palindrome: firstDigit-secondDigit-[middle]-secondDigit-firstDigit
                    totalPalindromes += 1LL * prefixPairs[i - 1][firstDigit][secondDigit] * 
                                              suffixPairs[i + 1][firstDigit][secondDigit];
                    totalPalindromes %= MOD;
                }
            }
        }
      
        return totalPalindromes;
    }
};


/**
2484. Count Palindromic Subsequences
Solved
Hard
Topics
conpanies iconCompanies
Hint

Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer 
may be very large, return it modulo 109 + 7.

Note:

    A string is palindromic if it reads the same forward and backward.
    A subsequence is a string that can be derived from another string by deleting some or no characters without 
        changing the order of the remaining characters.

 

Example 1:

Input: s = "103301"
Output: 2
Explanation: 
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
Two of them (both equal to "10301") are palindromic.

Example 2:

Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:

Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".
 */
