//3-1-1

#include<iostream>
#include<string>

///명령어 처리하는 링크드 리스트는 클래스를 링크드리스트로 만들자 .나머진 다 리스트클래스..
//그리고 프렌드도 여기서만, 디스도 여기서만.
//그리고 다른 문제는 int size는 리스트 다음에 큐나 스택에서 처리했지만
//여기선 링크드 리스트 안에서 사이즈를 처리해주기.(뒤에 3-2에서도)
//왜냐면 여긴 노드-링크드리스트-메인 이기 때문이다.
//removeFront에서 사이즈 구간별 세개. 

using namespace std;

class Node {
    friend class LinkedList;
    int data;
    Node* next;

    Node(int X) {
        this->data = X;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = tail = NULL;
        this->size = 0;
    }
    void addFront(int X);
    void removeFront();
    void front();
    void empty();  
};

void LinkedList::addFront(int X) {
    Node* node = new Node(X);
    node->next = head;
    head = node;
    if (size == 0)
        tail = head;
    size++;
}

void LinkedList::removeFront() {
    if (size == 1)
    {
        cout << head->data << "\n";
        head = tail = NULL;
        size = 0;
    }
    else if (size > 1) {
        Node* remove = head;
        cout << remove->data << "\n";
        head = head->next;
        delete remove;
        size--;
    }
    else {
        cout << -1 << "\n";
    }
}

void LinkedList::front()
{
    if (head == NULL) {
        cout << -1 << "\n";
    }
    else
    {
        cout << head->data << "\n";
    }
}

void LinkedList::empty() {
    if (head == NULL) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

int main() {
    LinkedList list;
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "addFront")
        {
            int X;
            cin >> X;
            list.addFront(X);
        }
        else if (str == "removeFront") {
            list.removeFront();
        }
        else if (str == "front") {
            list.front();
        }
        else if (str == "empty") {
            list.empty();
        }
    }
    return 0;
}