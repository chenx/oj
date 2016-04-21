// Works too. Use a map, instead of array.
class Solution4 {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0, n = secret.size();
        unordered_map<char, int> ct;
        
        for (int i = 0; i < n; ++ i) {
            if (secret[i] == guess[i]) ++ A;
            else ct[secret[i]] ++;
        }
        
        for (int i = 0; i < n; ++ i) {
            if (ct[guess[i]] > 0 && guess[i] != secret[i]) {
                ++ B;
                ct[guess[i]] --;
            }
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};

// Works. Much easier to understand. From CCI 5th Ed.
class Solution3 {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0, n = secret.length();
        int ct[10] = {0};
        
        for (int i = 0; i < n; ++ i) { // get bulls
            if (secret[i] == guess[i]) ++ A;
            else ct[secret[i] - '0'] ++;
        }
        
        for (int i = 0; i < n; ++ i) { // get cows
            if (ct[guess[i] - '0'] > 0 && guess[i] != secret[i]) {
                ++ B;
                ct[guess[i] - '0'] --;
            }
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};

// This works. More clear on what happens.
class Solution2 {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        vector<int> cnt(10);
        for (int i = 0; i < secret.length(); ++ i) {
            if (secret[i] == guess[i]) ++ A;
            else {
                int s = secret[i] - '0';
                int g = guess[i]  - '0';
                ++ cnt[s];
                -- cnt[g];
                if (cnt[s] <= 0) ++ B;
                if (cnt[g] >= 0) ++ B;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};

// This works.
class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        //int cnt[10];
        //memset(cnt, 0, 10 * sizeof(int));
        vector<int> cnt(10);
        for (int i = 0; i < secret.length(); ++ i) {
            if (secret[i] == guess[i]) ++ A;
            else {
                if (++cnt[secret[i]-'0'] <= 0) ++ B;
                if (--cnt[guess[i]-'0']  >= 0) ++ B;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};


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

