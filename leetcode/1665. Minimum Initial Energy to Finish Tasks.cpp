// From: https://algo.monster/liteproblems/1665
// Time: O(nlogn) for sorting
// Space: O(1) (or O(n) is sorting costs space)
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by actual - minimum.
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });

        int totalEffort = 0, curEffort = 0;

        for (int i = 0; i < tasks.size(); ++ i) {
            int actualEffort = tasks[i][0], curMinEffort = tasks[i][1];
            if (curEffort < curMinEffort) {
                totalEffort += curMinEffort - curEffort;
                curEffort = curMinEffort;
            }

            curEffort -= actualEffort;   
        }

        return totalEffort;
    }
};


/**
1665. Minimum Initial Energy to Finish Tasks
Solved
Hard
Topics
conpanies iconCompanies
Hint

You are given an array tasks where tasks[i] = [actuali, minimumi]:

    actuali is the actual amount of energy you spend to finish the ith task.
    minimumi is the minimum amount of energy you require to begin the ith task.

For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. 
However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.

 

Example 1:

Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
 */
