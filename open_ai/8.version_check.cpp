#include <iostream>
#include <sstream>

using namespace std;

class DependencyVersionCheck {
    vector<vector<int>> versions;
public:
    DependencyVersionCheck() {}

    void setVersions(vector<string> inputVersions) {
        versions.clear();
        for (const string& version : inputVersions) {
            auto segments = split(version);
            versions.push_back({stoi(segments[0]), stoi(segments[1]), stoi(segments[2])});
        }

        auto comp = [&](const vector<int>& a, const vector<int>& b) {
            int len = a.size();
            for (int i = 0; i < len; ++ i) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }
            return false;
        };
        sort(versions.begin(), versions.end(), comp);
        dump();
    }

private:
    void dump() {
        cout << "=> dump: " << endl;
        for (auto version: versions) {
            cout << version[0] << "." << version[1] << "." << version[2] << endl;
        }
        cout << endl;
    }

    vector<string> split(const string& s, char delimiter = '.') {
        stringstream ss(s);
        string out;
        vector<string> result;

        while (getline(ss, out, delimiter)) {
            result.push_back(out);
        }
        return result;
    }
};

class DependencyVersionCheckTest {
public:
    void test() {
        cout << "hi" << endl;
        DependencyVersionCheck dvc;
        
        vector<string> versions = {"103.003.02", "103.003.03", "203.003.02"};
        dvc.setVersions(versions);
    }
};

int main() {
    DependencyVersionCheckTest dvcTest;
    dvcTest.test();
    return 0;
}


/**
Part 1:
You are given a list of dependency versions, e.g., [103.003.02, 103.003.03, 203.003.02].
Each version may support or not support a specific feature.

Task: Find the earliest version that supports the current feature.

Part 2:
Multiple corner test cases are provided.
Some test cases may reveal additional requirements that invalidate initial assumptions.

Example: The first case may show that version 103.003.02 supports the feature, but the next version 103.003.03 does not.

You need to analyze the test data, identify new requirements, and confirm them with the interviewer.
Each test case can introduce new constraints, so careful observation of the data is required.

Key Points:
- Initial implementation: Find earliest supporting version based on given list.
- Iterative refinement: Each test case may reveal exceptions or new rules, requiring hypothesis adjustment.
- Observation-driven logic: Must carefully examine the data and dynamically adjust assumptions.
- Version comparison: Properly parse and compare version numbers (consider major/minor/patch).
 */
