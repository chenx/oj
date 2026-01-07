import queue

class Solution:
    def simplifyPath(self, path):
        # tokens = path.split('/')
        tokens = filter(lambda x : x != '.' and x != '', path.split('/'))
        result = []
        for token in tokens:
            if token == "..":
                if len(result) > 0: result.pop()
                else: return 'Null'
            else:
                result.append(token)

        return '/' + '/'.join(result)

    
    def cd(self, current_dir, new_dir):
        if self.simplifyPath(current_dir) == 'Null' or self.simplifyPath(new_dir) == 'Null': 
            return 'Null'
        return self.simplifyPath(current_dir + '/' + new_dir)

    
    def hasCycle(self, soft_links):
        """ O(n) Kahn algorithm: Topological sorting. """
        inDegree = {}
        outDegree = {}
        links = set()
        for key, value in soft_links.items():
            if not key in outDegree:
                outDegree[key] = set()
            outDegree[key].add(value)
            inDegree[value] = inDegree.get(value, 0) + 1
        visited = set()
        stack = [k for k, v in inDegree.items() if v == 0]
        while stack:
            node = stack.pop()
            visited.add(node)
            for neighbor in outDegree[node]:
                inDegree[neighbor] -= 1
                if inDegree[neighbor] == 0:
                    stack.append(neighbor)
        return len(visited) != len(soft_links)

    
    def cdWithSoftLinks(self, current_dir, new_dir, soft_links):
        # print(soft_links)
        if self.hasCycle(soft_links):
            return 'Cycle Detected'
        
        result = self.simplifyPath(current_dir + "/" + new_dir)
        # print("result: ", result)
        if result in soft_links:
            # print('resul tin soft_link')
            while result in soft_links:
                result = soft_links[result]
            return result
        
        while current_dir in soft_links:
            current_dir = soft_links[current_dir]
        while new_dir in soft_links:
            new_dir = soft_links[new_dir]
        result = self.simplifyPath(current_dir + "/" + new_dir)
        while result in soft_links:
            result = soft_links[result]
        return result


    def hasCycle2(self, soft_links):
        inDegree = {}
        outDegree = {}
        links = set()
        for key, value in soft_links.items():
            if not key in outDegree:
                outDegree[key] = set()
            outDegree[key].add(value)
            if not value in inDegree:
                inDegree[value] = set()
            inDegree[value].add(key)

            links.add(key)
            links.add(value)
        
        q = queue.Queue()
        for link in links:
            if not link in inDegree or len(inDegree[link]) == 0:
                q.put(link)
        
        visited = set()
        
        while not q.empty():
            link = q.get()
            visited.add(link)
            
            if link in outDegree:
                for nextLink in outDegree[link]:
                    inDegree[nextLink].remove(link)
                    if not nextLink in inDegree or len(inDegree[nextLink]) == 0:
                        q.put(nextLink)

        # print("len(links) = ", len(links), ", len(visited) = ", len(visited))
        return len(links) > len(visited)


    def hasCycle3(self, soft_links):
        inDegree = {}
        outDegree = {}
        links = set()
        for key, value in soft_links.items():
            if not key in outDegree:
                outDegree[key] = set()
            outDegree[key].add(value)
            if not value in inDegree:
                inDegree[value] = set()
            inDegree[value].add(key)

            links.add(key)
            links.add(value)
        
        q = queue.Queue()
        for link in links:
            if not link in inDegree or len(inDegree[link]) == 0:
                # print('q.put: ' + link)
                q.put(link)
        
        while not q.empty():
            link = q.get()
            # print('remove: link = ' + link)
            links.remove(link)

            if link in outDegree:
                for nextLink in outDegree[link]:
                    inDegree[nextLink].remove(link)
                    if not nextLink in inDegree or len(inDegree[nextLink]) == 0:
                        q.put(nextLink)

        # print("links: ", links)
        return len(links) > 0
    

class SolutionTest:
    def testSimplifyPath(self, path, expect):
        so = Solution()
        result = so.simplifyPath("/abc/../c/././d")
        if result == expect:
            print('Pass: result = ' + result)
        else:
            print('Fail: result = ' + result + ', expect = ' + expect)

    def testCd(self, current_dir, new_dir, expect):
        so = Solution()
        result = so.cd(current_dir, new_dir)
        if result == expect:
            print('Pass: result = ' + result)
        else:
            print('Fail: result = ' + result + ', expect = ' + expect)
    
    def testCdWithSoftLinks(self, current_dir, new_dir, soft_links, expect):
        so = Solution()
        result = so.cdWithSoftLinks(current_dir, new_dir, soft_links)
        if result == expect:
            print('Pass: result = ' + result)
        else:
            print('Fail: result = ' + result + ', expect = ' + expect)
    
    def runTests(self):
        self.testSimplifyPath("/abc/../c/././d", "/c/d")
        self.testCd("/a", "/b", "/a/b")
        self.testCd("/foo/bar", "baz", "/foo/bar/baz")
        self.testCd("/foo/../", "./baz", "/baz")
        self.testCd("/", "foo/bar/../../baz", "/baz")
        self.testCd("/", "..", "Null")
        self.testCd("/a/../..", "b", "Null")
        self.testCd("/a/", "/b/../..", "Null")

        soft_links = {"/foo/bar": "/abc"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "/abc/baz")

        soft_links = {"/foo/bar": "/abc", "/abc": "/bcd", "/bcd/baz": "/xyz"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "/xyz")

        # cd(/foo/bar, baz, {/foo/bar: /abc, /foo/bar/baz: xyz}) = xyz
        soft_links = {"/foo/bar": "/abc", "/foo/bar/baz": "xyz"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "xyz")

        soft_links = {"/foo/bar": "/abc", "A": "B", "/abc": "/foo/bar", "B": "A"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected")

        soft_links = {"/foo/bar": "/abc", "/abc": "/d", "/d": "/foo/bar", "B": "A"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected")

        soft_links = {"A": "B", "B": "A"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected")

        soft_links = {"A": "A", "B": "C"}
        self.testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected")

if __name__ == "__main__":
    test = SolutionTest()
    test.runTests()
