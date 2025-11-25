function combination(array, k) {
    const result = [];
    const curCombination = [];
    comb(array, k, 0, curCombination);
    return result;

    function comb(array, k, pos, curCombination) {
        if (curCombination.length == k) {
            result.push([...curCombination]);
            return;
        }

        for (let i = pos; i < array.length; ++ i) {
            curCombination.push(array[i]);
            comb(array, k, i + 1, curCombination);
            curCombination.pop();
        }
    }
}

console.log(combination([1,2,3,4], 3));
