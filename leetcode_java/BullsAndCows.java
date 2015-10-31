// This works. 
// From: 
// [1] https://leetcode.com/discuss/67071/clean-and-clear-java-o-n-solution
// [2] https://leetcode.com/discuss/67031/one-pass-java-solution
// Increment cows (B) when either number from secret was already seen in guest or vice versa.
public class Solution {
    public String getHint(String secret, String guess) {
        int A = 0, B = 0;
        int[] cnt = new int[10];
        for(int i=0; i<secret.length(); ++i){
            if(secret.charAt(i) == guess.charAt(i)) ++A;
            else{
                if(++cnt[secret.charAt(i)-'0'] <= 0) ++B;
                if(--cnt[guess.charAt(i)-'0']  >= 0) ++B;
            }
        }
        return A + "A" + B + "B";
    }
}

// This works too. Although not so clean.
public class Solution2 {
    public String getHint(String secret, String guess) {
        int len = secret.length();
        
        int A = 0, B = 0;
        String s = secret, g = guess;
        for (int i = 0; i < len; ++ i) {
            if (guess.charAt(i) == secret.charAt(i)) {
                ++ A;
                s = setCharAt(s, i, '_');
                g = setCharAt(g, i, '_');
            }
        }
        
        for (int i = 0; i < s.length(); ++ i) {
            char c = g.charAt(i);
            if (c == '_') continue;
            int pos = s.indexOf(c);
            if (pos != -1) {
                ++ B;
                s = setCharAt(s, pos, '_');
                g = setCharAt(g, i, '_');
            }
        }
        
        return A + "A" + B + "B";
    }
    
    private static String setCharAt(String s, int index, char c) {
        return s.substring(0, index) + c + s.substring(index + 1);
    }
    //private static String deleteCharAt(String strValue, int index) {
  	//	return strValue.substring(0, index) + strValue.substring(index + 1);
	  //}
}


/**
Bulls and Cows
Difficulty: Easy

You are playing the following Bulls and Cows game with your friend: 
You write a 4-digit secret number and ask your friend to guess it, 
each time your friend guesses a number, you give a hint, the hint 
tells your friend how many digits are in the correct positions 
(called "bulls") and how many digits are in the wrong positions 
(called "cows"), your friend will use those hints to find out the 
secret number.

For example:

Secret number:  1807
Friend's guess: 7810

Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)

According to Wikipedia: "Bulls and Cows (also known as Cows and Bulls 
or Pigs and Bulls or Bulls and Cleots) is an old code-breaking mind or 
paper and pencil game for two or more players, predating the similar 
commercially marketed board game Mastermind. The numerical version of 
the game is usually played with 4 digits, but can also be played with 
3 or any other number of digits."

Write a function to return a hint according to the secret number and 
friend's guess, use A to indicate the bulls and B to indicate the 
cows, in the above example, your function should return 1A3B.

You may assume that the secret number and your friend's guess only 
contain digits, and their lengths are always equal.
 */
