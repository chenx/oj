// 5:26 - 6:06
// 6:40 - 6:52
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        string token;
        stringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // do nothing
            } else if (token == "..") {
                if (! tokens.empty()) tokens.pop_back();
                else return "Null";
            } else {
                tokens.push_back(token);
            }
        }

        string result = "/";
        for (string token : tokens) {
            if (result != "/") result += "/";
            result += token;
        }
        return result;
    }

    string cd(string current_dir, string new_dir, unordered_map<string, string>& soft_links) {
        if (hasCycle(soft_links)) {
            return "Cycle Detected";
        }

        string result = simplifyPath(current_dir + "/" + new_dir);
        if (soft_links.count(result)) { // has long match.
            while (soft_links.count(result)) {
                result = soft_links[result];
            }
            return result;
        }

        // no long match
        while (soft_links.count(current_dir)) {
            current_dir = soft_links[current_dir];
        }
        while (soft_links.count(new_dir)) {
            new_dir = soft_links[new_dir];
        }
        result = simplifyPath(current_dir + "/" + new_dir);
        while (soft_links.count(result)) {
            result = soft_links[result];
        }
        return result;
    }

    string cd(string current_dir, string new_dir) {
        if (simplifyPath(current_dir) == "Null" || simplifyPath(new_dir) == "Null") {
            return "Null";
        }
        return simplifyPath(current_dir + "/" + new_dir);
    }

private:
    bool hasCycle(unordered_map<string, string>& soft_links) {
        unordered_map<string, set<string>> inDegree, outDegree;
        set<string> links;

        for (auto item : soft_links) {
            inDegree[item.second].insert(item.first);
            outDegree[item.first].insert(item.second);

            links.insert(item.first);
            links.insert(item.second);
        }

        queue<string> q;
        for (string link : links) {
            if (inDegree[link].empty()) {
                q.push(link);
            }
        }

        while (! q.empty()) {
            string link = q.front();
            q.pop();

            links.erase(link);

            for (string nextLink : outDegree[link]) {
                inDegree[nextLink].erase(link);

                if (inDegree[nextLink].empty()) {
                    q.push(nextLink);
                }
            }
        }

        return ! links.empty();
    }
};

class SolutionTest {
private:
    void testCdWithSoftLinks(string current_dir, string new_dir, unordered_map<string, string>& soft_links, string expect) {
        Solution so;
        string result = so.cd(current_dir, new_dir, soft_links);
        
        if (result == expect) {
            cout << "Pass: result = " << result  << endl;
        } else {
            cout << "Fail: result = " << result << ", expect = " << expect << endl;
        }
    }

    void testCd(string current_dir, string new_dir, string expect) {
        Solution so;
        string result = so.cd(current_dir, new_dir);
        
        if (result == expect) {
            cout << "Pass: result = " << result  << endl;
        } else {
            cout << "Fail: result = " << result << ", expect = " << expect << endl;
        }
    }

    void testSimplifyPath(string path, string expect) {
        Solution so;
        string result = so.simplifyPath(path);

        if (result == expect) {
            cout << "Pass: input: " << path << ", result = " << result  << endl;
        } else {
            cout << "Fail: input: " << path << ", result = " << result << ", expect = " << expect << endl;
        }
    }

public:
    void run_tests() {
        testSimplifyPath("/abc/../c/././d", "/c/d");
        testSimplifyPath("/abc/./c/././d", "/abc/c/d");
        testSimplifyPath("/abc/../", "/");

        testCd("/a", "/b", "/a/b");

        // cd(/foo/bar, baz) = /foo/bar/baz
        testCd("/foo/bar", "baz", "/foo/bar/baz");

        // cd(/foo/../, ./baz) = /baz
        testCd("/foo/../", "./baz", "/baz");

        // cd(/, foo/bar/../baz) = /baz
        testCd("/", "foo/bar/../../baz", "/baz");

        // cd(/, ..) = Null
        testCd("/", "..", "Null");

        testCd("/a/", "/b/../..", "Null");

        unordered_map<string, string> soft_links = {{"/foo/bar", "/abc"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "/abc/baz");

        // cd(/foo/bar, baz, {/foo/bar: /abc, /abc: /bcd, /bcd/baz: /xyz}) = /xyz
        soft_links = {{"/foo/bar", "/abc"}, {"/abc", "/bcd"}, {"/bcd/baz", "/xyz"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "/xyz");

        // cd(/foo/bar, baz, {/foo/bar: /abc, /foo/bar/baz: xyz}) = xyz
        soft_links = {{"/foo/bar", "/abc"}, {"/foo/bar/baz", "xyz"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "xyz");

        soft_links = {{"/foo/bar", "/abc"}, {"A", "B"}, {"/abc", "/foo/bar"}, {"B", "A"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected");

        soft_links = {{"/foo/bar", "/abc"}, {"/abc", "/d"}, {"/d", "/foo/bar"}, {"B", "A"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected");

        soft_links = {{"A", "B"}, {"B", "A"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected");

        soft_links = {{"A", "A"}, {"B", "C"}};
        testCdWithSoftLinks("/foo/bar", "baz", soft_links, "Cycle Detected");
    }
};

int main() {
    SolutionTest soTest;
    soTest.run_tests();
    return 0;
}
