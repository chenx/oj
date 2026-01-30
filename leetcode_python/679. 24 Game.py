class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        def calcTwo(i, j):
            result = [
                i + j,
                i - j,
                j - i,
                i * j,
            ]
            if i != 0:
                result.append(j / i)
            if j != 0:
                result.append(i / j)
            
            return result

        def judge(cards) -> bool:
            # if len(cards) == 1: # no need, this won't happen
            #     return cards[0] == 24
            if len(cards) == 2:
                result = calcTwo(cards[0], cards[1])
                # return 24 in result
                for r in result:
                    if abs(r - 24) < 0.00001:
                        return True
                return False
            
            n = len(cards)
            for i in range(n-1):
                for j in range(i+1, n):
                    # compute from result + other cards
                    otherCards = []
                    for k in range(n):
                        if k != i and k != j:
                            otherCards.append(cards[k])
                    
                    result = calcTwo(cards[i], cards[j])
                    for v in result:
                        otherCardsCopy = otherCards.copy()
                        otherCardsCopy.append(v)
                        if judge(otherCardsCopy):
                            return True
            return False

        return judge(cards)

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
