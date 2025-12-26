#include <iostream>
#include <map>

using namespace std;

class KvStoreSerializeDeserialize {
public:
    KvStoreSerializeDeserialize() {}

    string serialize(map<string, string>& kv) {
        string result;
        for (const auto& item : kv) {
            // if (result != "") result += ";"; // no needed for this separator.
            result += to_string(item.first.length()) + ":" + item.first +
                      to_string(item.second.length()) + ":" + item.second;
        }
        return result;
    }

    map<string, string> deserialize(string& s) {
        map<string, string> result;

        int offset = 0, index = 0;
        while ((index = s.find(":", offset)) != string::npos) {
            int keyLen = stoi(s.substr(offset, index - offset));
            string key = s.substr(index + 1, keyLen);
            // cout << "key: " << key << endl; // "1:A3:1232:B24:4567" => 1:A

            offset = index + 1 + keyLen;
            index = s.find(":", offset); // 3:123
            if (index == string::npos) {
                cout << "error" << endl;
                throw invalid_argument("error: cannot find value. index = " + to_string(index));
            }
            int valueLen = stoi(s.substr(offset, index - offset)); // 3:123
            string value = s.substr(index + 1, valueLen);
            // cout << "value: " << value << endl;

            result[key] = value;

            offset = index + 1 + valueLen;
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
