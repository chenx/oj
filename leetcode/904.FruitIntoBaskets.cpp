// See https://leetcode.com/problems/fruit-into-baskets/editorial/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> basket; // <fruit_type, count>
        int maxPicked = 0;

        for (int i = 0, left = 0; i < fruits.size(); ++ i) {
            ++ basket[fruits[i]];

            while (basket.size() > 2) {
                -- basket[fruits[left]];
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                ++ left;
            }

            maxPicked = max(maxPicked, i - left + 1);
        }
        return maxPicked;
    }
};


/**
904. Fruit Into Baskets
Medium

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are 
represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

    You only have two baskets, and each basket can only hold a single type of fruit. There is no limit 
        on the amount of fruit each basket can hold.
    Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the 
        start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.
 */
