// Version 2. works too.
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands2 = function(grid) {
    if (grid.length === 0 || grid[0].length === 0) return 0;
    const m = grid.length, n = grid[0].length;
    let count = 0;
    const directions = [-1, 0, 1, 0, -1];

    for (let i = 0; i < m; ++ i) {
        for (let j = 0; j < n; ++ j) {
            if (grid[i][j] == '1') {
                ++ count;
                traversal(i, j);
            }
        }
    }
    return count;

    // Note: if use the const definition, then it's an error since it needs to be declared before use.
    // But function will be hoisted to the top of the scope.
    // Function expressions and arrow functions are not hoisted in the same way as function declarations. 
    // They behave like let or const variables, meaning their declaration is hoisted but not their assignment.
    // const traversal = (i, j) => {
    function traversal(i, j) {
        grid[i][j] = '2';

        for (let k = 0; k < 4; ++ k) {
            let x = i + directions[k], y = j + directions[k+1];

            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] === '1') {
                    traversal(x, y);
                }
            }
        }
    }
};


/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if (grid.length === 0 || grid[0].length === 0) return 0;
    const m = grid.length, n = grid[0].length;
    let count = 0;
    const directions = [-1, 0, 1, 0, -1];

    // function traversal(i, j) {
    const traversal = (i, j) => {
        grid[i][j] = '2';

        for (let k = 0; k < 4; ++ k) {
            let x = i + directions[k], y = j + directions[k+1];

            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] === '1') {
                    traversal(x, y);
                }
            }
        }
    }

    for (let i = 0; i < m; ++ i) {
        for (let j = 0; j < n; ++ j) {
            if (grid[i][j] == '1') {
                ++ count;
                traversal(i, j);
            }
        }
    }
    return count;
};

