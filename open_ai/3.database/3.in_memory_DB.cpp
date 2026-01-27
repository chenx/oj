#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

bool VERBOSE = true;

class Database {
private:
    unordered_map<string, int> tableRowMaxId; // <table_name, row_max_id>
    unordered_map<string, unordered_map<int, vector<string>>> tables; // <table_name, <row_id, rows>>
    unordered_map<string, vector<string>> tableColumns;  // <table_name, column_names>

public:
    Database(vector<string>& names, vector<vector<string>>& columns) {
        for (int i = 0; i < names.size(); i++) {
            tables[names[i]] = unordered_map<int, vector<string>>();
            tableRowMaxId[names[i]] = 0;
            tableColumns[names[i]] = columns[i];
        }
    }

    bool insert(string name, vector<string> row) {
        // cout << "ins(" << name << "), row.size: " << row.size() << endl;
        if (! tables.count(name) || ! tableRowMaxId.count(name)) return false;
        if (tableColumns[name].size() != row.size()) return false;
        
        int rowId = ++ tableRowMaxId[name];
        tables[name][rowId] = row;
        return true;
    }
    
    void remove(string name, int rowId) {
        // cout << "rmv(" << name << "): rowId: " << rowId << endl;
        if (! tables.count(name)) return;
        tables[name].erase(rowId);
    }

    // where - may contains multiple conditions separated by AND/OR and comparison oprators (>, =, <).
    // order - sort by single or multiple columns
    vector<pair<int, vector<string>>> select(string name, string where = "", string orderBy = "") {
        vector<pair<int, vector<string>>> result; // rows[ <row_id, columns> ]
        if (!tables.count(name)) return result;

        if (VERBOSE) {
            cout << "SELECT * FROM " << name << (where == "" ? "" : (" WHERE " + where)) << (orderBy == "" ? "" : (" ORDER BY " + orderBy)) << endl;
        }
        handleWhere(result, name, where);
        handleOrderBy(result, name, orderBy);
        
        return result;
    }

    void show(string name, vector<pair<int, vector<string>>> rows) {
        cout << "Table: " << name << endl;
        for (const auto row : rows) {
            cout << row.first << ". " << join(row.second, ",") << endl;
        }
        cout << endl;
    }

private:

    void handleWhere(vector<pair<int, vector<string>>>& result, string& name, string& where) {
        if (where == "") {
            for (auto& row : tables[name]) {
                result.push_back({row.first, row.second});
            }
            return;
        }

        // E.g., where: "A > 1 AND B < 2"
        // if (VERBOSE) cout << "WHERE " << where << endl;
        vector<string> fields = split(where, ' ');
        vector<vector<string>> conditions;
        for (int i = 0, len = fields.size(); i < len; ) {
            if (i == 0) {
                conditions.push_back({fields[i], fields[i + 1], fields[i + 2]});
                // cout << "cond: " << fields[i] << " " << fields[i + 1] << " " << fields[i + 2] << endl;
                i += 3;
            } else {
                conditions.push_back({fields[i + 1], fields[i + 2], fields[i + 3], fields[i]});
                // cout << "cond: " << fields[i] << " " << fields[i + 1] << " " << fields[i + 2] << " " << fields[i + 3] << endl;
                i += 4;
            }
        }

        for (auto& row : tables[name]) {
            bool include = true;
            for (int i = 0; i < conditions.size(); ++ i) {
                auto cond = conditions[i];

                int index = getTableColumnIndex(name, cond[0]);
                if (index == -1) throw exception();
                // cout << row.second[index] << " " << cond[0] << " " << cond[1] << " " << cond[2] << endl;

                bool newCond = ((cond[1] == "<" && strcmp(row.second[index].c_str(), cond[2].c_str()) < 0) ||
                    (cond[1] == ">" && strcmp(row.second[index].c_str(), cond[2].c_str()) > 0) ||
                    (cond[1] == "=" && strcmp(row.second[index].c_str(), cond[2].c_str()) == 0));

                if (i == 0) {
                    include = newCond;
                } else {
                    if (cond[3] == "AND") include = include && newCond; 
                    else include = include || newCond; // OR
                }
            }
            if (! include) continue;

            result.push_back({row.first, row.second});
        }
    }

    void handleOrderBy(vector<pair<int, vector<string>>>& result, string& name, string& orderBy) {
        vector<string> orderByFields = split(orderBy, ',');
        vector<pair<int, string>> indexes; // <fieldName ASC|DESC>
        for (auto field : orderByFields)
        {
            vector<string> fieldPair = split(field, ' ');
            int index = getTableColumnIndex(name, fieldPair[0]);
            if (index == -1)
                throw exception();
            // cout << "fieldPair[1] = " << fieldPair[1] << endl;
            indexes.push_back({index, fieldPair[1]});
        }
        auto comp = [&](pair<int, vector<string>> &a, pair<int, vector<string>> &b)
        {
            for (int i = 0, len = indexes.size(); i < len; ++i)
            {
                int index = indexes[i].first;
                if (a.second[index] != b.second[index])
                {
                    return indexes[i].second == "DESC" ?
                         a.second[index] > b.second[index] :
                         a.second[index] < b.second[index];
                }
            }
            return a.first < b.first; // fall back to order by row ID.
        };
        sort(result.begin(), result.end(), comp);
    }

    int getTableColumnIndex(string name, string columnName) {
        if (! tableColumns.count(name)) return -1;
        for (int i = 0; i < tableColumns[name].size(); ++ i) {
            if (tableColumns[name][i] == columnName) return i;
        }
        return -1;
    }

    string join(const vector<string>& vec, string delimiter = ",") {
        string result;
        for (auto val : vec) {
            if (result != "") result += ",";
            result += val;
        }
        return result;
    }

    vector<string> split(string s, char delimiter) {
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
public:
    void test() {
        cout << "test" << endl;
        vector<string> names = {"Users", "Orders"};
        vector<vector<string>> columns = {
            {"firstName", "lastName", "age"},
            {"orderId", "productId", "orderData"}
        };

        Database db(names, columns);
        db.insert("Users", {"Alice", "Z", "30"});
        db.insert("Users", {"Carol", "E", "40"});
        db.insert("Users", {"Bob", "D2", "40"});
        db.insert("Users", {"Bob", "D1", "40"});
        db.insert("Users", {"Bob", "D1", "10"});

        db.show("Users", db.select("Users"));
        db.show("Orders", db.select("Orders"));

        // Test orderBy.
        db.show("Users", db.select("Users", "", "firstName,lastName,age"));
        db.show("Users", db.select("Users", "", "firstName ASC,lastName DESC,age"));
        db.show("Users", db.select("Users", "", "firstName ASC,lastName DESC,age DESC"));

        // Test where.
        db.show("Users", db.select("Users", "firstName = Alice"));
        db.show("Users", db.select("Users", "firstName > Alice"));
        db.show("Users", db.select("Users", "firstName > Alice AND age = 10"));
        db.show("Users", db.select("Users", "firstName < Alice"));
        db.show("Users", db.select("Users", "firstName = Alice OR age = 10"));

        // Test both where and orderBy.
        db.show("Users", db.select("Users", "firstName = Alice OR age = 10", "age"));
    }
};

int main() {
    DatabaseTest dbTest;
    dbTest.test();
    return 0;
}

/**
Test output:

SELECT * FROM Users
Table: Users
1. Alice,Z,30
2. Carol,E,40
3. Bob,D2,40
4. Bob,D1,40
5. Bob,D1,10

SELECT * FROM Orders
Table: Orders

SELECT * FROM Users ORDER BY firstName,lastName,age
Table: Users
1. Alice,Z,30
5. Bob,D1,10
4. Bob,D1,40
3. Bob,D2,40
2. Carol,E,40

SELECT * FROM Users ORDER BY firstName ASC,lastName DESC,age
Table: Users
1. Alice,Z,30
3. Bob,D2,40
5. Bob,D1,10
4. Bob,D1,40
2. Carol,E,40

SELECT * FROM Users ORDER BY firstName ASC,lastName DESC,age DESC
Table: Users
1. Alice,Z,30
3. Bob,D2,40
4. Bob,D1,40
5. Bob,D1,10
2. Carol,E,40

SELECT * FROM Users WHERE firstName = Alice
Table: Users
1. Alice,Z,30

SELECT * FROM Users WHERE firstName > Alice
Table: Users
2. Carol,E,40
3. Bob,D2,40
4. Bob,D1,40
5. Bob,D1,10

SELECT * FROM Users WHERE firstName > Alice AND age = 10
Table: Users
5. Bob,D1,10

SELECT * FROM Users WHERE firstName < Alice
Table: Users

SELECT * FROM Users WHERE firstName = Alice OR age = 10
Table: Users
1. Alice,Z,30
5. Bob,D1,10

SELECT * FROM Users WHERE firstName = Alice OR age = 10 ORDER BY age
Table: Users
5. Bob,D1,10
1. Alice,Z,30
 */

/**
 * Reference: https://github.com/chenx/oj/blob/master/leetcode/2408.DesignSQL.cpp
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
