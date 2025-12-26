class Excel2 {
    struct Cell {  // Assume column is A-Z only, row starts with 1.
        int val = 0;
        vector<vector<int>> parents; // A1:A2 => {{A, 1}, {A, 2}} => {{0, 0}, {0, 1}}
        set<vector<int>> parentSet;

        void setValue(int value) {
            val = value;
            parents.clear();
            parentSet.clear();
        }

        void setFormula(vector<vector<int>>& parents) {
            this->parents = parents;
            parentSet.clear();
            for (auto parent : parents) {
                parentSet.insert(parent);
            }
        }
    };

    vector<vector<Cell>> cells;
    int rows, cols;    
    stack<vector<int>> stack; // For cyclic update when setting formula.

public:
    Excel(int height, char width) : rows(height), cols(width) {
        cells.resize(height, vector<Cell>(width, Cell()));
    }
    
    void set(int row, char column, int val) {
        int col = column - 'A'; row -= 1;
        cells[row][col].setValue(val);
        updateChildren(row, col);
    }
    
    int get(int row, char column) {
        return cells[row - 1][column - 'A'].val;
    }
    
    int sum(int row, char column, vector<string> numbers) {
        vector<vector<int>> parents = convert(numbers);
        int col = column - 'A'; row -= 1;
        cells[row][col].setFormula(parents);

        updateChildren(row, col);
        return cells[row][col].val;
    }

private:
    void updateChildren(int row, int col) { // update cells depending on this cell.
        addChildrenToStack(row, col);
        calcStack();
    }

    vector<vector<int>> convert(vector<string>& strs) {
        vector<vector<int>> result;
        for (string st : strs) {
            if (st.find(":") == string::npos) {
                result.push_back({st[1] - '1', st[0] - 'A'});
            } else {
                vector<string> cells = split(st, ':');
                int si = stoi(cells[0].substr(1)), ei = stoi(cells[1].substr(1));
                char sj = cells[0][0], ej = cells[1][0];
                for (int i = si; i <= ei; i++) {
                    for (char j = sj; j <= ej; j++) {
                        result.push_back({i - 1, j - 'A'});
                    }
                }
            }
        }
        return result;
    }

    // Could memorize the children list for the given cell.
    // Then if update a formular of a cell, update its children.
    void addChildrenToStack(int row, int col) {
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

            Cell& cell = cells[row][col];
            if (! cell.parents.empty()) {
                cell.val = getParentSum(cell.parents);
            }
        }
    }

    int getParentSum(vector<vector<int>>& parents) {
        int sum = 0;
        for (auto parent : parents) {
            sum += cells[parent[0]][parent[1]].val;
        }
        return sum;
    }

    vector<string> split(const string& s, char delimiter) {
        stringstream ss(s);
        string out;
        vector<string> result;

        while (getline(ss, out, delimiter)) {
            result.push_back(out);
        }
        return result;
    }
};


// From: https://leetcode.com/problems/design-excel-sum-formula/editorial/
// set - takes O((r*c)^2) time. Here, r and c refer to the number of rows and columns in the current Excel Form.
// sum - takes O((r∗c)^2 + 2*r*c*l) time. l is the number of cells in the numbers 2D array.
// get - takes O(1) time.
// The space required will be O((r*c)^2) in the worst case. O(r*c) space will be required for the Excel Form itself. 
// For each cell in this form, the cells list can contain O(r*c) cells.

class Excel {
private:
    struct Formula {
        Formula(map<string, int> c, int v) : cells(c), val(v) {}

        map<string, int> cells;
        int val;
    };

    vector<vector<Formula>> Formulas;
    stack<vector<int>> stack;

public:
    Excel(int height, char width) {
        Formulas.resize(height, vector<Formula>(width - 'A' + 1, Formula({}, 0)));
    }
    
    void set(int row, char column, int val) {
        // Formulas[row - 1][column - 'A'] = Formula(map<string, int>(), val);
        Formulas[row - 1][column - 'A'].val = val;
        Formulas[row - 1][column - 'A'].cells.clear();

        topologicalSort(row - 1, column - 'A');
        execute_stack();
    }
    
    int get(int row, char column) {
        return Formulas[row - 1][column - 'A'].val;
    }
    
    int sum(int row, char column, vector<string> numbers) {
        map<string, int> cells = convert(numbers);
        int sum = calculate_sum(row - 1, column - 'A', cells);
        set(row, column, sum);
        Formulas[row - 1][column - 'A'] = Formula(cells, sum);
        return sum;
    }

private:

    void topologicalSort(int r, int c) {
        for (int i = 0; i < Formulas.size(); i++)
            for (int j = 0; j < Formulas[0].size(); j++) {
                string key = string(1, 'A' + c) + to_string(r + 1);
                cout << "key = " << key << endl;
                if (Formulas[i][j].cells.contains(key)) {
                    topologicalSort(i, j);
                }
            }
        stack.push({r,c});
    }

    void execute_stack() {
        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            if (Formulas[top[0]][top[1]].cells.size() > 0)
                calculate_sum(top[0], top[1], Formulas[top[0]][top[1]].cells);
        }
    }

    map<string, int> convert(vector<string>& strs) {
        map<string, int> res;
        for (string st : strs) {
            cout << "convert: st = " << st << endl;
            // if (st.indexOf(":") < 0) {
            if (st.find(":") == string::npos) {
                res[st] ++;
            } else {
                vector<string> cells = split(st, ':');
                int si = stoi(cells[0].substr(1)), ei = stoi(cells[1].substr(1));
                char sj = cells[0][0], ej = cells[1][0];
                for (int i = si; i <= ei; i++) {
                    for (char j = sj; j <= ej; j++) {
                        // convert char to string: string(1, j)
                        // convert int to string: to_string(i)
                        res[string(1, j) + to_string(i)] ++;
                    }
                }
            }
        }
        return res;
    }

    vector<string> split(string& str, char ch) {
        stringstream ss(str);
        string out;
        vector<string> result;
        while (getline(ss, out, ch)) {
            cout << "split: out = " << out << endl;
            result.push_back(out);
        }
        return result;
    }

    int calculate_sum(int r, int c, map<string, int>& cells) {
        int sum = 0;
        for (auto [key, value] : cells) {
            int x = stoi(key.substr(1)) - 1, y = key[0] - 'A';
            cout << "key = " << key << ", value=" << value << ", x = " << x << ", y = " << y << endl;
            sum += Formulas[x][y].val * cells[key];
        }
        Formulas[r][c] = Formula(cells, sum);
        return sum;
    }

};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */



/**
631. Design Excel Sum Formula
Hard

Design the basic function of Excel and implement the function of the sum formula.

Implement the Excel class:

    Excel(int height, char width) Initializes the object with the height and the width of the sheet. 
        The sheet is an integer matrix mat of size height x width with the row index in the range [1, height] and 
        the column index in the range ['A', width]. All the values should be zero initially.
    void set(int row, char column, int val) Changes the value at mat[row][column] to be val.
    int get(int row, char column) Returns the value at mat[row][column].
    int sum(int row, char column, List<String> numbers) Sets the value at mat[row][column] to be the sum of cells 
        represented by numbers and returns the value at mat[row][column]. This sum formula should exist until this 
        cell is overlapped by another value or another sum formula. numbers[i] could be on the format:

        "ColRow" that represents a single cell.
            For example, "F7" represents the cell mat[7]['F'].
        "ColRow1:ColRow2" that represents a range of cells. The range will always be a rectangle where "ColRow1" 
            represent the position of the top-left cell, and "ColRow2" represents the position of the bottom-right cell.
            For example, "B3:F7" represents the cells mat[i][j] for 3 <= i <= 7 and 'B' <= j <= 'F'.

Note: You could assume that there will not be any circular sum reference.

    For example, mat[1]['A'] == sum(1, "B") and mat[1]['B'] == sum(1, "A").
 */
