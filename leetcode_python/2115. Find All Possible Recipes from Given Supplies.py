class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        def dfs(recipe, ingredients, canMake, recipeIndex, visited):
            if recipe in canMake:
                return canMake[recipe]
            # if recipe in canMake and canMake[recipe]: # also works.
            #     return
            
            if not recipe in recipeIndex or recipe in visited:
                canMake[recipe] = False
                return
            visited.add(recipe)

            for ingredient in ingredients[recipeIndex[recipe]]:
                dfs(ingredient, ingredients, canMake, recipeIndex, visited)
                if not canMake[ingredient]:
                    canMake[recipe] = False
                    return
            canMake[recipe] = True
            return 


        result = []
        canMake = {supply: True for supply in supplies} # <recipe, boolean>
        recipeIndex = {recipe: index for (index, recipe) in enumerate(recipes)} # <recipe, index>

        for recipe in recipes:
            visited = set()
            dfs(recipe, ingredients, canMake, recipeIndex, visited)
            if recipe in canMake and canMake[recipe]:
                result.append(recipe)

        return result


/**
2115. Find All Possible Recipes from Given Supplies
Solved
Medium
Topics
conpanies iconCompanies
Hint

You have information about n different recipes. You are given a string array recipes and a 2D string 
array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the 
needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., 
ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and 
you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
 */
