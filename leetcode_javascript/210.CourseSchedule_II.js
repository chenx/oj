/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function(numCourses, prerequisites) {
    const ans = [];
    //    map<int, set<int>> in, out;
    const ain = new Map(), out = new Map();

    for (let pre of prerequisites) {
        // ain[pre[0]].insert(pre[1]);  // pre-requisites
        // out[pre[1]].insert(pre[0]);
        if (!ain.has(pre[0])) ain.set(pre[0], new Set());
        ain.get(pre[0]).add(pre[1]);

        if (!out.has(pre[1])) out.set(pre[1], new Set());
        out.get(pre[1]).add(pre[0]);
    }

    const courses = new Set();
    for (let i = 0; i < numCourses; ++ i) courses.add(i);

    while (courses.size > 0) {
        let found = false;
        for (let course of courses) {
            // This does not work: if (!in.contains(course)) {
            if (!ain.has(course) || ain.get(course).size === 0) { // Course has no prerequisite.
                found = true;
                ans.push(course);
                courses.delete(course);
                    
                for (let c of (out.get(course) || [])) {
                    ain.get(c).delete(course); // Remove course from prequisite list of c.
                }
                // ain.delete(course);
                // out.delete(course);
            }
        }
        if (!found) return [];
    }
    return ans;
};
