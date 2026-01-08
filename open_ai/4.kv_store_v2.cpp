// 6:10 - 6:20 : 10:00
// 7:05 - 7:50 : 45:00
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class KvStore {
private:
    unordered_map<string, map<int, string>> store;

public:
    KvStore() {}

    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto floorKey = store[key].upper_bound(timestamp);

        if (floorKey != store[key].begin()) {
            -- floorKey;
            return floorKey->second;
        }
        return "";
    }

    string serialize() {
        string s;
        for (auto& item : store) {
            string key = item.first;
            auto mapItem = item.second;
            for (auto& entry : mapItem) {
                string timestamp = to_string(entry.first);
                string val = entry.second;
                s += to_string(key.length()) + ":" + key + 
                    to_string(timestamp.length()) + ":" + timestamp + 
                    to_string(val.length()) + ":" + val;
            }
        }
        return s;
    }

    vector<vector<string>> deserialization(string s) {
        vector<vector<string>> result;

        int index = 0, offset = 0;
        string key, timestamp, value;
        while (true) {
            if (! getNextToken(s, index, offset, key)) break;
            if (! getNextToken(s, index, offset, timestamp)) break;
            if (! getNextToken(s, index, offset, value)) break;
            result.push_back({key, timestamp, value});

            // cout << "key: " << key << ", timestamp: " << timestamp << ", value: " << value << endl;
        }

        return result;
    }

    bool getNextToken(string& s, int& index, int& offset, string& output) {
        if ((index = s.find(":", offset)) == string::npos) return false;

        int len = stoi(s.substr(offset, index));
        output = s.substr(index + 1, len);
        offset = index + 1 + len;
        return true;
    } 
};

class KvStoreTest {
    void assert(string result, string expect) {
        if (result == expect) {
            cout << "Pass: result = " << result << endl;
        } else {
            cout << "Pass: result = " << result << ", expect = " << expect << endl;
        }
    }

    void assert2(vector<vector<string>> result, vector<vector<string>> expect) {
        if (result == expect) {
            cout << "Pass: result = " << dump(result) << endl;
        } else {
            cout << "Pass: result = " << dump(result) << ", expect = " << dump(expect) << endl;
        }
    }

    string dump(vector<vector<string>>& vec) {
        string result;
        for (auto row : vec) {
            result += "[";
            for (auto v : row) {
                result += v + " ";
            }
            result += "] ";
        }
        return "[" + result + "]";
    }

    void testSetGet() {
        KvStore store;

        store.set("k1", "v1", 10);
        string result = store.get("k1", 11);
        assert(result, "v1");

        store.set("k1", "v2", 15);
        result = store.get("k1", 20);
        assert(result, "v2");
    }

    void testSerialization() {
        KvStore store;

        store.set("k1", "v1", 10);
        store.set("k1", "v2", 15);

        string result = store.serialize();
        assert(result, "2:k12:102:v12:k12:152:v2");
    }

    void testDeserialization() {
        KvStore store;
        auto result = store.deserialization("2:k12:102:v12:k12:152:v2");
        vector<vector<string>> expect = {
            {"k1", "10", "v1"},
            {"k1", "15", "v2"}
        };
        assert2(result, expect);
    }
public:
    void run_tests() {
        testSetGet();
        testSerialization();
        testDeserialization();
    }
};

int main() {
    KvStoreTest test;
    test.run_tests();
    return 0;
}
