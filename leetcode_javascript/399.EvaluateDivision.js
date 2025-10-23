/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
    // map<nom, array<pair<den, value>>.
    const adj = new Map();
    const vars = new Set();
    const n = equations.length;
    for (let i = 0; i < n; ++ i) {
        const e = equations[i];
        vars.add(e[0]), vars.add(e[1]);

        if (!adj.has(e[0])) adj.set(e[0], []);
        adj.get(e[0]).push([e[1], values[i]]);

        if (!adj.has(e[1])) adj.set(e[1], []);
        adj.get(e[1]).push([e[0], 1.0 / values[i]]);
    }

    const ans = [];
    for (let i = 0; i < queries.length; ++ i) {
        const [startWord, endWord] = queries[i];
        if (! vars.has(startWord) || ! vars.has(endWord)) {
            ans.push(-1.0);
            continue;
        }
        if (startWord === endWord) {
            ans.push(1.0);
            continue;
        }

        const q = [];
        q.push([startWord, 1.0]);

        const used = new Set();
        used.add(startWord);

        let found = false;
        while (q.length > 0) {
            const [word, value] = q.shift();

            for (const [nextWord, nextValue] of adj.get(word)) {
                if (nextWord === endWord) {
                    found = true;
                    ans.push(value * nextValue);
                    break;
                }
                if (! used.has(nextWord)) {
                    q.push([nextWord, value * nextValue]);
                    used.add(nextWord);
                }
            }
            if (found) break;
        }
        if (!found) ans.push(-1.0);
    }

    return ans;
};
