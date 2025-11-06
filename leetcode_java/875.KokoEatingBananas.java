// Same as Solution, just shorter.
class Solution2 {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = 1;
        for (int p : piles) right = Math.max(right, p);

        while (left < right) {
            int mid = left + (right - left)/2;
            int hours = 0;
            for (int p : piles) {
                hours += Math.ceil( (double) p / mid );
            }

            if (hours <= h) right = mid;
            else left = mid + 1;
        }
        return right;
    }
}

// From https://leetcode.com/problems/koko-eating-bananas/editorial/
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        // Initalize the left and right boundaries 
        int left = 1, right = 1;
        for (int pile : piles) {
            right = Math.max(right, pile);
        }

        while (left < right) {
            int middle = (left + right) / 2;

            int hourSpent = 0;  // the total hour Koko spends.
            for (int pile : piles) {
                hourSpent += Math.ceil((double) pile / middle);
            }

            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return right; // the minimum workable eating speed
    }
}

/**
875. Koko Eating Bananas
Medium

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
 */
