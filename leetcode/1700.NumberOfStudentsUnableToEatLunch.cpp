// From: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/editorial/
// If none of the students in the queue's preference matches the top sandwich, none of the remaining students can eat.
// We can utilize this observation to develop a constant space solution.
//
// Time: O(m + n). m = students.size(), n = sandwiches.size().
// Space: O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleStudentCount = 0;
        int squareStudentCount = 0;

        // Count the number of students who want each type of sandwich
        for (int student : students) {
            if (student == 0) circleStudentCount++;
            else squareStudentCount++;
        }

        // Serve sandwiches to students
        for (int sandwich : sandwiches) {
            // No student wants the circle sandwich on top of the stack
            if (sandwich == 0 && circleStudentCount == 0) {
                return squareStudentCount;
            } 
            // No student wants the square sandwich on top of the stack
            if (sandwich == 1 && squareStudentCount == 0) {
                return circleStudentCount;
            }

            // Decrement the count of the served sandwich type
            if (sandwich == 0) circleStudentCount--;
            else squareStudentCount--;
        }

        return 0;
    }
};


// Time: O(m*n). m = students.size(), n = sandwiches.size().
// Space: O(m)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int student : students) q.push(student);

        int noMatchCount = 0;
        for (int i = 0; i < sandwiches.size(); ) {
            if (q.front() == sandwiches[i]) {
                ++ i;
                q.pop();
                noMatchCount = 0;
            } else {
                q.push(q.front());
                q.pop();

                ++ noMatchCount;
                if (noMatchCount == q.size()) return q.size();
            }
        }
        return 0;
    }
};


/**
1700. Number of Students Unable to Eat Lunch
Easy

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 
respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed 
in a stack. At each step:

    If the student at the front of the queue prefers the sandwich on the top of the stack, they will 
        take it and leave the queue.
    Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich 
in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the 
initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

 

Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.

Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
 */
