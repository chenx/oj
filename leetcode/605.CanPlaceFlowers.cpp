class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); ++ i) {
            if (flowerbed[i] == 0) {
                bool leftOk = (i == 0) || flowerbed[i-1] == 0;
                bool rightOk = (i == flowerbed.size() - 1) || flowerbed[i+1] == 0;

                if (leftOk && rightOk) {
                    ++ count;
                    flowerbed[i] = 1;
                    if (count >= n) break;
                }
            }
        }
        return count >= n;
    }
};

/**
605. Can Place Flowers
Easy

You have a long flowerbed in which some of the plots are planted, and some are not. 
However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
and an integer n, return true if n new flowers can be planted in the flowerbed without violating 
the no-adjacent-flowers rule and false otherwise.
 */
