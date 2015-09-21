/**
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * For example: 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. 
 */
public class Solution {

    // Clever implementation using math interpretation. This works too. O(1).
    public int addDigits2(int num) {
        if (num == 0) return 0;
        int x = num % 9;
        return x == 0 ? 9 : x;
    }
    
    // Naive implementation. This works.
    // This is more expensive than log(n). Each inner while loop is log(num.length). 
    // log(n) + log(log(n)) + log(log(log(n))) + ...
    public int addDigits(int num) {
        while (num > 9) {
            int x = num;
            num = 0;
            while (x > 0) {
                num += x % 10;
                x /= 10;
            }
        }
        return num;
    }
}
