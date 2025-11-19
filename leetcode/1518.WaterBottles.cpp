class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            numBottles = newBottles + numBottles % numExchange;
            total += newBottles;
        }
        return total;
    }
};

/**
1518. Water Bottles
Easy

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water 
bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
 */
