// From: https://walkccc.me/LeetCode/problems/3494/
// Time: O(nm)
// Space: O(1)
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long sumSkill = accumulate(skill.begin(), skill.end(), 0L);
    long prevWizardDone = sumSkill * mana[0];

    for (int j = 1; j < mana.size(); ++j) {
      long prevPotionDone = prevWizardDone;
      for (int i = skill.size() - 2; i >= 0; --i) {
        // start time for wizard i brewing potion j
        // = max(end time for wizard i brewing potion j - 1,
        //       the earliest start time for wizard i + 1 brewing potion j
        //       (coming from previous iteration)
        //       - time for wizard i brewing potion j)
        prevPotionDone -= static_cast<long>(skill[i + 1]) * mana[j - 1];
        prevWizardDone =
            max(prevPotionDone,
                prevWizardDone - static_cast<long>(skill[i]) * mana[j]);
      }
      prevWizardDone += sumSkill * mana[j];
    }

    return prevWizardDone;
    }
};


/**
3494. Find the Minimum Amount of Time to Brew Potions
Medium

You are given two integer arrays, skill and mana, of length n and m, respectively.

In a laboratory, n wizards must brew m potions in order. Each potion has a mana capacity mana[j] and must pass through all the wizards sequentially to be brewed properly. The time taken by the ith wizard on the jth potion is timeij = skill[i] * mana[j].

Since the brewing process is delicate, a potion must be passed to the next wizard immediately after the current wizard completes their work. This means the timing must be synchronized so that each wizard begins working on a potion exactly when it arrives. ​

Return the minimum amount of time required for the potions to be brewed properly.

 

Example 1:

Input: skill = [1,5,2,4], mana = [5,1,4,2]

Output: 110
 */
