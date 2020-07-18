#include <iostream>
#include <string>
#define MAX 10001
using namespace std;

class stack {
public:
    int length;
    int arr[MAX];

    stack() : length(0) {}

    void push(int x) {
        arr[++length] = x;
    }

    int empty() {
        if (length) return 0;
        else return 1;
    }

    int top() {
        if (empty())	return -1;
        else return arr[length];
    }

};

int main() {
    int n;
    string str;
    stack s;
    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push") {
            int k;
            cin >> k;
            s.push(k);
        }
        else if (str == "empty") {
            cout << s.empty() << endl;
        }
        else if (str == "top") {
            cout << s.top() << endl;
        }
    }
    return 0;
}




//list 이용해서 구현
/*
#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node()
    {
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

    void addFront(int x) {
        Node* new_Node = new Node();
        new_Node->data = x;
        if (head == NULL)
            head = tail = new_Node;
        else {
            new_Node->next = head;
            head = new_Node;
        }
    }
    int removeFront() {
        if (head == NULL)
            return -1;
        Node* temp = head;
        int x = head->data;
        head = head->next;
        delete temp;
        return x;
    }
};

class stack
{
public:
    List* list;
    int s;
    stack() {
        list = new List();
        s = 0;
    }
    void push(int x) {
        list->addFront(x);
        s++;
    }
    int pop() {
        if (s == 0)
            return -1;
        else {
            s--;
            return list->removeFront();
        }
    }
    int top() {
        if (s == 0)
            return -1;
        return list->head->data;
    }
    int empty() {
        if (s == 0)
            return 1;
        return 0;
    }
    int size() {
        return s;
    }
};

int main()
{
    string str;
    stack s;
    int x;
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        if (str == "push") {
            cin >> x;
            s.push(x);
        }
        else if (str == "pop")
            cout << s.pop() << "\n";
        else if (str == "empty")
            cout << s.empty() << "\n";
        else if (str == "size")
            cout << s.size() << "\n";
        else if (str == "top")
            cout << s.top() << "\n";
    }
    return 0;
}*/