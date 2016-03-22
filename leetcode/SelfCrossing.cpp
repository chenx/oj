// Works. Tested. 
// Modified from Solution3.
/*
 case 1: x[i-1] does not change.
            x[i-2]
        ┌------------┐
        |    ┌---┐   | x[i-3] 
        |  | |   |   |
x[i-1]  |  | └───────-
        |  |   x[i-4]
        |  |           
        └───
        x[i]

 case 2: x[i-1] = x[i-1] - x[i-3]
            x[i-2]
        ┌------------┐
        |    ┌---┐   | x[i-3] 
        |    |   |   |
x[i-1]  |    └───────-
        |    _________
        |             |
        └──────────────
              x[i]
 */
class Solution4 {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n <= 3) return false;
        bool grow; // incremental spiral.

        for (int i = 3, grow = (x[2] > x[0]); i < n; ++ i) {
            // shrink case, cross happens on x[i].
            if (! grow && x[i] >= x[i-2]) return true; 
            
            if (grow && x[i] <= x[i-2]) { // if grow changes to shrink
                grow = false;
                // update x[i-1]. See figures above for cases 1 and 2.
                x[i-1] = ((x[i] + (i >= 4 ? x[i-4] : 0)) < x[i-2]) ? 
                         x[i-1] : (x[i-1] - x[i-3]); 
            }
        }
        return false;
    }
};


// Works. Tested.
// From: https://leetcode.com/discuss/88196/re-post-2-o-n-c-0ms-solutions
class Solution3 {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = x.size(), i;
        if(len<=3) return false;
        bool grow_spiral;

        for(i=3, grow_spiral = x[2]>x[0]; i<len;++i) {
            //if it is a "shrink" case before x[i] and cross happens
            if(!grow_spiral && x[i]>=x[i-2]) return true;
            
            // if it is a grow case, and x[i] changes it to shrink
            if(grow_spiral && x[i]<=x[i-2]) { 
                    grow_spiral = false;
                    x[i-1] = x[i] + (i>=4?x[i-4]:0)<x[i-2]? x[i-1]:x[i-1]-x[i-3];// update boundary
            }
        }
        return false;
    }
};


// Works. Tested.
// From: https://leetcode.com/discuss/88196/re-post-2-o-n-c-0ms-solutions
class Solution2 {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = x.size(),i;
        for(i=3; i<len;++i)
        {
            if(x[i]>=x[i-2] && x[i-1] <= x[i-3]) return true; // case 1, the consecutive four lines form a cross
            if(i>3 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2]) return true; // case 2, the consecutive five lines form a cross
            if(i>4 && x[i-2]>=x[i-4] && x[i-4]+x[i]>=x[i-2] && x[i-1]<=x[i-3] && x[i-5] + x[i-1]>=x[i-3]) return true;// case 3, the consecutive six lines form a cross
        }
        return false;
    }
};


// Works. Tested. 
// From: https://leetcode.com/discuss/88603/5-lines-c-solution-with-comments
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int i, xSize = x.size();
        
        // Expand from inner space to outer space at first
        for (i = 2; i < xSize && x[i] > x[i-2]; i++);
        
        // Judge if the state transfer is illegal 
        if ((++i < xSize) && ((i > 4 && x[i-1]+x[i-5]>=x[i-3]) || 
            (i==4 && x[i-1]==x[i-3])) && x[i]+x[i-4] >= x[i-2]) return true;
        
        // Shrink from outer space to inner space
        for (; i < xSize && x[i] < x[i-2]; i++);
        
        return (i < xSize);
    }
};


/**
Self Crossing
Difficulty: Medium

You are given an array x of n positive numbers. You start at point (0,0) 
and moves x[0] metres to the north, then x[1] metres to the west, x[2] 
metres to the south, x[3] metres to the east and so on. In other words, 
after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your 
path crosses itself, or not.

Example 1:

Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)

Example 2:

Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)

Example 3:

Given x = [1, 1, 1, 1],
┌───┐
│   │
└───┼>

Return true (self crossing)

 */
