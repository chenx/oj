#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>

using namespace std;

bool VERBOSE = false;

class Solution {
public:
    string cd_with_softlinks(string current_dir, string new_dir, unordered_map<string, string>& soft_links) {
        if (detectCycle(soft_links)) {
            // cout << "Cycle detected in soft_links dictionary" << endl;
            return "Cycle Detected";
        }

        // Find long match.
        string result = cd(current_dir, new_dir);
        if (soft_links.count(result) > 0) {
            if (VERBOSE) cout << "found long match" << endl;
            while (soft_links.count(result) > 0) {
                result = soft_links[result];
            }
            return result;
        }

        if (VERBOSE) cout << "NOT found long match" << endl;
        // There is no long match.
        while (soft_links.count(current_dir) > 0) {
            if (VERBOSE) cout << "found softlink: " << current_dir << " -> " << soft_links[current_dir] << endl;
            current_dir = soft_links[current_dir];
        }
        while (soft_links.count(new_dir) > 0) {
            if (VERBOSE) cout << "found softlink: " << new_dir << " -> " << soft_links[new_dir] << endl;
            new_dir = soft_links[new_dir];
        }

        result = cd(current_dir, new_dir);
        while (soft_links.count(result) > 0) {
            result = soft_links[result];
        }
        return result;
    }

    string cd(string current_dir, string new_dir) {
        try {
            current_dir = simplifyPath(current_dir);
            new_dir = simplifyPath(new_dir);
        } catch (const exception& ex) {
            return "Null";
        }

        if (current_dir == "/" && new_dir == "/") {
            return "/";
        } else if (current_dir == "/") {
            return new_dir;
        } else if (new_dir == "/") {
            return current_dir;
        } else {
            return current_dir + new_dir;
        }
    }

private:
    bool detectCycle(unordered_map<string, string>& soft_links) {
        unordered_map<string, string> inDegree, outDegree;
        unordered_set<string> links;
        for (const auto& item : soft_links) {
            string in = item.first, out = item.second;
            inDegree[out] = in;
            outDegree[in] = out;
            links.insert(in);
            links.insert(out);
        }

        queue<string> q;
        for (string link : links) {
            if (inDegree.count(link) == 0) {
                q.push(link);
            }
        }

        while (! q.empty()) {
            string link = q.front();
            q.pop();

            links.erase(link);

            if (outDegree.count(link) > 0) {
                string nextLink = outDegree[link];
                q.push(nextLink);
            }
        }

        if (! links.empty()) {
            if (true) {
                cout << "Cycle detected: ";
                for (string link : links) cout << link << " ";
                cout << endl;
            }
            return true;
        }
        return false;
    }

    string simplifyPath(string path) {
        vector<string> st;
        string cur;
        for (char c : path) {
            if (c == '/') process(st, cur);
            else cur += c;
        }
        process(st, cur);

        string ans = "/";
        for (auto& s : st) {
            if (ans != "/") ans += "/";
            ans += s;
        }
        return ans;
    }

    void process(vector<string>& st, string& cur) {
        if (cur.empty() || cur == ".") {
            // do nothing.
        } else if (cur == "..") {
            if (!st.empty()) st.pop_back();
            else throw exception();
        } else {
            st.push_back(cur);  // add new directory.
        }
        cur = "";
    }
};

void test(string cur_dir, string new_dir, string expect) {
    Solution so;
    string result = so.cd(cur_dir, new_dir);
    if (result == expect) {
        cout << "Pass: " << "cd(" << cur_dir << ", " << new_dir << ") = " << result << endl;
    } else {
        cout << "Fail: " << "cd(" << cur_dir << ", " << new_dir << ") = " << result << ", expect: " << expect << endl;
    }
    cout << endl;
}

string print_soft_links(unordered_map<string, string>& soft_links) {
    string result = "{";
    int i = 0;
    for (const auto& item : soft_links) {
        if (i ++ > 0) result += ", ";
        result += item.first + ": " + item.second;
    }
    result += "}";
    return result;
}

void test_soft_links(string cur_dir, string new_dir, unordered_map<string, string>& soft_links, string expect) {
    Solution so;
    string result = so.cd_with_softlinks(cur_dir, new_dir, soft_links);
    string soft_links_str = print_soft_links(soft_links);
    if (result == expect) {
        cout << "Pass: " << "cd(" << cur_dir << ", " << new_dir << ", " << soft_links_str << ") = " << result << endl;
    } else {
        cout << "Fail: " << "cd(" << cur_dir << ", " << new_dir << ", " << soft_links_str << ") = " << result << ", expect: " << expect << endl;
    }
    cout << endl;
}

void run_tests() {
    // cd(/foo/bar, baz) = /foo/bar/baz
    test("/foo/bar", "baz", "/foo/bar/baz");

    // cd(/foo/../, ./baz) = /baz
    test("/foo/../", "./baz", "/baz");

    // cd(/, foo/bar/../baz) = /baz
    test("/", "foo/bar/../../baz", "/baz");

    // cd(/, ..) = Null
    test("/", "..", "Null");


    unordered_map<string, string> soft_links;

    // cd(/foo/bar, baz, {/foo/bar: /abc}) = /abc/baz
    soft_links = {{"/foo/bar", "/abc"}};
    test_soft_links("/foo/bar", "baz", soft_links, "/abc/baz");

    // cd(/foo/bar, baz, {/foo/bar: /abc, /abc: /bcd, /bcd/baz: /xyz}) = /xyz
    soft_links = {{"/foo/bar", "/abc"}, {"/abc", "/bcd"}, {"/bcd/baz", "/xyz"}};
    test_soft_links("/foo/bar", "baz", soft_links, "/xyz");

    // cd(/foo/bar, baz, {/foo/bar: /abc, /foo/bar/baz: xyz}) = xyz
    soft_links = {{"/foo/bar", "/abc"}, {"/foo/bar/baz", "xyz"}};
    test_soft_links("/foo/bar", "baz", soft_links, "xyz");

    soft_links = {{"/foo/bar", "/abc"}, {"A", "B"}, {"/abc", "/foo/bar"}, {"B", "A"}};
    test_soft_links("/foo/bar", "baz", soft_links, "Cycle Detected");

    soft_links = {{"/foo/bar", "/abc"}, {"/abc", "/d"}, {"/d", "/foo/bar"}, {"B", "A"}};
    test_soft_links("/foo/bar", "baz", soft_links, "Cycle Detected");

    soft_links = {{"A", "B"}, {"B", "A"}};
    test_soft_links("/foo/bar", "baz", soft_links, "Cycle Detected");
}

int main() {
    run_tests();
    return 0;
}
