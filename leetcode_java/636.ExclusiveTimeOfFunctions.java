// From: https://leetcode.com/problems/exclusive-time-of-functions/editorial/
// Time complexity : O(n) 
// Space complexity: O(n)
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> stack = new Stack(); // stack of function id
        int[] ans = new int[n];

        String[] s = logs.get(0).split(":"); // func_id, start/end, timestamp
        stack.push(Integer.valueOf(s[0]));
        int i = 1, prevTime = Integer.parseInt(s[2]);
        while (i < logs.size()) {
            s = logs.get(i).split(":");
            int curTime = Integer.valueOf(s[2]);
            if (s[1].equals("start")) {
                if (! stack.isEmpty()) {
                    ans[stack.peek()] += curTime - prevTime;
                }
                stack.push(Integer.valueOf(s[0]));
                prevTime = curTime;
            } else {
                ans[stack.peek()] += curTime - prevTime + 1;
                stack.pop();
                prevTime = curTime + 1;
            }
            ++ i;
        }
        return ans;
    }
}

/**
636. Exclusive Time of Functions
Medium

On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, 
and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the 
stack is the current function being executed. Each time a function starts or ends, we write a log with 
the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string 
"{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 
started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end 
of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, 
if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, 
the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time 
for the function with ID i.
 */
