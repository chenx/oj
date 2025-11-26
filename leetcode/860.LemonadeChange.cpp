// Let n be the length of the bills array.
// Time complexity: O(n)
// Space: O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> count; // <bill, count>

        for (int bill : bills) {
            if (bill == 5) {
                ++ count[5];
            } else if (bill == 10) {
                if (count[5] == 0) return false;
                -- count[5];
                ++ count[10];
            } else { // 20
                if (count[5] == 0) return false;
                if (count[10] > 0) {
                    -- count[10];
                    -- count[5];
                } else {
                    if (count[5] < 3) return false;
                    count[5] -= 3;
                }
                // ++ count[20];
            }
        }
        return true;
    }
};


/**
860. Lemonade Change
Easy

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you 
and order one at a time (in the order specified by bills). Each customer will only buy one lemonade 
and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so 
that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you 
can provide every customer with the correct change, or false otherwise.

 

Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
 */
