// from: https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
// also see: https://leetcode.com/discuss/oj/flip-game-ii
public boolean canWin(String s) {
    s = s.replace('-', ' ');
    int G = 0;
    List<Integer> g = new ArrayList<>();
    for (String t : s.split("[ ]+")) {
        int p = t.length();
        if (p == 0) continue;
        while (g.size() <= p) {
            char[] x = t.toCharArray();
            int i = 0, j = g.size() - 2;
            while (i <= j)
                x[g.get(i++) ^ g.get(j--)] = '-';
            g.add(new String(x).indexOf('+'));
        }
        G ^= g.get(p);
    }
    return G != 0;
}

 /**
 Flip Game II
Difficulty: Easy

Given a string that contains only + or - characters, 
each player takes turn to flip two consecutive "++" to "--".

The player who could not make a move loses.

Write a function that determines if the starting player can guarantee a win.

An example of a valid input string is "---++----++-+"
  */
