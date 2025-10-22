/**
 * @param {number[][]} grid
 * @return {number}
 */
var numDistinctIslands = function(grid) {
    if (grid.length === 0 || grid[0].length === 0) return;
    const m = grid.length, n = grid[0].length;
    const directions = [-1, 0, 1, 0, -1];
    const actions = ['U', 'L', 'D', 'R'];
    let path = '';

    const islands = new Set();
    for (let i = 0; i < m; ++ i) {
        for (let j = 0; j < n; ++ j) {
            if (grid[i][j] == 1) {
                path = '';
                dfs(i, j);
                islands.add(path);
            }
        }
    }

    return islands.size;

    function dfs(i, j) {
        grid[i][j] = 2; // so we don't visit a visited cell.

        for (let k = 0; k < 4; ++ k) {
            let x = i + directions[k], y = j + directions[k+1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] === 1) {
                    path += actions[k];
                    dfs(x, y);
                }
            }
        }

        path += '.';
    }
};
