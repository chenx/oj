/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const map = new Map();
    strs.forEach(str => {
        const chars = str.split('');
        chars.sort();
        const key = chars.join('');
        if (!map.has(key)) map.set(key, []);
        map.get(key).push(str);
    });

    const ans = [];
    for (const [key, value] of map.entries()) {
        // value.sort();
        ans.push(value);
    }
    return ans;
};

/*
vector<vector<string>> ans;

        unordered_map<string, vector<string>> m;
        for (auto& str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }

        for (auto& item : m) {
            sort(item.second.begin(), item.second.end());
            ans.push_back(item.second);
        }
        return ans;
*/
