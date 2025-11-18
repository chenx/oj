// Same as Solution.
class Solution2 {
public:
    vector<double> A(double a, double b) {
        vector<double> v = {a + b, a - b, b - a, a * b};
        if (abs(a) > 0.00001) v.push_back(b/a);
        if (abs(b) > 0.00001) v.push_back(a/b);
        return v;
    }

    bool calc(vector<double>& input) {
        int n = input.size();
        if (n == 1) {
            return abs(input[0] - 24) < 0.00001;
        }

        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                vector<double> newInput;
                for (int k = 0; k < n; ++ k) {
                    if (k != i && k != j) newInput.push_back(input[k]);
                }
        
                vector<double> tmp = A(input[i], input[j]);
                for (double t : tmp) {
                    newInput.push_back(t);
                    if (calc(newInput)) return true;
                    newInput.pop_back();
                }

            }
        }
        return false;        
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> input(cards.begin(), cards.end());
        return calc(input);
    }
};

class Solution {
public:
    // All possible operations we can perform on two numbers.
    vector<double> generatePossibleResults(double& a, double& b) {
        vector<double> res = { a + b, a - b, b - a, a * b };
        if (a) {
            res.push_back(b / a);
        } 
        if (b) {
            res.push_back(a / b);
        }
        return res;
    }
    
    // Check if using current list we can react result 24.
    bool checkIfResultReached(vector<double> list) {
        if (list.size() == 1) {
            // Base Case: We have only one number left, check if it is approximately 24.
            return abs(list[0] - 24) <= 0.1;
        }

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                // Create a new list with the remaining numbers and the new result.
                vector<double> newList;
                for (int k = 0; k < list.size(); k++) {
                    if (k != j && k != i) {
                        newList.push_back(list[k]);
                    }
                }
                
                // For any two numbers in our list,
                // we perform every operation one by one.
                for (double& res : generatePossibleResults(list[i], list[j])) {
                    // Push the new result in the list.
                    newList.push_back(res); 
                    
                    // Check if using this new list we can obtain the result 24.
                    if (checkIfResultReached(newList)) {
                        return true;
                    }
                    
                    // Backtrack: remove the result from the list.
                    newList.pop_back();
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> list(cards.begin(), cards.end());
        return checkIfResultReached(list);
    }
};


/**
679. 24 Game
Solved
Hard
Topics
conpanies iconCompanies

You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. 
You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] 
and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

    The division operator '/' represents real division, not integer division.
        For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
    Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
        For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
    You cannot concatenate numbers together
        For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.

Return true if you can get such expression that evaluates to 24, and false otherwise.
 */
