class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (auto& op : operations) {
            if (op == "+") {
                if (scores.size() >= 2) {
                    int score = scores.top();
                    scores.pop();
                    int newScore = score + scores.top();
                    scores.push(score);
                    scores.push(newScore);
                }
            } else if (op == "D") {
                scores.push( scores.top() * 2);
            } else if (op == "C") {
                scores.pop();
            } else { // should be a number. Could be negative like "-2".
                scores.push(stoi(op));
            }
        }

        int sum = 0;
        while (! scores.empty()) {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};


/**
682. Baseball Game
Easy

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, 
you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must 
apply to the record and is one of the following:

    An integer x.
        Record a new score of x.
    '+'.
        Record a new score that is the sum of the previous two scores.
    'D'.
        Record a new score that is the double of the previous score.
    'C'.
        Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 
32-bit integer and that all operations are valid.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27

Example 3:

Input: ops = ["1","C"]
Output: 0
 */
