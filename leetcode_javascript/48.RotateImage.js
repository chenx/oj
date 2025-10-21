/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const n = matrix.length;

    for (let layer = 0; layer < n/2; ++ layer) {
        let start = layer, last = n - 1 - layer;

        for (let i = start; i < last; ++ i) {
            const offset = i - start;
            const tmp = matrix[start][i];
            matrix[start][i] = matrix[last - offset][start];
            matrix[last - offset][start] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = tmp;
        }
    }
};
