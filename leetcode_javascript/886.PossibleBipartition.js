/**
 * @param {number} n
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function(n, dislikes) {
    // const adj = new Array(n+1).fill([]); // This won't work. All adj[i] use the same []
    const adj = new Array(n + 1); // [n, n_neighbors[]]
    for (let i = 0; i <= n; ++ i) adj[i] = [];

    dislikes.forEach(dislike => {
        adj[dislike[0]].push(dislike[1]);
        adj[dislike[1]].push(dislike[0]);
    });

    const color = new Array(n+1).fill(-1);

    function dfs(i) {
        for (const neighbor of adj[i]) {
            if (color[neighbor] === color[i]) return false;
            if (color[neighbor] === -1) {
                color[neighbor] = 1 - color[i];
                if (! dfs(neighbor)) return false;
            }
        }
        return true;
    }

    for (let i = 1; i <= n; ++ i) {
        if (color[i] === -1) {
            color[i] = 0;
            if (! dfs(i)) return false;
        }
    }
    return true;
};
