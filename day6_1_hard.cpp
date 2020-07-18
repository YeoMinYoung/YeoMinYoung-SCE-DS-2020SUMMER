#include<iostream>
#include<string>
using namespace std;

/// 환형 리스트랑 큐로 구현한 것들만 addback, removefront.
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
        else {
            tail->next = new_Node;
            tail = new_Node;
        }
    }

    void removeFront() {
        if (head == NULL)
            return;
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class queue
{
public:
    int s;
    List* list;
    queue() {
        s = 0;
        list = new List(); ///존나 중요하다 
    }
    void enqueue(int x) {
        list->addBack(x);
        s++;
    }
    int size() {
        return s;
    }
    int isEmpty() {
        if (s == 0)
            return 1;
        else
            return 0;
    }
    int dequeue() {
        int x = list->head->data;
        list->removeFront();
        s--;
        return x;
    }
    int front() {
        return list->head->data;
    }
    int rear() {
        return list->tail->data;
    }
};

int main()
{
    int S;
    cin >> S;
    int test_case;
    cin >> test_case;
    string str;
    queue q;
    int x;
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        if (str == "enqueue") {
            cin >> x;
            if (q.size() == S)
                cout << "Full" << "\n";
            else
                q.enqueue(x);
        }
        else if (str == "size") {
            cout << q.size() << "\n";
        }
        else if (str == "isEmpty") {
            cout << q.isEmpty() << "\n";
        }
        else if (str == "dequeue") {
            if (q.size() == 0)
                cout << "Empty" << "\n";
            else
                cout << q.dequeue() << "\n";
        }
        else if (str == "front") {
            if (q.size() == 0)
                cout << "Empty" << "\n";
            else
                cout << q.front() << "\n";
        }
        else if (str == "rear") {
            if (q.size() == 0)
                cout << "Empty" << "\n";
            else
                cout << q.rear() << "\n";
        }
    }

    return 0;
}