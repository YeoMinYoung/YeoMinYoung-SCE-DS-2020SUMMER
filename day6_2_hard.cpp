#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class List
{
public:
    Node* head;
    Node* tail;
    List() {
        head = tail = NULL;
    }
    void addBack(int x) {
        Node* new_Node = new Node();
        new_Node->data = x;
        if (head == NULL)
            head = tail = new_Node;
        else
        {
            tail->next = new_Node;
            tail = new_Node;
        }
    }
    void removeFront() {
        if (head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

class queue
{
public:
    int s;
    List* list;
    queue() {
        s = 0;
        list = new List();
    }
    void push(int x) {
        list->addBack(x);
        s++;
    }
    void pop() {
        if (s == 0)
            return;
        list->removeFront();
        s--;
    }
    bool empty() {
        if (s == 0)
            return true;
        else
            return false;
    }
    int size() {
        return s;
    }
    int front() {
        return list->head->data;
    }
};

int main() {

    int test_case;
    cin >> test_case;
    int n;
    queue q1;
    queue q2;
    int x;

    for (int i = 0; i < test_case; i++) {
        int win[2] = { 0, };
        int carry[2] = { 0, };
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            q1.push(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            q2.push(x);
        }
        int a, b;
        for (int i = 0; i < n; i++) {
            a = q1.front() + carry[0];
            b = q2.front() + carry[1];
            if (a > b)
            {
                win[0]++;
                carry[0] = a - b - 1;
                carry[1] = 0;
            }
            else if (a < b)
            {
                win[1]++;
                carry[1] = b - a - 1;
                carry[0] = 0;
            }
            else {
                carry[0] = carry[1] = 0;
            }
            q1.pop();
            q2.pop();
        }
        if (win[0] > win[1])
            cout << "1" << "\n";
        else if (win[0] < win[1])
            cout << "2" << "\n";
        else
            cout << "0" << "\n";
    }

    return 0;
}