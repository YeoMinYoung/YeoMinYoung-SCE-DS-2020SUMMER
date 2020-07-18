#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    int depth;
    Node* parent;
    vector<Node*> child;
    Node() {
        data = 0;
        depth = 0;
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
    Node* search(int x) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->data == x)
                return v[i];
        }
        return NULL;  ///그냥 리턴 아니다 !! 널 리턴.
    }
    void insert(int p, int c) {
        Node* par = search(p);
        if (par == NULL) {
            cout << "-1\n";
            return;
        }
        Node* new_Node = new Node();
        new_Node->data = c;
        new_Node->parent = par;
        new_Node->depth = par->depth + 1;
        par->child.push_back(new_Node);
        v.push_back(new_Node);
    }

    void printChild(int x) {
        Node* n = search(x);
        if (n == NULL) {
            cout << "-1\n";
            return;
        }
        else if (n->child.size() == 0) {
            cout << "0\n";
            return;
        }
        for (int i = 0; i < n->child.size(); i++) {
            cout << n->child[i]->data << " ";
        }
        cout << "\n";
    }
    void printDepth(int x) {
        Node* n = search(x);
        if (n == NULL)
        {
            cout << "-1\n";
        }
        else {
            cout << n->depth << "\n";
        }
    }

};
int main() {
    string str;
    Tree t;
    int test_case;
    int x, y;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        if (str == "insert") {
            cin >> x >> y;
            t.insert(x, y);
        }
        else if (str == "printChild") {
            cin >> x;
            t.printChild(x);
        }
        else if (str == "printDepth") {
            cin >> x;
            t.printDepth(x);
        }
    }
    return 0;
}