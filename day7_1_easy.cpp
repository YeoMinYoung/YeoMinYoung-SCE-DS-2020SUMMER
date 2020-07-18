#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
    int data;
    Node* parent;
    vector<Node*> child;
    Node() {
        data = 0;
        parent = NULL;
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> v;
    Tree() {
        root = new Node();
        root->data = 1;
        v.push_back(root);
    }
    Node* getRoot() {
        return root;
    }
    Node* search(int x) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->data == x)
                return v[i];
        }
        return NULL;
    }
    void insertNode(int p, int c) {
        Node* par = search(p);
        Node* new_Node = new Node();
        new_Node->data = c;
        par->child.push_back(new_Node);
        v.push_back(new_Node);
    }
    void printChild(int x) {
        Node* n = search(x);
        for (int i = 0; i < n->child.size(); i++) {
            cout << n->child[i]->data << " ";
        }
        cout << "\n";
    }

};

int main() {

    int test_case;
    cin >> test_case;
    string str;
    int x, y;
    Tree t;
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        if (str == "insert") {
            cin >> x >> y;
            t.insertNode(x, y);
        }
        else if (str == "printChild") {
            cin >> x;
            t.printChild(x);
        }
    }
    return 0;
}