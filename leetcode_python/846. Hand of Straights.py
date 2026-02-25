# Reverse Decrement (Most Optimal)
# From: https://leetcode.com/problems/hand-of-straights/editorial/
# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        # Counter to store the count of each card value
        card_count = Counter(hand)

        for card in hand:
            start_card = card
            # Find the start of the potential straight sequence
            while card_count[start_card - 1]:
                start_card -= 1

            # Process the sequence starting from start_card
            while start_card <= card:
                while card_count[start_card]:
                    # Check if we can form a consecutive sequence
                    # of groupSize cards
                    for next_card in range(start_card, start_card + groupSize):
                        if not card_count[next_card]:
                            return False
                        card_count[next_card] -= 1
                start_card += 1

        return True

/**
846. Hand of Straights
Medium
Topics
conpanies iconCompanies

Alice has some number of cards and she wants to rearrange the cards into groups so that each group 
is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
 */
