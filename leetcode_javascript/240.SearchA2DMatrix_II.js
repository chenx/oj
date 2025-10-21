/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let m = matrix.length, n = matrix[0].length;

    // Both work.
    // for (let i = m-1, j = 0; i >= 0 && j < n; ) {
    //     if (matrix[i][j] === target) return true;
    //     if (matrix[i][j] < target) ++ j;
    //     else -- i;
    // }
    for (let i = 0, j = n-1; i < m && j >= 0; ) {
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] < target) ++ i;
        else -- j;
    }
    return false;
};
