class Cell:
    value = 0
    formular = ''
    parents = []
    parentSet = set()

    def set_value(self, val):
        self.value = val
        self.formular = ''
        self.parents = []
        self.parentSet = set()
    
    def set_formular(self, f):
        if f[0] == '=': f = f[1:]
        self.formular = f
        self.parents = []
        self.parentSet = set()

        for cell in f.split('+'):
            x = int(cell[1:]) - 1
            y = ord(cell[0]) - ord('A')
            self.parents.append([x, y])
            self.parentSet.add(str(x) + ',' + str(y))
        
        # print('parents: ', self.parents)
        # print('parentSet: ', self.parentSet)

class Spreadsheet:
    def __init__(self, height, width):
        self.rows = height
        self.cols = width
        self.cells = [[Cell() for _ in range(self.cols)] for _ in range(self.rows)]
        # print(self.cells)
        self.calcStack = []

    def set_formular(self, cellName, formular):
        row, col = self.getRowCol(cellName)
        self.cells[row][col].set_formular(formular)

        # can't use {row, col}, this is a set, for row = 0 and col = 0, this becomes {0}
        if self.has_cycle(row, col, [row, col]):
            print('cycle detected at ' + cellName)
            return

        self.get_children(row, col)
        self.calc_stack()
        # self.dump()

    def set_value(self, cellName, value):
        if isinstance(value, str):
            self.set_formular(cellName, value)
            return
        
        row, col = self.getRowCol(cellName)
        self.cells[row][col].value = value
        # self.dump()

        self.get_children(row, col)
        self.calc_stack()
    
    def get_cell(self, cellName):
        row, col = self.getRowCol(cellName)
        return self.cells[row][col].value

    def getRowCol(self, cellName):
        row = int(cellName[1:]) - 1
        col = ord(cellName[0]) - ord('A')
        return row, col
    
    def has_cycle(self, row, col, start):
        # print('row/col/start: ', row, ', ', col, ', ', start)
        for [x, y] in self.cells[row][col].parents:
            if [x, y] == start:
                return True
            if self.has_cycle(x, y, start):
                return True
        return False

    def get_children(self, x, y):
        for i in range(self.rows):
            for j in range(self.cols):
                key = str(x) + ',' + str(y)
                if key in self.cells[x][y].parentSet:
                    self.get_children(i, j)
        self.calcStack.append([x, y])

    def calc_stack(self):
        while len(self.calcStack) > 0:
            [x, y] = self.calcStack.pop()
            if not self.cells[x][y].formular == '':
                sum = 0
                for [i, j] in self.cells[x][y].parents:
                    sum += self.cells[i][j].value

                self.cells[x][y].value = sum

    def dump(self):
        print('dump:')
        for i in range(self.rows):
            for j in range(self.cols):
                print(str(self.cells[i][j].value) + ' [' + self.cells[i][j].formular + ']\t', end = ' ')
            print()
    

class SpreadsheetTest:
    def run_tests(self):
        # self.test_cell()
        # self.test_spreadsheet()
        self.test_spreadsheet_cycle()
        pass
    
    def test_cell(self):
        cell = Cell()
        cell.set_formular('A1+A2')
    
    def test_spreadsheet(self):
        sheet = Spreadsheet(5, 5)
        sheet.set_value('A1', 1)
        self.assert1("A1", sheet.get_cell("A1"), 1);

        sheet.set_value('A2', 2)
        self.assert1("A2", sheet.get_cell("A2"), 2);

        sheet.set_value('A3', '=A1+A2')
        self.assert1("A3", sheet.get_cell("A3"), 3);

        sheet.set_value("A3", "=A1+A2+A1");
        self.assert1("A3", sheet.get_cell("A3"), 4);
        
        sheet.set_value("A4", "=A3+A2");
        self.assert1("A4", sheet.get_cell("A4"), 6);
        
        sheet.set_value("A5", "=A3+A4");
        self.assert1("A5", sheet.get_cell("A5"), 10);
        
        sheet.set_value("B1", "=A1+A2+A3+A4+A5");
        self.assert1("B1", sheet.get_cell("B1"), 23);
    
    def test_spreadsheet_cycle(self):
        sheet = Spreadsheet(5, 5)
        sheet.set_value('A1', '=A3')
        sheet.set_value('A2', '=A1')
        sheet.set_value('A3', '=A1+A2')

    def assert1(self, cellName, result, expect):
        if result == expect:
            print('Pass: ' + cellName + ': result = ', result)
        else:
            print('Fail: ' + cellName + ': result = ', result, ', expect = ', expect)


if __name__ == "__main__":
    test = SpreadsheetTest()
    test.run_tests()
