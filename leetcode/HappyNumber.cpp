class Solution {
public:
    bool isHappy(int n) { // assume n > 0.
        if (n <= 0) return false;
        
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) return false;
            
            s.insert(n);
            n = getSum(n);
        }
        
        return true;
    }
    
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};

/**
Happy Number
Difficulty: Easy

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of 
the squares of its digits, and repeat the process until the number 
equals 1 (where it will stay), or it loops endlessly in a cycle which 
does not include 1. Those numbers for which this process ends in 1 
are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

 */
