// Let n be the number of tasks at initialization and m be the number of subsequent operations.
// Time complexity: Initialization takes O(nlogn). add and edit each take O(log(n+m)). rmv takes O(1). 
//     execTop has an average cost of O(log(n+m)).
// Space complexity: O(n+m).
class TaskManager {
    priority_queue<pair<int, int>> maxHeap; // <priority, taskId>
    unordered_map<int, pair<int, int>> taskInfo; // <taskId, <priority, userId>>
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority, taskId});
        taskInfo[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        taskInfo[taskId].first = newPriority;
        maxHeap.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskInfo.erase(taskId);
    }

    int execTop() {
        while (! maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();
            if (taskInfo.contains(taskId) && taskInfo[taskId].first == priority) {
                int userId = taskInfo[taskId].second;
                taskInfo.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
    
    // int execTop2() {
    //     while (! maxHeap.empty()) {
    //         int priority = maxHeap.top().first, taskId = maxHeap.top().second;
    //         if (! taskInfo.contains(taskId)) { // removed.
    //             maxHeap.pop();
    //         } else if (taskInfo[taskId].first != priority) { // stale entry.
    //             maxHeap.pop();
    //         } else {
    //             int userId = taskInfo[taskId].second;
    //             taskInfo.erase(taskId);
    //             maxHeap.pop();
    //             return userId;
    //         }
    //     }
    //     return -1;
    // }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */


/**
3408. Design Task Manager
Solved
Medium
Topics
conpanies iconCompanies

There is a task management system that allows users to manage their tasks, each associated with a priority. 
The system should efficiently handle adding, modifying, executing, and removing tasks.

Implement the TaskManager class:

    TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority 
    triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to 
    the specified user with the given priority.

    void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to 
    the user with userId. It is guaranteed that taskId does not exist in the system.

    void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. 
    It is guaranteed that taskId exists in the system.

    void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that 
    taskId exists in the system.

    int execTop() executes the task with the highest priority across all users. If there are multiple 
    tasks with the same highest priority, execute the one with the highest taskId. After executing, the 
    taskId is removed from the system. Return the userId associated with the executed task. If no tasks 
    are available, return -1.

Note that a user may be assigned multiple tasks.

 

Example 1:

Input:
["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
[[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]

Output:
[null, null, null, 3, null, null, 5]

Explanation
TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
taskManager.edit(102, 8); // Updates priority of task 102 to 8.
taskManager.execTop(); // return 3. Executes task 103 for User 3.
taskManager.rmv(101); // Removes task 101 from the system.
taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
taskManager.execTop(); // return 5. Executes task 105 for User 5.
 */
