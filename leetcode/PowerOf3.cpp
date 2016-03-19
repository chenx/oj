// All 3 methods work. 
// Method 2 needs no recursion/loop. Method 3 can be rewritten to be so.
class Solution {
public:
    bool isPowerOfThree3(int n) {
        int power_list[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 
            177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 
            387420489, 1162261467};
        for (int i = 0, len = sizeof(power_list) / sizeof(int); i < len; ++ i) {
            if (n == power_list[i]) return true;
        }
        return false;
    }
    
    bool isPowerOfThree2(int n) {
        // 1162261467=3^19. 3^20 is bigger than int.
        return n > 0 && 1162261467 % n == 0;
    }
    
    bool isPowerOfThree(int n) {
        if (n == 0) return false; // or use n <= 0
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};


/*
Power of Three

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion? 
 */
