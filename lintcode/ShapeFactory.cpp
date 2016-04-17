
/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
 
// From: http://www.jianshu.com/p/9205271e1b33
class Shape {
public:
    virtual void draw() const=0;

    void drawHorizontalLine() const {
        drawSpace(1);
        for(int i = 0; i < 4; i++) {
            cout << '-';
        }
        drawSpace(1);
        cout << endl;
    }

    void drawVerticalLine() const {
        cout << '|';
        drawSpace(4);
        cout << '|' << endl;
    }

    void drawSpace(int n) const {
        for(int i = 0; i < n; i++) {
            cout << ' ';
        }
    }
};

class Rectangle: public Shape {
public:
    void draw() const {
        drawHorizontalLine();
        drawVerticalLine();
        drawHorizontalLine();
    }
};

class Square: public Shape {
public:
    void draw() const {
        drawHorizontalLine();
        drawVerticalLine();
        drawVerticalLine();
        drawHorizontalLine();
    }
};

class Triangle: public Shape {
public:
    void draw() const {
        drawSpace(2);
        cout << "/\\" << endl;
        drawSpace(1);
        cout << '/';
        drawSpace(2);
        cout << '\\' << endl;
        cout << '/';
        for(int i = 0; i < 4; i++) {
            cout << '_';
        }
        cout << '\\' << endl;
    }
};

class ShapeFactory {
private:
    const string squareType = "Square";
    const string triangleType = "Triangle";
    const string rectType = "Rectangle";

public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        if (shapeType == squareType) {
            return new Square();
        } else if (shapeType == rectType) {
            return new Rectangle();
        } else if (shapeType == triangleType) {
            return new Triangle();
        }

        return NULL;
    }
};


/**
Shape Factory

Factory is design pattern in common usage. Implement a ShapeFactory that can generate correct shape.
Have you met this question in a real interview?
Example

ShapeFactory sf = new ShapeFactory();
Shape shape = sf.getShape("Square");
shape.draw();
>>  ----
>> |    |
>> |    |
>>  ----

shape = sf.getShape("Triangle");
shape.draw();
>>   /\
>>  /  \
>> /____\

shape = sf.getShape("Rectangle");
shape.draw();
>>  ----
>> |    |
>>  ----


 */
