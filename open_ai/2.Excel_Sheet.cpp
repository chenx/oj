#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

bool VERBOSE = false;

vector<string> split(const string& s, char delimiter) {
    stringstream ss(s);
    string out;
    vector<string> result;

    while (getline(ss, out, delimiter)) {
        result.push_back(out);
    }
    return result;
}

string getCellName(vector<int> cell) {
    return string(1, 'A' + cell[1]) + to_string(cell[0] + 1);
}

// Assume column is A-Z only, row starts with 1.
struct Cell {
    Cell(string formula, int value) : formula(formula), val(value) {}

    string formula; // E.g., =A1+B2
    int val;

    vector<vector<int>> parents; // =A1+A2 => {{A, 1}, {A, 2}} => {{0, 0}, {0, 1}}
    // It's possible a formula uses a cell more than once:  =A1+A1+A2, so use a set.
    set<vector<int>> parentSet; // =A1+A2 => {{A, 1}, {A, 2}} => {{0, 0}, {0, 1}}

    void setValue(int value) {
        val = value;
        formula = "";
        parents.clear();
        parentSet.clear();
    }

    void setFormula(string formula) {
        this->formula = formula;
        formula = formula.substr(1); // ignore "="
        vector<string> cells = split(formula, '+');
        parents.clear();
        parentSet.clear();
        for (auto cell : cells) {
            vector<int> item = {cell[1] - '1', cell[0] - 'A'}; // <row, col>
            parents.push_back(item);
            parentSet.insert(item);
        }
    }

    string dumpParents() {
        string result;
        for (auto parent : parents) {
            if (result != "") result += ",";
            result += getCellName(parent);
        }
        return result;
    }
};

class Spreadsheet {
    vector<vector<Cell>> cells;
    int rows, cols;

    // For cyclic update when setting formula.
    stack<vector<int>> stack;

public:
    Spreadsheet(int height, int width) : rows(height), cols(width) {
        cells.resize(height, vector<Cell>(width, Cell("", 0)));
    }

    void setCell(string cellName, string formular) {
        cout << "=> setCell(" << cellName << ", " << formular << ")" << endl;
        int col = cellName[0] - 'A';
        int row = cellName[1] - '1';

        cells[row][col].setFormula(formular);

        if (detectCycle(row, col)) {
            // throw exception();
            throw invalid_argument("setCell(" + cellName + ", " + formular + "): cycle found");
            return;
        }

        // Update value if there are children cells using this cell.
        addChildrenToStack(row, col);
        calcStack();

        if (VERBOSE) dump();
    }

    void setCell(string cellName, int value) {
        cout << "=> setCell(" << cellName << ", " << value << ")" << endl;
        int col = cellName[0] - 'A';
        int row = cellName[1] - '1';

        cells[row][col].setValue(value);
    
        // Update value if there are children cells using this cell.
        addChildrenToStack(row, col);
        calcStack();
        
        if (VERBOSE) dump();
    }

    int getCell(string cellName) {
        int col = cellName[0] - 'A';
        int row = cellName[1] - '1';
        return cells[row][col].val;
    }

    void dump() {
        if (rows == 0 || cols == 0) {
            cout << "(empty)" << endl;
            return;
        }

        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (j > 0) cout << ",\t";
                cout << string(1, 'A' + j) << to_string(i + 1) << " " << cells[i][j].val << " (" << cells[i][j].formula << ")";
                cout << " [" << cells[i][j].dumpParents() << "]";
            }
            cout << endl;
        }
        cout << endl;
    }

private:

    bool detectCycle(int row, int col) {
        // return dfs(row, col, {row, col});
        return bfs(row, col);
    }

    bool bfs(int row, int col) {
        vector<int> start = {row, col};

        queue<vector<int>> q;
        q.push(start);

        while (! q.empty()) {
            int i = q.front()[0], j = q.front()[1];
            q.pop();

            for (auto parent : cells[i][j].parents) {
                if (parent == start) {
                    cout << "===>>> Cycle detected at cell: " << getCellName({i, j}) << endl;
                    return true;
                }
                q.push(parent);
            }
        }
        return false;
    }

    // Another way to detect cycle.
    bool dfs(int row, int col, vector<int> start) {
        for (auto parent : cells[row][col].parents) {
            if (parent == start) {
                cout << "===>>> Cycle detected at cell: " << getCellName({row, col}) << endl;
                return true;
            }
            if (dfs(parent[0], parent[1], start)) return true;
        }
        return false;
    }

    int getSum(int row, int col) {
        int sum = 0;
        for (auto parent : cells[row][col].parents) {
            Cell cell = cells[parent[0]][parent[1]];
            // cout << cell.getCellName(parent) << endl;
            sum += cell.val;
        }
        return sum;
    }

    // Could memorize the children list for the given cell.
    // Then if update a formular of a cell, update its children.
    void addChildrenToStack(int row, int col) {
        if (VERBOSE) cout << "addChildrenToStack: " << getCellName({row, col}) << endl;
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (cells[i][j].parentSet.count({row, col}) > 0) {
                    addChildrenToStack(i, j);
                }
            }
        }
        stack.push({row, col});
    }

    void calcStack() {
        while (! stack.empty()) {
            int row = stack.top()[0], col = stack.top()[1];
            stack.pop();

            if (VERBOSE) cout << "calcStack: " << getCellName({row, col}) << endl;

            if (cells[row][col].formula != "") {
                cells[row][col].val = getSum(row, col);
            }
        }
    }
};

class SpreadsheetTest {
public:
    void test() {
        cout << "test" << endl;
        Spreadsheet spreadsheet(10, 5);
        spreadsheet.dump();

        spreadsheet.setCell("A1", 1);
        spreadsheet.setCell("A2", 2);
        spreadsheet.setCell("A3", "=A1+A2+A1");
        spreadsheet.setCell("A4", "=A3+A2");
        spreadsheet.setCell("A5", "=A3+A4");
        spreadsheet.setCell("B1", "=A1+A2+A3+A4+A5");
        spreadsheet.dump();

        spreadsheet.setCell("A1", 3);
        spreadsheet.dump();

        spreadsheet.setCell("A4", 0);
        spreadsheet.dump();

        spreadsheet.setCell("A4", "=A1+B1");
        spreadsheet.dump();
    }
};

int main() {
    SpreadsheetTest spreadsheetTest;
    spreadsheetTest.test();
    return 0;
}

/**
 * Reference: https://leetcode.com/problems/design-excel-sum-formula/

Given a Spreadsheet API, implement getCell and setCell. setCell can depend on other cells or accept 
an independent value (e.g., setCell("A", "B+C"), setCell("A", 100)).

Circular dependencies must be handled, and test cases should be written. Part 1 can implement a 
non-optimal getCell (calculates values in real time).

Part 2 requires optimizing setCell so that it updates dependent cells, enabling getCell to achieve 
O(1) time complexity. Ultimately, implement both getCell() and setCell().

Test cases:

Example 1:

spreadsheet = Spreadsheet()
spreadsheet.setCell('A1', '1')
spreadsheet.setCell('A2', 2)
spreadsheet.setCell('A3', '=A1+A2')
spreadsheet.setCell('A4', '=A3+A2')
spreadsheet.setCell('A5', '=A3+A4')
spreadsheet.setCell('B1', '=A1+A2+A3+A4+A5')

Example 2:

Cell A = Cell(6, NULL, NULL)
Cell B = Cell(7, NULL, NULL)
Cell C = Cell(13, A, B)
print(getCell(C))  # should return 13 (A+B=6+7)

// after updating Cell A = Cell(2, NULL, NULL)
print(getCell(C))  # should return 9 (A+B=2+7)

Additional notes: A cell can be an int or a formula (e.g., A1+B1). Simple DFS can be used. 
Interviewers may ask how to optimize for more efficient search, especially across multiple requests.

Hints: Implement basic DFS first, then attempt cache-based optimization, particularly focusing 
on how to find downstream cells that are outdated when a node changes.
 */
