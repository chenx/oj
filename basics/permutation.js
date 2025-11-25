function permutation(array) {
    const result = [];
    perm(array, 0);
    return result;

    function perm(array, pos) {
        if (pos == array.length) {
            result.push([...array]);
            return;
        }

        for (let i = pos; i < array.length; ++ i) {
            swap(array, i, pos);
            perm(array, pos + 1);
            swap(array, i, pos);
        }
    }

    function swap(array, i, j) {
        const tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

console.log(permutation([1,2,3]));
