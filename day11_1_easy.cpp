#include<iostream>
using namespace std;

class Node {
public:
    int data;
    int depth;
    int degree;
    Node* parent;
    Node* left;
    Node* right;
    Node() {
        parent = NULL;
        left = NULL;
        right = NULL;
        data = depth = degree = 0;
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
    Node* search(Node* root, int x) {
        if (root == NULL)
            return NULL;
        if (root->data == x)
            return root;
        else if (root->data > x)
            return search(root->left, x);
        else
            return search(root->right, x);
    }
    void insert(int x) {
        Node* new_Node = new Node();
        new_Node->data = x;
        Node* curr = root;
        Node* par = NULL;

        while (curr != NULL) {
            par = curr;
            if (curr->data > x) curr = curr->left;
            else curr = curr->right;
        }
        if (par == NULL) root = new_Node;
        else if (par->data > x) par->left = new_Node;
        else par->right = new_Node;

        new_Node->parent = par;
        
        if (par != NULL) {
            new_Node->depth = par->depth + 1;
            par->degree++;
        }
        if (height < new_Node->depth) height = new_Node->depth;
    }
    void trans(Node* p, Node* c) {
        if (p == root) root = c;
        else if (p->parent->right == p) p->parent->right = c;
        else p->parent->left = c;
        if (c != NULL) c->parent = p->parent;
    }
    void remove(int x) {
        Node* curr = search(root, x);
        if (curr->left == NULL && curr->right == NULL) {
            if (curr == root) root = NULL;
            else {
                if (curr->parent->left == curr) curr->parent->left = NULL;
                else curr->parent->right = NULL;
            }
        }
        else if (curr->left == NULL && curr->right != NULL) {
            trans(curr, curr->right);
        }
        else if (curr->left != NULL && curr->right == NULL) {
            trans(curr, curr->right);
        }
        else {
            Node* n = curr->right;
            while (n->left != NULL) n = n->left;
            if (n != curr->right) {
                trans(n, n->right);
                n->right = curr->right;
                curr->right->parent = n;
            }
            trans(curr, n);
            n->left = curr->left;
            curr->left->parent = n;
        }
        delete curr;
    }
    void structure(Node* n) {
        if (root == NULL)
            return;

        if (n->left != NULL)
            structure(n->left);
        if (n->right != NULL)
            structure(n->right);
        delete n;
    }
};

int main() {

    int test_case;
    cin >> test_case;
    int x, n, m;
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
            Node* n = bst.search(bst.root, x);
            if (n == NULL) cout << "0\n";
            else {
                cout << n->degree << " " << n->depth << "\n";
            }
        }
        bst.structure(bst.root);
    }
    return 0;
}

