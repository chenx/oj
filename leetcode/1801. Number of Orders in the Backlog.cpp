#define logSize(buyMaxHeap, sellMinHeap) \
    cout << "buy log size: " << buyMaxHeap.size() << "; "; \
    cout << "sell log size: " << sellMinHeap.size() << endl;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>, vector<vector<int>>> buyMaxHeap; // buy log
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sellMinHeap; // sell log
        
        for (vector<int> order: orders) {
            int price = order[0], amount = order[1], orderType = order[2];
            if (orderType == 0) { // buy order
                //cout << "buy: " << amount << " orders at $" << price << endl;
                while (! sellMinHeap.empty() && amount > 0) {
                    if (sellMinHeap.top()[0] <= price) {
                        if (sellMinHeap.top()[1] <= amount) {
                            amount -= sellMinHeap.top()[1];
                            sellMinHeap.pop();
                        } else {
                            int sellPrice = sellMinHeap.top()[0];
                            int sellAmount = sellMinHeap.top()[1] - amount;
                            sellMinHeap.pop();
                            if (sellAmount > 0) {
                                sellMinHeap.push({sellPrice, sellAmount});
                            }
                            amount = 0;
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if (amount > 0) {
                    buyMaxHeap.push({price, amount});
                }
            } else { // sell order 
                //cout << "sell: " << amount << " orders at $" << price << endl;
                while (! buyMaxHeap.empty() && amount > 0) {
                    if (buyMaxHeap.top()[0] >= price) {
                        if (buyMaxHeap.top()[1] <= amount) {
                            amount -= buyMaxHeap.top()[1];
                            buyMaxHeap.pop();
                        } else {
                            int buyPrice = buyMaxHeap.top()[0];
                            int buyAmount = buyMaxHeap.top()[1] - amount;
                            buyMaxHeap.pop();
                            if (buyAmount > 0) {
                                buyMaxHeap.push({buyPrice, buyAmount});
                            }
                            amount = 0;
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if (amount > 0) {
                    sellMinHeap.push({price, amount});
                }
            }
            //logSize(buyMaxHeap, sellMinHeap);
        }
        //logSize(buyMaxHeap, sellMinHeap);

        long long result = 0;
        while (! buyMaxHeap.empty()) {
            result += buyMaxHeap.top()[1];
            buyMaxHeap.pop();
        }
        while (! sellMinHeap.empty()) {
            result += sellMinHeap.top()[1];
            sellMinHeap.pop();
        }
        //cout << result << endl;
        return result % 1000000007;
    }
};


/**
1801. Number of Orders in the Backlog
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given a 2D integer array orders, where each orders[i] = [pricei, amounti, orderTypei] denotes that amounti orders have been placed of type orderTypei at the price pricei. The orderTypei is:

    0 if it is a batch of buy orders, or
    1 if it is a batch of sell orders.

Note that orders[i] represents a batch of amounti independent orders with the same price and order type. All orders represented by orders[i] will be placed before all orders represented by orders[i+1] for all valid i.

There is a backlog that consists of orders that have not been executed. The backlog is initially empty. When an order is placed, the following happens:

    If the order is a buy order, you look at the sell order with the smallest price in the backlog. If that sell order's price is smaller than or equal to the current buy order's price, they will match and be executed, and that sell order will be removed from the backlog. Else, the buy order is added to the backlog.
    Vice versa, if the order is a sell order, you look at the buy order with the largest price in the backlog. If that buy order's price is larger than or equal to the current sell order's price, they will match and be executed, and that buy order will be removed from the backlog. Else, the sell order is added to the backlog.

Return the total amount of orders in the backlog after placing all the orders from the input. Since this number can be large, return it modulo 109 + 7.

 

Example 1:

Input: orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
Output: 6
 */
