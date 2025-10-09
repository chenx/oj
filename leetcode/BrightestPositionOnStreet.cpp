// Works.
// From https://algo.monster/liteproblems/2021
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> brightnessChange;  // <pos, brightness_change>
        for (auto light : lights) {
            int left = light[0] - light[1];
            int right = light[0] + light[1];
            ++ brightnessChange[left];
            -- brightnessChange[right + 1];
        }

        int brightness = 0, maxVal = 0, maxPos = 0;
        for (auto [pos, change] : brightnessChange) {
            brightness += change;
            if (maxVal < brightness) {
                maxVal = brightness;
                maxPos = pos;
            }
        }
        return maxPos;
    }
};

/**
2021. Brightest Position on Street

A perfectly straight street is represented by a number line. The street has street lamp(s) on it and is 
represented by a 2D integer array lights. Each lights[i] = [positioni, rangei] indicates that there is 
a street lamp at position positioni that lights up the area from [positioni - rangei, positioni + rangei] (inclusive).

The brightness of a position p is defined as the number of street lamp that light up the position p.

Given lights, return the brightest position on the street. If there are multiple brightest positions, 
return the smallest one.
 */
