// 
// Evaluate an expression tree. In Java.
// Note the use of interface, exception.
//
// 1) This allows both unary and binary operators, and can be extended to 
//    operators require more operands, by passing operands in a list. 
// 2) Can print callStack to pinpoint where the exception happens.
//
// By: X.C. 4/18/2016. Amz.
// Last modified: 4/20/2016
//
import java.util.*;

interface Evaluator {
     Double evaluate();
}

public class ExprEval implements Evaluator {
    private Node root;
    
    public void setRoot(Node root) { this.root = root; }
    
    public Double evaluate() {
       double val = 0.0;
       try {
           val = evaluate(root);
       }
       catch (Exception e) {
           System.out.println("Exception: " + e.getMessage());
           dumpCallStack();
       }
       return val;
    }

    private Double evaluate(Node root) throws Exception {
        if (root == null) return 0.0;
        callStack.push(root);

        Double val;
        if (root.isOperator()) {
            //val = calc(root.getOperator(), evaluate(root.left), evaluate(root.right));
            ArrayList<Double> params = new ArrayList<Double>();
            if (root.left != null) params.add(evaluate(root.left));
            if (root.right != null) params.add(evaluate(root.right));
            val = calc(String.valueOf(root.getOperator()), params);
        }
        else {
            val = root.getValue();
        }

        callStack.pop();
        return val;
    }

    // In this new version of calc(), can add any operator.
    // Strategy design pattern.
    private Double calc(String operator, ArrayList<Double> params) throws Exception {
        if (operator.equals("+")) return params.get(0) + params.get(1);
        else if (operator.equals("-")) return params.get(0) - params.get(1);
        else if (operator.equals("*")) return params.get(0) * params.get(1);
        else if (operator.equals("/")) {
            //if (b == 0) throw new Exception("divide by zero");
            if (Math.abs(params.get(1)) < 0.0000001) throw new Exception("divide by zero");
            else return params.get(0) / params.get(1);
        }
        else if (operator.equals("sqrt")) {
            if (params.get(0) < 0) throw new Exception("sqrt on negative number");
            return Math.sqrt(params.get(0));
        }
        else throw new Exception("unknown operator: " + operator);
    }

    /*
    // Deprecated. This is un-favorable since it applies to binary operators only.
    private Double calc2(char operator, double a, double b) throws Exception {
        if (operator == '+') return a + b;
        else if (operator == '-') return  a - b;
        else if (operator == '*') return a * b;
        else if (operator == '/') {
            //if (b == 0) throw new Exception("divide by zero");
            if (Math.abs(b) < 0.0000001) throw new Exception("divide by zero");
            else return a / b;
        }
        else throw new Exception("unknown operator: " + operator);
    }
    */
    
    // call stack, to display where error happens.
    private Stack<Node> callStack;
    private void dumpCallStack() {
        System.out.println("call stack:");
        while (! callStack.empty()) {
           Node n = callStack.peek();
           if (n.isOperator()) System.out.println( n.op );
           else System.out.println( n.val );
           callStack.pop();
           
           // below prints the left/right path from root.
           if (callStack.empty()) System.out.println( " :root" );
           else System.out.println( n == callStack.peek().left ? " :left child" : " :right child" );
        }
    }
    public ExprEval() { callStack = new Stack<Node>(); }
    
    void test1() {
        Node root = new Node('+');
        root.left = new Node('/');
        root.left.left = new Node(12);
        root.left.right = new Node(3);
        root.right = new Node('*');
        root.right.left = new Node('/');
        root.right.left.left = new Node(4);
        root.right.left.right = new Node(2);
        root.right.right = new Node('/');
        root.right.right.left = new Node(3);
        root.right.right.right = new Node(1);
        
        try {
            setRoot(root);
            double v = evaluate();
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
    }
}

class Node {
    public char op;
    public boolean isOp;
    public boolean isOperator() { return isOp; }
    public char getOperator() { return op; }
    
    public double val;
    public double getValue() { return val; }

    Node left, right;
    
    Node(double v) { val = v; isOp = false; left = right = null; }
    Node(char operator) { op = operator; isOp = true; left = right = null; }
}

