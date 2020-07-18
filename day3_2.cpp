#include<iostream>
#include<string>
using namespace std;

//여기선 링크드 리스트 안에서 사이즈를 처리해주기.(뒤에 3-2에서도)
//왜냐면 여긴 노드-리스트-메인 이기 때문이다.
//함수는 addBack, removeFront(Node* n), curr !!!
//반복문으로 while 

class Node {
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
    int s;
    Node* head;
    Node* tail;
    List() {
        s = 0;
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
        tail->next = head;
        s++;
    }
    void removeFront(Node* n) {
        if (s == 0)
            return;
        Node* temp = n;
        Node* curr = head;
        while (curr->next != n) {
            curr = curr->next;
        }
        if (head == n)
            head = head->next;
        else if (tail == n)
            tail = curr;
        curr->next = n->next;
        s--;
        delete temp;
    }
};


int main() {

    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        string str;
        Node* curr;
        List list;
        int x;
        for (int j = 0; j < 10; j++) {
            cin >> x;
            list.addBack(x);
        }
        for (int j = 0; j < 3; j++) {
            curr = list.head;
            cin >> str >> x;
            while (x--)
                curr = curr->next;
            list.removeFront(curr);
        }
        int size = list.s;
        curr = list.head;
        while (size--)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    return 0;
}