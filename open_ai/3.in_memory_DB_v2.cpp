// 12:15 - 12:27: 0:12
//  1:01 - 1:44: 00:43
//  1:44 - 2:07: 00:23
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Database {
private:
    unordered_map<string, int> tableRowMaxId; // <tableName, rowMaxId>
    unordered_map<string, unordered_map<int, vector<string>>> tables; // <tableName, <rowId, row>>
    unordered_map<string, vector<string>> tableColumns; // <tableName, columns>

public:
    Database(vector<string>& names, vector<vector<string>>& columns) {
        int n = names.size();
        for (int i = 0; i < n; ++ i) {
            string tableName = names[i];
            tableRowMaxId[tableName] = 0;
            tableColumns[tableName] = columns[i];
        }
    }

    void insert(string tableName, vector<string>& row) {
        int rowId = ++ tableRowMaxId[tableName];
        tables[tableName][rowId] = row;
    }

    void remove(string tableName, int rowId) {
        tables[tableName].erase(rowId);
    }

    vector<pair<int, vector<string>>> select(string tableName, string where = "", string orderBy = "") {
        vector<pair<int, vector<string>>> result;
        handleWhere(result, tableName, where);
        handleOrderBy(result, tableName, orderBy);
        return result;
    }

    void dump(string tableName, vector<pair<int, vector<string>>>& result) {
        cout << "table: " << tableName << endl;
        for (auto row : result) {
            cout << row.first << ": ";
            for (auto field : row.second) {
                cout << field << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    // where: where, multi-column where. AND logic. columnName >|=|< value
    // e.g., name = 'alice' AND age = '15'
    void handleWhere(vector<pair<int, vector<string>>>& result, string& tableName, string& where) {
        vector<string> tokens = split(where);
        for (auto& row : tables[tableName]) {
            if (whereIsTrueAndOr(tableName, tokens, row.second)) {
                result.push_back({row.first, row.second});
            }
        }
    }

    bool whereIsTrueAndOnly(string& tableName, vector<string>& tokens, vector<string>& row) {
        if (tokens.empty()) return true;

        for (int i = 0; i < tokens.size(); i += 3) {
            if (i > 0) i += 1;

            string field = tokens[i];
            int fieldIndex = getFieldIndex(tableName, field);
            string fieldValue = row[fieldIndex];
            string op = tokens[i+1];
            string val = tokens[i+2];

            if (op == "=" && fieldValue != val) return false;
            if (op == ">" && strcmp(fieldValue.c_str(), val.c_str()) <= 0) return false;
            if (op == "<" && strcmp(fieldValue.c_str(), val.c_str()) >= 0) return false;
        }
        return true;
    }

    bool whereIsTrueAndOr(string& tableName, vector<string>& tokens, vector<string>& row) {
        if (tokens.empty()) return true;

        bool cond = true;
        string logicOp;
        for (int i = 0; i < tokens.size(); i += 3) {
            if (i > 0) {
                logicOp = tokens[i ++]; // AND or OR
            }

            string field = tokens[i];
            int fieldIndex = getFieldIndex(tableName, field);
            string fieldValue = row[fieldIndex];
            string op = tokens[i+1];
            string val = tokens[i+2];

            bool logicValue = (op == "=" && fieldValue == val) ||
                (op == ">" && strcmp(fieldValue.c_str(), val.c_str()) > 0) ||
                (op == "<" && strcmp(fieldValue.c_str(), val.c_str()) < 0);
            
            if (logicOp != "") {
                if (logicOp == "AND") cond = cond && logicValue;
                else cond = cond || logicValue; // OR
            } else {
                cond = logicValue;
            }
        }
        return cond;
    }

    int getFieldIndex(string& tableName, string& field) {
        for (int j = 0; j < tableColumns[tableName].size(); ++j) {
            if (field == tableColumns[tableName][j]) {
                return j;
            }
        }
        throw invalid_argument("invalid field: " + field);
    }

    // e.g., orderBy name,age, orderBy name ASC,age DESC
    void handleOrderByAscOnly(vector<pair<int, vector<string>>>& result, string& tableName, string& orderBy) {
        vector<string> orderFields = split(orderBy, ',');
        auto comp = [&](pair<int, vector<string>>& a, pair<int, vector<string>>& b){
            for (string& field : orderFields) {
                int fieldIndex = getFieldIndex(tableName, field);
                string va = a.second[fieldIndex];
                string vb = b.second[fieldIndex];

                if (va != vb) return va < vb;
            }
            return a.first < b.first; // order by Id
        };

        sort(result.begin(), result.end(), comp);
    }

    void handleOrderBy(vector<pair<int, vector<string>>>& result, string& tableName, string& orderBy) {
        vector<string> fields = split(orderBy, ',');
        vector<vector<string>> orderFields;
        for (string& field : fields) {
            vector<string> item = split(field, ' ');
            if (item.size() == 1) item.push_back("ASC");
            orderFields.push_back(item);
        }
        auto comp = [&](pair<int, vector<string>>& a, pair<int, vector<string>>& b){
            for (auto& field : orderFields) {
                int fieldIndex = getFieldIndex(tableName, field[0]);
                string va = a.second[fieldIndex];
                string vb = b.second[fieldIndex];

                if (va != vb) {
                    if (field[1] == "ASC") {
                        return va < vb;
                    } else { // DESC
                        return va > vb;
                    }
                } 
            }
            return a.first < b.first; // order by Id
        };

        sort(result.begin(), result.end(), comp);
    }

    vector<string> split(string& s, char delimiter = ' ') {
        vector<string> result;
        stringstream ss(s);
        string out;
        while (getline(ss, out, delimiter)) {
            result.push_back(out);
        }
        return result;
    }
};

class DatabaseTest {
private:
    void test() {
        cout << "hi" << endl;
        vector<string> names = {"User", "Product"};
        vector<vector<string>> columns = {
            {"name", "age"},
            {"productName", "price"}
        };
        Database db(names, columns);

        vector<string> row = {"Alice", "29"};
        db.insert("User", row);
        row = {"Bob", "30"};
        db.insert("User", row);
        row = {"Carol", "28"};
        db.insert("User", row);
        row = {"Doug", "28"};
        db.insert("User", row);

        auto result = db.select("User");
        db.dump( "select from User", result );

        result = db.select("User", "name = Alice");
        db.dump( "select from User where name = Alice", result );

        result = db.select("User", "name = Alice OR age = 28");
        db.dump( "select from User where name = Alice", result );

        result = db.select("User", "", "age");
        db.dump( "select from User orderBy age", result );

        result = db.select("User", "", "age DESC");
        db.dump( "select from User orderBy age", result );

        result = db.select("User", "", "age DESC,name DESC");
        db.dump( "select from User orderBy age", result );
    }
public:
    void run_tests() {
        test();
    }
};

int main() {
    DatabaseTest dbTest;
    dbTest.run_tests();
    return 0;
}


/**
 * See: https://github.com/chenx/oj/blob/master/leetcode/2408.DesignSQL.cpp
 * 
 * Prompt: Implement an in-memory database 
 * supporting insert and query. Queries must support where filtering and order by sorting. 
 * Provide a select(table_name, where=None, order_by=None) interface. Multiple where conditions only
 * support AND logic. Implement queries with where, multi-column where, where with single-column sort, 
 * where with multi-column sort. The same API must be used, and input parameters should ensure backward 
 * compatibility.
 *
 * Original requirements: Simulate SQL using a map. 
 * - Create tables based on column name lists. 
 * - Implement add row, query by single or multiple columns (supporting AND/OR), 
 * - support comparison operators (>, <), and order by. 
 *
 * No need to parse SQL; just provide APIs with the required functionality.
 *
 * Key points: When where is empty, return all matching entries (or empty list if none).
 */
