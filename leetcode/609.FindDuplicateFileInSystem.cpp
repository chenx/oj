// See: https://leetcode.com/problems/find-duplicate-file-in-system/editorial/
// Time complexity : O(n∗x). n strings of average length x is parsed.
// Space complexity : O(n∗x). map and res size grows upto n∗x.
// 
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> map;

        for (string& path: paths) {
            vector<string> values = split(path, ' '); 
            for (int i = 1; i < values.size(); i++) {
                vector<string> name_cont = split(values[i], '(');
                name_cont[1].pop_back(); // remove last char ')'.
                // name_cont[1] = name_cont[1].substr(0, name_cont[1].length() - 1);
                
                map[name_cont[1]].push_back(values[0] + "/" + name_cont[0]);
            }
        }

        vector<vector<string>> result;
        for (auto [key, val] : map) {
            if (val.size() > 1) result.push_back(val);
        }
        return result;
    }

    vector<string> split(string data, char delim) {
        vector<string> result;
        stringstream ss(data);
        string val;
        while (std::getline(ss, val, delim)) {
            result.push_back(val);
        }
        return result;
    }
};


/**
609. Find Duplicate File in System
Medium

Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

    "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

    "directory_path/file_name.txt"
 */
