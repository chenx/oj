public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        
        int v = x, y0, y = 0;
        while (v > 0) {
            y0 = y;
            y = y * 10 + v % 10;
            if (y / 10 != y0) return false;
            v /= 10;
        }
        
        return x == y;
    }
}

/**
Palindrome Number
Difficulty: Easy

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, 
note the restriction of using extra space.

You could also try reversing an integer. However, if you 
have solved the problem "Reverse Integer", you know that 
the reversed integer might overflow. How would you handle 
such case?

There is a more generic way of solving this problem.

 */
