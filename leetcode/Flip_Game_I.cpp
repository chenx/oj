// See: https://leetcode.com/discuss/oj/flip-game
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 0, len = s.length() - 1; i < len; ++ i) {
            if (s[i] == s[i+1] && s[i] == '+') {
                string s2 = s;
                s2[i] = s2[i+1] = '-';
                ans.push_back(s2);
            }
        }
        return ans;
    }
};


/**
Flip Game I
Difficulty: Easy

You are playing the following Flip Game with your friend: 
given a string that contains only two characters: + or - , 
you and your friend take turns to flip two consecutive "++" 
into "--". If one of you fail to do so (no consecutive + exist), 
then he will lose the game.

Write a function to compute all the possible states of the string after one move.

For example, given s = "++++", after one move, it may become one of the following states:

"--++", "+--+", "++--"

 */
