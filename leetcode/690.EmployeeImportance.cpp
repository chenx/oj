/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// From: https://leetcode.com/problems/employee-importance/editorial/
// DFS.
// Time Complexity: O(N), where N is the number of employees. We might query each employee in dfs.
// Space Complexity: O(N), the size of the implicit call stack when evaluating dfs.
//
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> employeeMap; // <id, employee>
        for (auto employee : employees) {
            employeeMap[employee->id] = employee;
        }
        return dfs(id, employeeMap);
    }

    int dfs(int id, map<int, Employee*>& employeeMap) {
        Employee* employee = employeeMap[id];
        int sum = employee->importance;
        for (int subordinate : employee->subordinates) {
            sum += dfs(subordinate, employeeMap);
        }
        return sum;
    }
};


/**
690. Employee Importance
Medium

You have a data structure of employee information, including the employee's unique ID, importance value, 
and direct subordinates' IDs.

You are given an array of employees employees where:

    employees[i].id is the ID of the ith employee.
    employees[i].importance is the importance value of the ith employee.
    employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.

Given an integer id that represents an employee's ID, return the total importance value of this employee 
and all their direct and indirect subordinates.
 */
