#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;
    Node() {
        data = 0;
        parent = left = right = NULL;
    }
};

class Bst {
public:
    Node* root;
    Bst() {
        root = NULL;
    }
    Node* search(int x) {
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data == x) return curr;
            else if (curr->data > x) curr = curr->left;
            else curr = curr->right;
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
        new_Node->parent = par;
    }
    void transplant(Node* p, Node* c) {
        if (p == root) root = c;
        else if (p->parent->left == p) p->parent->left = c;
        else p->parent->right = c;
        if (c != NULL) c->parent = p->parent;
    }
    void remove(int x) {
        Node* n = search(x);
        if (n == NULL) return;
        if (n->left == NULL && n->right == NULL) {
            if (n == root) root = NULL;
            else if (n->parent->left == n) n->parent->left = NULL;
            else n->parent->right = NULL;
        }
        else if (n->left != NULL && n->right == NULL)
            transplant(n, n->left);
        else if (n->left == NULL && n->right != NULL)
            transplant(n, n->right);
        else {
            Node* curr = n->right;
            while (curr->left != NULL)
                curr = curr->left;
            if (curr != n->right) {
                transplant(curr, curr->right);
                curr->right = n->right;
                n->right->parent = curr;
            }
            transplant(n, curr);
            curr->left = n->left;
            n->left->parent = curr;
        }
        delete n;
    }
    void destructor(Node* n) {
        if (n == NULL) return;
        if (n->left != NULL) destructor(n->left);
        if (n->right != NULL) destructor(n->right);
        delete n;
    }
    void print(Node* root) {
        if (root == NULL) cout << 0;
        else {
            cout << root->data << " ";
            if (root->left != NULL) print(root->left);
            if (root->right != NULL) print(root->right);
        }
    }
};

int main() {
    int test_case;
    cin >> test_case;
    int n, m, x;
    for (int i = 0; i < test_case; i++) {
        cin >> n;
        Bst bst;
        for (int j = 0; j < n; j++) {
            cin >> x;
            bst.insert(x);
        }
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x;
            bst.remove(x);
        }
        if (bst.root == NULL) cout << 0;
        else bst.print(bst.root);
        cout << "\n";
        bst.destructor(bst.root);

    }

    return 0;
}