#include<iostream>
using namespace std;

class Node {
public:
    int data;
    int depth;
    Node* parent;
    Node* left;
    Node* right;
    Node() {
        data = depth = 0;
        parent = left = right = NULL;
    }
};

class Bst {
public:
    Node* root;
    int height;
    Bst() {
        root = NULL;
        height = 0;
    }
    Node* search(int x) {
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data == x)
                return curr;
            else {
                if (curr->data > x) curr = curr->left;
                else curr = curr->right;
            }
        }
        return NULL;
    }
    void insert(int x) {
        Node* new_Node = new Node();
        new_Node->data = x;
        Node* curr = root;
        Node* par = NULL;
        while (curr != NULL) {
            par = curr;
            if (curr->data > x)curr = curr->left;
            else curr = curr->right;
        }
        if (par == NULL) root = new_Node;
        else if (par->data > x) par->left = new_Node;
        else par->right = new_Node;
        if (par != NULL) {
            new_Node->parent = par;
            new_Node->depth = par->depth + 1;
        }
        if (height < new_Node->depth) height = new_Node->depth;
    }
    void transplant(Node* p, Node* c) {
        if (p == root) root = c;
        else if (p->parent->left == p) p->parent->left = c;
        else p->parent->right = c;
        if (c != NULL) c->parent = p->parent;
    }
    void remove(int x) {
        Node* curr = search(x);
        if (curr->left == NULL && curr->right == NULL) {
            if (curr == root) root = curr;
            else {
                if (curr->parent->left == curr) curr->parent->left = NULL;
                else curr->parent->right = NULL;
            }
        }
        else if (curr->left != NULL && curr->right == NULL) {
            transplant(curr, curr->left);
        }
        else if (curr->left == NULL && curr->right != NULL) {
            transplant(curr, curr->right);
        }
        else {
            Node* tmp = curr->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            if (tmp != curr->right) {
                transplant(tmp, tmp->right);
                tmp->right = curr->right;
                curr->right->parent = tmp;
            }
            transplant(curr, tmp);
            tmp->left = curr->left;
            curr->left->parent = tmp;
        }
        delete curr;
    }
    void destructor(Node* n) {
        if (root == NULL) return;
        if (n->left != NULL) destructor(n->left);
        if (n->right != NULL) destructor(n->right);
        delete n;
    }
};
int main() {
    int test_case;
    cin >> test_case;
    int n, x;
    for (int i = 0; i < test_case; i++) {
        cin >> n;
        Bst bst;
        for (int j = 0; j < n; j++) {
            cin >> x;
            bst.insert(x);
        }
        cout << bst.height << "\n";
        bst.destructor(bst.root);
    }

    return 0;
}