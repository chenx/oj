// Time complexity: O(logmax(num1​,num2​)).
// Space: O(1)
class Solution2 {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while (num1 != 0 && num2 != 0) {
            count += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return count;
    }
};


// This can be much slower than Solution 2.
// E.g., num1 = 1000, num2 = 1.
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 > num2) num1 -= num2;
            else num2 -= num1;
            
            ++ count;
        }
        return count;
    }
};


/**
2169. Count Operations to Obtain Zero
Easy

You are given two non-negative integers num1 and num2.

In one operation, if num1 >= num2, you must subtract num2 from num1, otherwise subtract num1 from num2.

    For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus obtaining num1 = 1 and num2 = 4. 
    However, if num1 = 4 and num2 = 5, after one operation, num1 = 4 and num2 = 1.

Return the number of operations required to make either num1 = 0 or num2 = 0.
 */
