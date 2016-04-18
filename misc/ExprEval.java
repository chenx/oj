import java.util.*;

interface Evaluator {
     Double evaluate(Node root) throws Exception;
}

public class ExprEval implements Evaluator {

    public Double evaluate(Node root) throws Exception {
        if (root == null) return 0.0;

        if (root.isOperator()) {
            return calc(root.getOperator(), evaluate(root.left), evaluate(root.right));
        }
        else {
            return root.getValue();
        }
    }

    Double calc(char operator, double a, double b) throws Exception {
        if (operator == '+') return a + b;
        else if (operator == '-') return  a - b;
        else if (operator == '*') return a * b;
        else if (operator == '/') {
            //if (b == 0) throw new Exception("divide by zero");
            if (Math.abs(b) < 0.0000001) throw new Exception("divide by zero");
            else return a / b;
        }
        else {
            throw new Exception("unknown operator");
        }
    }

    void test1() {
        Node root = new Node('+');
        root.left = new Node('/');
        root.left.left = new Node(12);
        root.left.right = new Node(3);
        root.right = new Node('*');
        root.right.left = new Node(2);
        root.right.right = new Node(3);

        try {
            double v = evaluate(root);
            double a = 10;
            System.out.println("expects: " + v + ", answer: " + a);
            System.out.println( (v == a) ? "pass" : "fail <----" );
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        ExprEval e = new ExprEval();
        e.test1();
        //System.out.println("hello");
    }
}

class Node {
    public double val;
    public char op;
    public boolean isOp;
    public boolean isOperator() { return isOp; }
    public char getOperator() { return op; }
    public double getValue() { return val; }

    Node left, right;
    Node(double v) { val = v; isOp = false; left = right = null; }
    Node(char operator) { op = operator; isOp = true; left = right = null; }
}

