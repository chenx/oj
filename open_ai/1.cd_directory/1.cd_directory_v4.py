# 2:15 - 2:58 : 43 min

from collections import deque

class CdDirectory:
    def contains_cycle(self, softlinks):
        links = set()
        in_degree, out_degree = {}, {} # <string, set<string>>

        for key, val in softlinks.items():
            links.add(key)
            links.add(val)
            if val not in in_degree: in_degree[val] = set()
            if key not in out_degree: out_degree[key] = set()
            in_degree[val].add(key)
            out_degree[key].add(val)

        q = deque()
        used = set()
        for link in links:
            if link not in in_degree or len( in_degree[link] ) == 0:
                q.append(link)
                used.add(link)

        while len(q) > 0:
            link = q.popleft()

            if link in out_degree:
                for next_link in out_degree[link]:
                    in_degree[next_link].remove(link)
                    if len(in_degree[next_link]) == 0:
                        in_degree.pop(next_link) # otherwise, need to check len below.

                    if next_link not in in_degree and next_link not in used:
                        q.append(next_link)
                        used.add(next_link)

        return len(links) != len(used)

    def cd_with_softlinks(self, cur_dir, new_dir, softlinks):
        if self.contains_cycle(softlinks):
            return "Error: Cycle Detected"
        
        long_path = cur_dir + "/" + new_dir
        if long_path in softlinks:
            while long_path in softlinks:
                long_path = softlinks[long_path]
            return self.simplify_path(long_path)
        
        # else, long path has no match in softlinks
        while cur_dir in softlinks:
            cur_dir = softlinks[cur_dir]
        while new_dir in softlinks:
            new_dir = softlinks[new_dir]
        path = cur_dir + "/" + new_dir
        while path in softlinks:
            path = softlinks[path]
        return self.simplify_path(path)

    def cd(self, cur_dir, new_dir):
        cur_dir = self.simplify_path(cur_dir)
        new_dir = self.simplify_path(new_dir)
        if cur_dir == "Null" or new_dir == "Null":
            return "Null"
        return self.simplify_path(cur_dir + "/" + new_dir)

    def simplify_path(self, path):
        tokens = []
        for token in path.split('/'):
            if token == "" or token == ".":
                pass
            elif token == "..":
                if len(tokens) > 0:
                    tokens.pop()
                else:
                    return "Null"
            elif token == "~":
                tokens.clear()
            else:
                tokens.append(token)
        
        return "/" + "/".join(tokens)
        

class CdDirectoryTest:
    def assertEq(self, result, expect):
        if result == expect:
            print(f"Pass: result = {result}")
        else:
            print(f"Fail: result = {result}, expect = {expect}")

    def test_cd(self):
        print("\ntest_cd")
        cd = CdDirectory()
        self.assertEq(cd.cd("/foo/bar", "baz"), "/foo/bar/baz")
        self.assertEq(cd.cd("/foo/../", "./baz"), "/baz")
        self.assertEq(cd.cd("/", "foo/bar/../../baz"), "/baz")
        self.assertEq(cd.cd("/", ".."), "Null")
        self.assertEq(cd.cd("/a/b/c/~", "d/e"), "/d/e")
        self.assertEq(cd.cd("/a/b/c/", "d/~/e"), "/a/b/c/e")
    
    def test_cd_with_softlinks(self):
        print("\ntest_cd_with_softlinks")
        cd = CdDirectory()
        softlinks = {"/foo/bar" : "/abc", "/foo/bar/baz" : "xyz"}
        self.assertEq(cd.cd_with_softlinks("/foo/bar", "baz", softlinks), "/xyz")
    
    def test_cd_with_softlinks_with_cycle(self):
        print("\ntest_cd_with_softlinks_with_cycle")
        cd = CdDirectory()
        softlinks = {"/foo/bar" : "/abc", "/foo/bar/baz" : "xyz", "a": "a"}
        self.assertEq(cd.cd_with_softlinks("/foo/bar", "baz", softlinks), "Error: Cycle Detected")

    def run_tests(self):
        self.test_cd()
        self.test_cd_with_softlinks()
        self.test_cd_with_softlinks_with_cycle()
    

if __name__ == "__main__":
    test = CdDirectoryTest()
    test.run_tests()
