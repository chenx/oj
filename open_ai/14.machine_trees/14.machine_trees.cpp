// 4:52 - 6:24

#include <iostream>

using namespace std;

class Node {
public:
    Node* parent;
    vector<Node*> children;
    int id;
    int recvMessageCount = 0;
    int totalCount = 0;
    string totalStructure;

    Node(int idVal, Node* parentVal = NULL) : id(idVal), parent(parentVal) {}

    void sendMessage(Node* targetNode, Node* fromNode, string msg, bool needResponse = false) {
        cout << "Node(" << id << "): send msg to (" << targetNode->id << "): " << msg << endl;
        string response = targetNode->recvMessage(fromNode, msg);
        if (needResponse) fromNode->recvMessage(targetNode, response);
    }

    string recvMessage(Node* fromNode, string message) {
        if (message == "") return "";
        string msgType, msgValue;
        getMsg(message, msgType, msgValue);

        cout << "Node(" << id << "): recvMessage from (" << (fromNode ? fromNode->id : 0) << "). msg = " << message << endl;

        bool isRoot = parent == NULL;

        if (msgType == "START_COUNT" || msgType == "COUNT_REQUEST") {
            if (children.empty()) {
                if (isRoot) {
                    cout << "Total count: 1" << endl;
                } else {
                    return "COUNT_RESPONSE:1";
                }
            } else {
                recvMessageCount = 0;
                totalCount = 1; // count self as 1
                for (auto node : children) {
                    sendMessage(node, this, "COUNT_REQUEST", /* needResponse= */true);
                }
            }
        } else if (msgType == "COUNT_RESPONSE") {
            totalCount += stoi(msgValue);
            ++ recvMessageCount;
            cout << "Node(" << id << "): recvMessageCount = " << recvMessageCount << endl;
            if (recvMessageCount == children.size()) {
                if (isRoot) {
                    cout << "Total count: " << totalCount << endl;
                } else {
                    sendMessage(parent, this, "COUNT_RESPONSE:" + to_string(totalCount));
                }
            }
        } 
        else if (msgType == "START_STRUCTURE" || msgType == "STRUCTURE_REQUEST") {
            if (children.empty()) {
                if (isRoot) {
                    cout << id << endl;
                } else {
                    return "STRUCTURE_RESPONSE:" + to_string(id);
                }
            } else {
                recvMessageCount = 0;
                totalStructure = to_string(id);
                for (auto node : children) {
                    sendMessage(node, this, "STRUCTURE_REQUEST", /* needResponse= */true);
                }
            }
        } else if (msgType == "STRUCTURE_RESPONSE") {
            ++ recvMessageCount;

            if (recvMessageCount == 1) totalStructure += "(";
            if (recvMessageCount > 1) totalStructure += ",";
            totalStructure += msgValue;
            if (recvMessageCount == children.size())totalStructure += ")";

            if (recvMessageCount == children.size()) {
                if (isRoot) {
                    cout << "Total structure: " << totalStructure << endl;
                } else {
                    sendMessage(parent, this, "STRUCTURE_RESPONSE:" + totalStructure);
                }
            }
        }

        return "";
    }

    void getMsg(string& msg, string& type, string& val) {
        int index = msg.find(":");
        if (index != string::npos) {
            type = msg.substr(0, index);
            val = msg.substr(index + 1);
            // cout << "type: " << type << ", val: " << val << endl;
            return;
        }
        // cout << "index == -1. msg: " << msg << endl;
        type = msg;
    }
};

class MachineTree {
    Node* root;
public:
    MachineTree(Node* rootValue) : root(rootValue) {}

    void startCount() {
        root->recvMessage(NULL, "START_COUNT");
    }

    void startStructure() {
        root->recvMessage(NULL, "START_STRUCTURE");
    }
};

class MachineTreeTest {
    void test_count() {
        cout << "Test count" << endl;
        Node * root = new Node(1);
        root->children.push_back(new Node(2, root));
        root->children.push_back(new Node(3, root));
        root->children[0]->children.push_back(new Node(4, root->children[0]));
        root->children[0]->children.push_back(new Node(5, root->children[0]));
        root->children[1]->children.push_back(new Node(6, root->children[1]));
        root->children[1]->children[0]->children.push_back(new Node(7, root->children[1]->children[0]));

        MachineTree tree(root);

        tree.startCount();
    }

    void test_structure() {
        cout << "Test structure" << endl;
        Node * root = new Node(1);
        root->children.push_back(new Node(2, root));
        root->children.push_back(new Node(3, root));
        root->children[0]->children.push_back(new Node(4, root->children[0]));
        root->children[0]->children.push_back(new Node(5, root->children[0]));
        root->children[1]->children.push_back(new Node(6, root->children[1]));
        root->children[1]->children[0]->children.push_back(new Node(7, root->children[1]->children[0]));

        MachineTree tree(root);

        tree.startStructure();
    }
public:
    void run_tests() {
        test_count();
        test_structure();
    }
};

int main() {
    MachineTreeTest test;
    test.run_tests();
    return 0;
}


/**
Test count
Node(1): recvMessage from (0). msg = START_COUNT
Node(1): send msg to (2): COUNT_REQUEST
Node(2): recvMessage from (1). msg = COUNT_REQUEST
Node(2): send msg to (4): COUNT_REQUEST
Node(4): recvMessage from (2). msg = COUNT_REQUEST
Node(2): recvMessage from (4). msg = COUNT_RESPONSE:1
Node(2): recvMessageCount = 1
Node(2): send msg to (5): COUNT_REQUEST
Node(5): recvMessage from (2). msg = COUNT_REQUEST
Node(2): recvMessage from (5). msg = COUNT_RESPONSE:1
Node(2): recvMessageCount = 2
Node(2): send msg to (1): COUNT_RESPONSE:3
Node(1): recvMessage from (2). msg = COUNT_RESPONSE:3
Node(1): recvMessageCount = 1
Node(2): recvMessage from (1). msg = wait for next child response .. 
Node(1): recvMessage from (2). msg = 
Node(1): send msg to (3): COUNT_REQUEST
Node(3): recvMessage from (1). msg = COUNT_REQUEST
Node(3): send msg to (6): COUNT_REQUEST
Node(6): recvMessage from (3). msg = COUNT_REQUEST
Node(3): recvMessage from (6). msg = COUNT_RESPONSE:1
Node(3): recvMessageCount = 1
Node(3): send msg to (1): COUNT_RESPONSE:2
Node(1): recvMessage from (3). msg = COUNT_RESPONSE:2
Node(1): recvMessageCount = 2
Total count: 6
Node(3): recvMessage from (1). msg =  // why there are empty messages sent?
Node(1): recvMessage from (3). msg = 
*/
