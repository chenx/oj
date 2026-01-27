# 5:50 - 6:32 (where)
from operator import itemgetter

class Database:
    def __init__(self, table_names, columns):
        self.tables = {table: {} for table in table_names}  # <tableName, map<rowId, row[]>>
        self.table_max_id = {table : 0 for table in table_names} # <tableName, row_max_id>
        self.table_columns = {}  # <tableName, columns[]>
        self.table_column_index = {}  # <tableName, map<columnName, index>>

        for i in range(len(table_names)):
            self.table_columns[table_names[i]] = columns[i]  # <tableName, columns[]>

            self.table_column_index[table_names[i]] = {}
            for j in range(len(columns[i])):
                self.table_column_index[table_names[i]][columns[i][j]] = j  # <tableName, map<columnName, index>>
        print(self.table_column_index['User'])

    def insert(self, table, row):
        print(f"\nInsert INTO {table} ({row})")
        self.table_max_id[table] += 1
        rowId = self.table_max_id[table]
        self.tables[table][rowId] = row

        print(f"Table {table}: {self.tables[table]}")
    
    def select(self, table, where, order_by):
        print(f"\nSELECT FROM {table} WHERE {where} OrderBy {order_by}")
        result = []  # List[rowId, List[row]]
        self.handle_where(table, result, where)
        self.handle_orderby(table, result, order_by)
        return result

    def handle_orderby(self, table, result, order_by):
        """
        Python's sort is guaranteed to be stable. 
        This means you can sort multiple times, from the least significant key to the most significant key, 
        and the relative order of tied items from previous sorts will be preserved. 
        
        :param order_by: name ASC, age DESC
        """
        if order_by == "":
            return
        
        # Multiple sort is stable. So sort in reverse order of the fields and it's good.
        # See: https://docs.python.org/3/howto/sorting.html#sort-stability-and-complex-sorts
        fields = order_by.split(',')
        fields.reverse()
        for field in fields:
            fieldName, order = field.strip().split(' ')
            index = self.table_column_index[table][fieldName] + 1  # +1 to bypass RowId
            rev = order == "DESC"

            # print(f"order by {index}, {order}")
            result.sort(key=itemgetter(index), reverse=rev)


    def handle_where(self, table, result, where):
        """
        :param where: E.g., name = Alice AND age = 28
        """
        conditions = [] if where == '' else where.split(' ')
        # print(f"conditions: {conditions}")

        rows = len(self.tables[table])
        for rowId, fields in self.tables[table].items():
            if self.conditionIsTrue(table, conditions, fields):
                row = [rowId]
                row.extend(fields)
                result.append(row)
    
    def conditionIsTrue(self, table, conditions, fields):
        n = len(conditions)

        cond = True
        for i in range(0, n, 3):
            if i > 0:
                i += 1  # ignore AND/OR
            if i >= n: 
                break
                        
            fieldName = conditions[i]
            fieldIndex = self.table_column_index[table][fieldName]
            fieldValue = fields[fieldIndex]
            op = conditions[i + 1]
            val = conditions[i + 2]

            curCond = (op == ">" and fieldValue > val) or \
                      (op == "<" and fieldValue < val) or \
                      (op == "=" and fieldValue == val)

            cond = cond and curCond

        return cond
    
    def dump(self, table):
        print(f"Table {table}\n{self.tables[table]}")

class DatabaseTest:
    def run_tests(self):
        self.test_insert()
        self.test_select()
        self.test_select_where()
        self.test_select_orderby()

    # To assert equality of list or Dict, compare directly.
    def assertEq(self, result, expect):
        if result == expect:
            print(f"Pass: result = {result}")
        else:
            print(f"Fail: result = {result}, expect = {expect}")

    def test_insert(self):
        print("test_insert")
        db = Database(["User", "Product"], [["name", "age"], ["name", "price"]])
        db.insert("User", ["Alice", "28"])
        db.insert("User", ["Bob", "29"])
        db.insert("User", ["Cat", "30"])
        db.insert("User", ["Alice", "30"])

    def test_select(self):
        print("test_insert")
        db = Database(["User", "Product"], [["name", "age"], ["name", "price"]])
        db.insert("User", ["Alice", "28"])
        db.insert("User", ["Bob", "29"])
        db.insert("User", ["Cat", "30"])
        db.insert("User", ["Alice", "30"])

        db.select("User", "", "")

    def test_select_where(self):
        print("test_insert")
        db = Database(["User", "Product"], [["name", "age"], ["name", "price"]])
        db.insert("User", ["Alice", "28"])
        db.insert("User", ["Bob", "29"])
        db.insert("User", ["Cat", "30"])
        db.insert("User", ["Alice", "30"])

        result = db.select("User", "name = Alice", "")
        self.assertEq(result, [[1, 'Alice', '28'], [4, 'Alice', '30']])
        result = db.select("User", "name = Alice AND age = 30", "")
        self.assertEq(result, [[4, 'Alice', '30']])

    def test_select_orderby(self):
        print("test_insert")
        db = Database(["User", "Product"], [["name", "age"], ["name", "price"]])
        db.insert("User", ["Alice", "28"])
        db.insert("User", ["Bob", "29"])
        db.insert("User", ["Cat", "30"])
        db.insert("User", ["Alice", "30"])

        result = db.select("User", "", "name ASC, age ASC")
        print(result)
        result = db.select("User", "", "name ASC, age DESC")
        print(result)


if __name__ == "__main__":
    test = DatabaseTest()
    test.run_tests()
