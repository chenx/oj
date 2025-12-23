// Reference: https://algo.monster/liteproblems/2408
class SQL {
    unordered_map<string, int> tableRowId;
    unordered_map<string, unordered_map<int, vector<string>>> tables;
    unordered_map<string, int> tableColumns;

public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < names.size(); i++) {
            tables[names[i]] = unordered_map<int, vector<string>>();
            tableRowId[names[i]] = 0;
            tableColumns[names[i]] = columns[i];
        }
    }
    
    bool ins(string name, vector<string> row) {
        // cout << "ins(" << name << "), row.size: " << row.size() << endl;
        if (! tables.contains(name) || ! tableRowId.contains(name)) return false;
        if (tableColumns[name] != row.size()) return false;
        
        int rowId = ++ tableRowId[name];
        tables[name][rowId] = row;
        return true;
    }
    
    void rmv(string name, int rowId) {
        // cout << "rmv(" << name << "): rowId: " << rowId << endl;
        if (! tables.contains(name)) return;
        tables[name].erase(rowId);
    }
    
    string sel(string name, int rowId, int columnId) {
        // cout << "sel(" << name << "): rowId: " << rowId << "， columnId: " << columnId << endl;
        if (!tables.contains(name)) return "<null>";
        if (!tables[name].contains(rowId)) return "<null>";
        if (columnId < 1 || columnId > tableColumns[name]) return "<null>";
        
        // cout << "sel return: " << tables[name][rowId][columnId - 1] << endl;
        return tables[name][rowId][columnId - 1];
    }
    
    vector<string> exp(string name) {
        if (! tables.contains(name)) return vector<string>();

        vector<string> result;
        for (auto [id, row] : tables[name]) {
            result.push_back(to_string(id) + "," + join(row));
        }
        return result;
    }

    string join(vector<string>& vec, string delimiter = ",") {
        string result;
        for (auto val : vec) {
            if (result != "") result += ",";
            result += val;
        }
        return result;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */


/**
2408. Design SQL
Medium

You are given two string arrays, names and columns, both of size n. The ith table is represented by the name names[i] 
and contains columns[i] number of columns.

You need to implement a class that supports the following operations:

    Insert a row in a specific table with an id assigned using an auto-increment method, where the id of the first 
        inserted row is 1, and the id of each new row inserted into the same table is one greater than the id of the 
        last inserted row, even if the last row was removed.
    Remove a row from a specific table. Removing a row does not affect the id of the next inserted row.
    Select a specific cell from any table and return its value.
    Export all rows from any table in csv format.

Implement the SQL class:

    SQL(String[] names, int[] columns)
        Creates the n tables.
    bool ins(String name, String[] row)
        Inserts row into the table name and returns true.
        If row.length does not match the expected number of columns, or name is not a valid table, returns false 
            without any insertion.
    void rmv(String name, int rowId)
        Removes the row rowId from the table name.
        If name is not a valid table or there is no row with id rowId, no removal is performed.
    String sel(String name, int rowId, int columnId)
        Returns the value of the cell at the specified rowId and columnId in the table name.
        If name is not a valid table, or the cell (rowId, columnId) is invalid, returns "<null>".
    String[] exp(String name)
        Returns the rows present in the table name.
        If name is not a valid table, returns an empty array. Each row is represented as a string, with each cell 
            value (including the row's id) separated by a ",".

 

Example 1:

Input:

["SQL","ins","sel","ins","exp","rmv","sel","exp"]
[[["one","two","three"],[2,3,1]],["two",["first","second","third"]],["two",1,3],["two",["fourth","fifth","sixth"]],
  ["two"],["two",1],["two",2,2],["two"]]

Output:

[null,true,"third",true,["1,first,second,third","2,fourth,fifth,sixth"],null,"fifth",["2,fourth,fifth,sixth"]]

Explanation:

// Creates three tables.
SQL sql = new SQL(["one", "two", "three"], [2, 3, 1]);

// Adds a row to the table "two" with id 1. Returns True.
sql.ins("two", ["first", "second", "third"]);

// Returns the value "third" from the third column
// in the row with id 1 of the table "two".
sql.sel("two", 1, 3);

// Adds another row to the table "two" with id 2. Returns True.
sql.ins("two", ["fourth", "fifth", "sixth"]);

// Exports the rows of the table "two".
// Currently, the table has 2 rows with ids 1 and 2.
sql.exp("two");

// Removes the first row of the table "two". Note that the second row
// will still have the id 2.
sql.rmv("two", 1);

// Returns the value "fifth" from the second column
// in the row with id 2 of the table "two".
sql.sel("two", 2, 2);

// Exports the rows of the table "two".
// Currently, the table has 1 row with id 2.
sql.exp("two");

Example 2:

Input:

["SQL","ins","sel","rmv","sel","ins","ins"]
[[["one","two","three"],[2,3,1]],["two",["first","second","third"]],["two",1,3],["two",1],["two",1,2],
  ["two",["fourth","fifth"]],["two",["fourth","fifth","sixth"]]]

Output:

[null,true,"third",null,"<null>",false,true]

Explanation:

// Creates three tables.
SQL sQL = new SQL(["one", "two", "three"], [2, 3, 1]); 

// Adds a row to the table "two" with id 1. Returns True. 
sQL.ins("two", ["first", "second", "third"]); 

// Returns the value "third" from the third column 
// in the row with id 1 of the table "two".
sQL.sel("two", 1, 3); 

// Removes the first row of the table "two".
sQL.rmv("two", 1); 

// Returns "<null>" as the cell with id 1 
// has been removed from table "two".
sQL.sel("two", 1, 2); 

// Returns False as number of columns are not correct.
sQL.ins("two", ["fourth", "fifth"]); 

// Adds a row to the table "two" with id 2. Returns True.
sQL.ins("two", ["fourth", "fifth", "sixth"]); 

 */
