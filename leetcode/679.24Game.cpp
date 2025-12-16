// Brute force, list all permutations.
class Solution3 {
public:
    vector<double> F(double a, double b) {
        vector<double> v = {a + b, a - b, b - a, a * b};
        if (abs(a) > 0.00001) v.push_back(b/a);
        if (abs(b) > 0.00001) v.push_back(a/b);
        return v;
    }

    bool has24(vector<double>& A) {
        for (auto a : A) {
            if (abs(a - 24) < 0.00001) return true;
        }
        return false;
    }

    bool calc(vector<double>& input) {
        int a = input[0], b = input[1], c = input[2], d = input[3];
        auto A = F(a, b), B = F(b, c), C = F(c, d);

        // ((a b) c) d
        for (auto n : A) {
            auto B = F(n, c);
            for (auto m : B) {
                auto C = F(m, d);
                if (has24(C)) return true;
            }
        }

        // (a b) (c d)
        for (auto n : A) {
            for (auto m : C) {
                auto D = F(n, m);
                if (has24(D)) return true;
            }
        }

        // (a (b c)) d
        for (auto n : B) {
            auto C = F(a, n);
            for (auto m : C) {
                auto D = F(m, d);
                if (has24(D)) return true;
            }
        }

        // a ((b c) d)
        for (auto n : B) {
            auto C = F(n, d);
            for (auto m : C) {
                auto D = F(a, m);
                if (has24(D)) return true;
            }
        }

        // a (b (c d))
        for (auto n : C) {
            auto B = F(b, n);
            for (auto m : B) {
                auto C = F(a, m);
                if (has24(C)) return true;
            }
        }

        return false;
    }

    void getPerm(vector<vector<double>>& result, 
                 vector<double>& input, vector<double> output, int pos) {
        if (pos == output.size()) {
            result.push_back(output);
            return;
        }

        for (int i = 0; i < input.size(); ++ i) {
            output[pos] = input[i];
            auto input2 = input;
            input2.erase(input2.begin() + i);
            getPerm(result, input2, output, pos + 1);
        }
    }

    vector<vector<double>> getPermutations(vector<double>& input) {
        vector<vector<double>> result;
        vector<double> output (input.size());
        getPerm(result, input, output, 0);
        return result;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> input(cards.begin(), cards.end());
        vector<vector<double>> permutations = getPermutations(input);
        cout << "permutations size = " << permutations.size() << endl;
        for (auto perm : permutations) {
            // for (auto x : perm) cout << x << " ";
            // cout << endl;
            if (calc(perm)) return true;
        }
        return false;
    }
};

// Same as Solution.
class Solution2 {
public:
    vector<double> getResultsOfTwoElements(double a, double b) {
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
        
                vector<double> tmp = getResultsOfTwoElements(input[i], input[j]);
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

// https://leetcode.com/problems/24-game/editorial/
// Time complexity: O(N^3⋅3^(N−1)⋅N!⋅(N−1)!).
// Space complexity: O(N^2).
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
