/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
        if (beginWord === endWord) return 1;

        const words = new Set();
        for (let word of wordList) words.add(word);

        const queue = [];
        queue.push([beginWord, 1]);

        const used = new Set();
        used.add(beginWord);

        const letters = 'abcdefghijklmnopqrstuvwxyz'.split(''); // !!!

        while (queue.length > 0) {
            const [word, dist] = queue.shift();  // !!! <-------- shift() == pop()

            const wordArray = word.split('');
            for (let i = 0; i < wordArray.length; ++ i) {
                const backup = wordArray[i];

                for (let j = 0; j < letters.length; ++ j) {
                    const ch = letters[j];
                    if (ch === backup) continue;
                    wordArray[i] = ch;

                    const next = wordArray.join('');
                    if (words.has(next) && ! used.has(next)) {
                        if (next === endWord) return dist + 1;
                        queue.push([next, dist + 1]);
                        used.add(next);
                    }
                }

                wordArray[i] = backup;
            }
        }
        return 0;
};
