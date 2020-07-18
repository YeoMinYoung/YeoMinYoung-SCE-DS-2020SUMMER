#include<iostream>
#include<string>
using namespace std;
//stack 쓸 때 그냥 list에서 함수는 둘다 프론트. 애드프론트, 리무브프론트.
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
    //환형 링크드 리스트가 아니면 그냥 애드프론트 리므부 프론트
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

    void removeFront() {
        if (head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};
class stack
{
public:
    List* list;
    int s;
    stack() {
        list = new List(); //중요 중요 중요 이거 안하면 안나옴.NULL아님!!
        s = 0;
    }
    void push(int x) {
        list->addFront(x);
        s++;
    }
    void pop() {
        if (s == 0)
            return;
        else {
            list->removeFront();
            s--;
        }
    }
    int top() {
        return list->head->data;
    }
    bool empty() {
        if (s == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    int test_case;
    string str;
    cin >> test_case;
    int a, b;
    for (int i = 0; i < test_case; i++) {
        stack s;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '+') {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (str[i] == '-') {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a - b);
            }
            else if (str[i] == '*') {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a * b);
            }
            else
                s.push(str[i] - '0');
        }
        cout << s.top() << "\n";

    }
    return 0;
}