// From: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/editorial/
// Sorting + Two Pointers
// Time complexity: O(nlogn+mlogm)
// Space complexity: O(n+logm) or O(n+m)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> sortedSpells;
        for (int i = 0; i< spells.size(); ++i) {
            sortedSpells.push_back({ spells[i], i });
        }

        // Sort the 'spells with index' and 'potions' array in increasing order.
        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> answer(spells.size());
        int m = potions.size();
        int potionIndex = m - 1;
        
        // For each 'spell' find the respective 'minPotion' index.
        for (const auto& [spell, index] : sortedSpells) {
            while (potionIndex >= 0 && (long long) spell * potions[potionIndex] >= success) {
                potionIndex -= 1;
            }
            answer[index] = m - (potionIndex + 1);
        }
        
        return answer;
    }
};


/**
2300. Successful Pairs of Spells and Potions
Medium

You are given two positive integer arrays spells and potions, of length n and m respectively, where 
spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product 
of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a 
successful pair with the ith spell.
 */
