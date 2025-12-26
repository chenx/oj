//
// Simplified function deserialize().
//
#include <iostream>
#include <map>

using namespace std;

class KvStoreSerializeDeserialize {
public:
    KvStoreSerializeDeserialize() {}

    string serialize(map<string, string>& kv) {
        string result;
        for (const auto& item : kv) {
            result += to_string(item.first.length()) + ":" + item.first +
                      to_string(item.second.length()) + ":" + item.second;
        }
        return result;
    }

    map<string, string> deserialize(string& s) {
        map<string, string> result;

        int offset = 0, index = 0;
        string key, value;
        bool isKey = true;
        while ((index = s.find(":", offset)) != string::npos) {
            int len = stoi(s.substr(offset, index - offset));

            if (isKey) {
                key = s.substr(index + 1, len);
            } else {
                value = s.substr(index + 1, len);
                result[key] = value;
            }

            offset = index + 1 + len;
            isKey = ! isKey;
        }

        if (! isKey) {
            cout << "=> WARNING: value not found for key: " << key << endl;
        }
        if (offset != s.length()) {
            cout << "=> WARNING: offset(" << offset << ") != s.length()(" << s.length() << ")" << endl;
        }

        return result;
    }
};

class KvStoreSerializeDeserializeTest {
public:
    void test() {
        KvStoreSerializeDeserialize kvStore;
        map<string, string> inputKvMap = {{"A", "123"}, {"B2", "4567"}};
        string serializeResult = kvStore.serialize(inputKvMap);
        string expect = "1:A3:1232:B24:4567";

        if (serializeResult == expect) {
            cout << "Pass: result = " << serializeResult << endl;
        } else {
            cout << "Fail: result = " << serializeResult << ", expect = " << expect << endl;
        }

        map<string, string> deserializeResult = kvStore.deserialize(serializeResult);
        if (deserializeResult == inputKvMap) {
            cout << "Pass: result = " << dumpMap(deserializeResult) << endl;
        } else {
            cout << "Fail: result = " << dumpMap(deserializeResult) << ", expect = " << dumpMap(inputKvMap) << endl;
        }
    }

private:
    string dumpMap(map<string, string>& map) {
        string result;
        for (auto item : map) {
            if (result != "") result += ", ";
            result += "{" + item.first + ", " + item.second + "}";
        }
        return result;
    }
};

int main() {
    KvStoreSerializeDeserializeTest kvTest;
    kvTest.test();
    return 0;
}

/**
Implement serialization and deserialization for a key-value store where both keys and values 
can contain any characters including delimiters. You can't use simple delimiters because they 
might appear in the data. Most candidates land on length-prefix encoding (like 3:key5:value), 
which is the same pattern used in Redis protocol.
 */
