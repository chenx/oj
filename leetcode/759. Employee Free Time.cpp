// From: https://leetcode.com/problems/employee-free-time/editorial/
// Time Complexity: O(ClogC), where C is the number of intervals across all employees.
// Space Complexity: O(C).
//
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        const int OPEN = 0;
        const int CLOSE = 1;

        vector<pair<int, int>> events;
        for (const auto& employee : avails) {
            for (const auto& iv : employee) {
                events.push_back({iv.start, OPEN});
                events.push_back({iv.end, CLOSE});
            }
        }

        // Sort by time, then by type
        sort(events.begin(), events.end()); 

        vector<Interval> ans;
        int prev = -1;
        int bal = 0;

        for (const auto& event : events) {
            int time = event.first;
            int type = event.second;

            // If no one is working, it's free time
            if (bal == 0 && prev >= 0) {
                ans.push_back(Interval(prev, time));
            }

            bal += (type == OPEN) ? 1 : -1;
            prev = time;
        }

        return ans;
    }
};


// From: https://leetcode.com/problems/employee-free-time/editorial/
// 
// Time Complexity: O(ClogN), where N is the number of employees, and C is the number of jobs across all employees. 
// The maximum size of the heap is N, so each push and pop operation is O(logN), and there are O(C) such operations.
// Space Complexity: O(N) in additional space complexity.
class Solution {
    struct Job {
        int eid;
        int index;
        Job(int e, int i) : eid(e), index(i) {}
    };
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        vector<Interval> ans;

        auto cmp = [&](const Job& a, const Job& b) {
            return avails[a.eid][a.index].start >
                   avails[b.eid][b.index].start;
        };

        priority_queue<Job, vector<Job>, decltype(cmp)> pq(cmp);

        int anchor = INT_MAX;

        for (int ei = 0; ei < avails.size(); ++ei) {
            pq.push(Job(ei, 0));
            anchor = min(anchor, avails[ei][0].start);
        }

        while (!pq.empty()) {
            Job job = pq.top();
            pq.pop();

            Interval iv = avails[job.eid][job.index];

            if (anchor < iv.start) {
                ans.push_back(Interval(anchor, iv.start));
            }

            anchor = max(anchor, iv.end);

            ++job.index;

            if (job.index < avails[job.eid].size()) {
                pq.push(job);
            }
        }

        return ans;
    }
};


/**
759. Employee Free Time
Hard
Topics
conpanies iconCompanies
Hint

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. 
For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't 
include intervals like [5, 5] in our answer, as they have zero length.

 

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
 */
