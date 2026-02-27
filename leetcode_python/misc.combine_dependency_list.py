class DependencyList:
    def group_dependency_list(self, input: dict[str, list[str]]) -> list[list[str]]:
        map : dict[str, set[str]] = {}
        for key, val in input.items():
            map[key] = set(val)
            for v in val:
                if not v in map:
                    map[v] = set()
                map[v].add(key)
        # print(map)

        result = []
        used = set()

        for key, val in map.items():
            if key in used:
                continue

            row = []
            self.dfs(row, used, key, map)
            row.sort()
            result.append(row)

        # print(f"result = {result}")
        return result


    def dfs(self, row, used, key, map):
        row.append(key)
        used.add(key)

        if key in map:
            for v in map[key]:
                if not v in used:
                    self.dfs(row, used, v, map)


class DependencyListTest:
    def test1(self):
        dl = DependencyList()
        input = {'a' : ['b', 'c', 'd'], 'b' : ['e', 'f'], 'g': ['d'], 'h': ['i']}
        result = dl.group_dependency_list(input)

        expected_output = [['a', 'b', 'c', 'd', 'e', 'f', 'g'], ['h', 'i']]
        assert result == expected_output

    def run_tests(self):
        self.test1()

print("hi")
test = DependencyListTest()
test.run_tests()

/**
misc.combine_dependency_list
Given dependency:
a -> b, c, d
b -> e, f
g -> d
h -> i

combine them into:
[['a', 'b', 'c', 'd', 'e', 'f', 'g'], ['h', 'i']]
 */
