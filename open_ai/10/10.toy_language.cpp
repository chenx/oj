#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Primitives: Lowercase strings like int, float, str, bool
    Generics: Uppercase letters followed by numbers, e.g., T1, T2
    Tuples: Comma-separated types inside brackets, which can be nested. Example: [int, [T1, str]].
    Functions: Defined by a list of parameter types and a single return type. Syntax: [param1, param2] -> returnType.
 */

// class Node;
// void convertTupleToString(vector<Node>& tuple, string& str);


class Node {
public:
    vector<Node> children;
    string typeName;

    Node(string type) {
        typeName = type;
    }

    Node(vector<Node>& tuple) {
        children = tuple;
        updateStringVal();
    }

    string toString() const {
        return typeName;
    }

    void updateStringVal() {
        typeName = "";
        convertTupleToString(children, typeName);
        typeName = "[" + typeName + "]";
    }

    void convertTupleToString(const vector<Node>& tuple, string& str, int level = 0) {
        for (const Node& node : tuple) {
            if (str != "") str += ",";
            if (! node.children.empty()) {
                convertTupleToString(node.children, str, 1);
            } else {
                str += node.toString();
            }
        }
        if (level > 0) str = "[" + str + "]";
    }
};

// void convertTupleToString(vector<Node>& tuple, string& str) {
//     for (const Node& node : tuple) {
//         if (str != "") str += ",";
//         if (! node.children.empty()) {
//             vector<Node> tpl = { node };
//             convertTupleToString(tpl, str);
//         } else {
//             str += node.toString();
//         }
//     }
// }

class Function {
public:
    vector<Node> outputTypes;
    string typeName;
    vector<Node> params_;
    
    Function(vector<Node>& input_params, Node output_type) {
        params_ = input_params;
        outputTypes.push_back(output_type);

        output_type.convertTupleToString(input_params, typeName); 
        // // convertTupleToString(input_params, typeName); 
        typeName = "(" + typeName + ") -> " + output_type.toString();
    }

    string toString() {
        return typeName;
    }

    vector<Node>& getParams() {
        return params_;
    }
};

bool getMatch(vector<Node>& params, vector<Node>& funcParams, unordered_map<string, string>& typeMap) {
    if (params.size() != funcParams.size()) return false;

    for (int i = 0; i < params.size(); ++ i) {
        // cout << "i=" << i << ". " << funcParams[i].toString() << endl;
        if (funcParams[i].children.empty()) {
            if (funcParams[i].typeName[0] == 'T') {
                if (! typeMap.count(funcParams[i].typeName)) {
                    // cout << "matching: " << funcParams[i].typeName << " to " << params[i].typeName << endl;
                    typeMap[funcParams[i].typeName] = params[i].typeName;
                } else if (typeMap[funcParams[i].typeName] != params[i].typeName) {
                    cout << "found conflict1: " << funcParams[i].typeName << " to " << params[i].typeName << endl;
                    return false;
                }
            } else {
                if (funcParams[i].typeName != params[i].typeName) {
                    cout << "found conflict2: " << funcParams[i].toString() << " to " << params[i].typeName << endl;
                    return false;
                }
            }
        } else { // is a tuple.
            if (! getMatch(params[i].children, funcParams[i].children, typeMap)) {
                return false;
            }
        }
    }
    return true;
}

void replace(vector<Node>& funcParams, unordered_map<string, string>& typeMap) {
    for (auto& param : funcParams) {
        if (param.children.empty()) {
            if (param.typeName[0] == 'T') {
                if (typeMap[param.typeName].empty()) {
                    cout << "warning: unmatched generic type: " << param.typeName << endl;
                }
                // cout << "replace: " << param.typeName << " with " << typeMap[param.typeName] << endl;
                param.typeName = typeMap[param.typeName];
            }
        } else {
            replace(param.children, typeMap);
        }
    }
}

Node get_return_type(vector<Node>& params, Function& func) {
    unordered_map<string, string> typeMap;

    if (! getMatch(params, func.getParams(), typeMap)) {
        // cout << "match failed" << endl;
        // throw invalid_argument("match failed");
        return Node("match failed");
    }

    replace(func.outputTypes, typeMap);
    func.outputTypes[0].updateStringVal();

    // string result = func.outputTypes[0].toString();
    // cout << "result: " << result << endl;
    return func.outputTypes[0];
}

class Test {
    void expect(string result, string expect) {
        if (result == expect) {
            cout << "Pass: result = " << result << endl;
        } else {
            cout << "Fail: result = " << result << ", expect = " << expect << endl;
        }
    }

    void testNode() {
        Node node("int");
        expect(node.toString(), "int");

        Node node2("T1");
        expect(node2.toString(), "T1");

        vector<Node> params = {
            Node("T1"),
            Node("int"),
        };
        Node node3(params);
        expect(node3.toString(), "[T1,int]");
    }

    void testFunction() {
        vector<Node> nodeParams = {
            Node("T1"),
            Node("str"),
        };
        Node outputType(nodeParams);

        vector<Node> funcParams = {
            Node("int"),
            Node("T1"),
        };
        Function func(funcParams,  outputType);
        expect(func.toString(), "(int,T1) -> [T1,str]");

        vector<Node> params = {
            Node("int"),
            Node("bool"),
        };
        Node node = get_return_type(params, func);
        expect(node.toString(), "[bool,str]");
    }

    void testFunction2() {
        // Function: [T1, T2, int, T1] -> [T1, T2]
        // Arguments: [int, str, int, int]

        vector<Node> nodeParams = {
            Node("T1"),
            Node("T2"),
        };
        Node outputType(nodeParams);

        vector<Node> funcParams = {
            Node("T1"),
            Node("T2"),
            Node("int"),
            Node("T1"),
        };
        Function func(funcParams,  outputType);
        expect(func.toString(), "(T1,T2,int,T1) -> [T1,T2]");

        vector<Node> params = {
            Node("int"),
            Node("str"),
            Node("int"),
            Node("int"),
        };
        Node node = get_return_type(params, func);
        expect(node.toString(), "[int,str]");
    }

    void testFunction3() {
        // Function: [[T1, float], T2, T3] -> [T3, T1]
        // Arguments: [[str, float], [int, str], int]

        vector<Node> nodeParams = {
            Node("T3"),
            Node("T1"),
        };
        Node outputType(nodeParams);

        vector<Node> funcParams1 = {
            Node("T1"),
            Node("float"),
        };
        Node node1(funcParams1);

        vector<Node> funcParams = {
            // Node({ 
            //     Node("T1"),
            //     Node("float")
            // }),
            node1,
            Node("T2"),
            Node("T3"),
        };
        Function func(funcParams,  outputType);
        expect(func.toString(), "([T1,float],T2,T3) -> [T3,T1]");

        vector<Node> params1 = {
            Node("str"),
            Node("float"),
        };
        vector<Node> params2 = {
            Node("int"),
            Node("str"),
        };
        Node node21(params1);
        Node node22(params2);
        vector<Node> params = {
            node21,
            node22,
            Node("int"),
        };
        Node node = get_return_type(params, func);
        expect(node.toString(), "[int,str]");
    }

    void testFunction4() {
        // Function: [T1, T1] -> T1
        // Arguments: [int, str]
        // Error: T1 cannot be both int and str.

        vector<Node> nodeParams = {
            Node("T1"),
        };
        Node outputType(nodeParams);

        vector<Node> funcParams = {
            Node("T1"),
            Node("T1"),
        };
        Function func(funcParams,  outputType);

        vector<Node> params = {
            Node("int"),
            Node("str"),
        };

        Node node = get_return_type(params, func);
        expect(node.toString(), "match failed");
    }

public:
    void run_tests() {
        testNode();
        testFunction();
        testFunction2();
        testFunction3();
        testFunction4();
    }
};

int main() {
    Test test;
    test.run_tests();
    return 0;
}
