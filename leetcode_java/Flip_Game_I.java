public class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        List list = new ArrayList();
        for (int i = 0, len = s.length - 1; i < len; ++ i) {
            if (s.charAt(i) == s.charAt(i+1) && s.charAt(i) == '+') {
                StringBuilder s2 = new StringBuilder(s);
                s2.setCharAt(i, '-'); 
                s2.getCharAt(i+1, '-');
                list.add(s2.toString());
            }
        }
        return list;
    }
};

// This works too. Is shorter.
public List<String> generatePossibleNextMoves(String s) {
    List list = new ArrayList();
    for (int i=-1; (i = s.indexOf("++", i+1)) >= 0; )
        list.add(s.substring(0, i) + "--" + s.substring(i+2));
    return list;
}

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
