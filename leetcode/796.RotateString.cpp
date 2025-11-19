// See https://leetcode.com/problems/rotate-string/editorial/
class Solution {
public:
    bool rotateString(string s, string goal) {
        // string goal2 = goal + goal;
        // return s.length() == goal.length() && goal2.find(s) != string::npos; // this works too.
        string s2 = s + s;
        return s.length() == goal.length() && s2.find(goal) != string::npos;
    }
};


/**
796. Rotate String
Easy

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

    For example, if s = "abcde", then it will be "bcdea" after one shift.
 */
