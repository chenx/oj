// From: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/editorial/
// Let n be the number of recipes, m be the total number of ingredients across all recipes, and s be the number of supplies.
// Time complexity: O(n+m+s)
// Space complexity: O(n+s)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> ans;
        map<string, bool> canMake; // Track if ingredient/recipe can be made
        map<string, int> recipeIndex; // Map recipe name to its index in ingredients list

        for (const string& supply : supplies) { // Mark all initial supplies as available
            canMake[supply] = true;
        }

        for (int i = 0; i < recipes.size(); ++ i) { // Create recipe to index mapping
            recipeIndex[recipes[i]] = i;
        }

        for (const string& recipe : recipes) { // Try to make each recipe using DFS
            set<string> visited;
            checkRecipe(recipe, ingredients, visited, canMake, recipeIndex);
            if (canMake[recipe]) {
                ans.push_back(recipe);
            }
        }

        return ans;
    }

private:
    void checkRecipe(const string& recipe, vector<vector<string>>& ingredients,
                     set<string>& visited,
                     map<string, bool>& canMake,
                     map<string, int>& recipeIndex) {
        if (canMake.contains(recipe)) return;

        // Not a valid recipe or cycle detected
        if (! recipeIndex.contains(recipe) || visited.count(recipe)) {
            canMake[recipe] = false;
            return;
        }

        visited.insert(recipe);

        // Check if we can make all required ingredients
        int index = recipeIndex[recipe];
        for (const string& ingredient : ingredients[index]) {
            checkRecipe(ingredient, ingredients, visited, canMake, recipeIndex);
            if (!canMake[ingredient]) {
                canMake[recipe] = false;
                return;
            }
        }

        canMake[recipe] = true; // All ingredients can be made
    }
};

/**
2115. Find All Possible Recipes from Given Supplies
Medium

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. 
A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an 
infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.
 */
