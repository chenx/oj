/**
 * @param {number} k
 * @param {number} n
 * @return {number}
 */
var superEggDrop = function(K, N) {
    // F(k, n) = 1 + min{h=1..k}( max(F(k-1, h-1), F(k, n-h)) )
    let L = 0, R = N;
    while (L < R) {
        let M = Math.floor( (L + R) / 2 );
        if (f(M, K, N) < N) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    return L;

    function f(x, K, N) {
        let ans = 0, r = 1;
        for (let i = 1; i <= K; ++ i) {
            r = r * (x - i + 1) / i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
    }
};
