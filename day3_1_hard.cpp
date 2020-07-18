//3-1-2

#include<iostream>
#include<string>

using namespace std;


///명령어 처리하는 링크드 리스트는 클래스를 링크드리스트로 만들자 .나머진 다 리스트클래스..
//그리고 프렌드도 여기서만, 디스도 여기서만.
//그리고 다른 문제는 int size는 리스트 다음에 큐나 스택에서 처리했지만
//여기선 링크드 리스트 안에서 사이즈를 처리해주기.
//왜냐면 여긴 노드-링크드리스트-메인 이기 때문이다.
//removeFront에서 사이즈 구간별 세개.

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

    void addFront(int X) {
        Node* node = new Node(X);
        node->next = head;//맨 앞에 x추가니까 노드가 가리키는 넥스트를 헤드로 연결.
        //그럼 헤드 바로 전에 x 추가, 즉 맨 앞에 x 추가됨.
        head = node;
        if (size == 0)
            tail = head;//if 사이즈 0이면, 한개 추가된 x가 헤드이자 테일
        size++;
    }

    void removeFront() {
        if (size == 1)
        {
            cout << head->data << "\n"; //size==1일 경우 헤드가 가리키는 데이타.즉 헤드의
            //데이타를 출력하고 줄 띄움.
            head = tail = NULL;
            //헤드에 있는 데이터 삭제하고 출력했으니 아무 수도 없음. 즉 헤드와 테일은 NULL
            size = 0;
            //아무 수도 없으니 사이즈는 0.
        }
        else if (size > 1) {
            Node* remove = head; //remove에 헤드의 주솟값 저장
            cout << remove->data << "\n"; //저장된 헤드가 가리키는 데이터를 출력
            head = head->next;// 헤드에 헤드가 가리키는 넥스트포인터를 저장해놓음.remove에도 저장됨.
            delete remove; //remove 삭제.
            size--; //하나 삭제되었으므로 사이즈 1 감소
        }
        else {
            cout << -1 << "\n";
        } //리스트 비어있는 경우 -1 출력
    }

    void front()
    {
        if (head == NULL) {
            cout << -1 << "\n";
        } //리스트 비어있는 경우 -1 출력
        else
        {
            cout << head->data << "\n";
        }//헤드가 가리키는 데이터를 출력
    }

    void empty()
    {
        if (head == NULL) {
            cout << 1 << "\n";
        }//리스트 비어있으면 1 출력
        else {
            cout << 0 << "\n";
        }//리스트 안비어있으면 0 출력
    }
    void showList()
    {
        if (head == NULL) {
            cout << -1 << "\n";
        }//리스트 비었을 때 -1 출력
        else
        {
            Node* scan = head;//스캔 포인터를 만들어서 헤드를 저장
            while (scan != NULL) { //tail 까지
                cout << scan->data << " "; //저장된 데이터들을 연결해서 출력
                scan = scan->next; // next NULL을 연결해줌 스캔에
            }
            cout << "\n";
        }
    }

    void addBack(int X)
    {
        Node* node = new Node(X);
        tail->next = node;// 맨 뒤에 추가해야 되니까 tail은 NULL을 가리키게. 여기에 추가
        //해야 되니까 빈 NULL공간 생성
        tail = node; //tail = node 해서 빈공간 줌.
        if (size == 0) {
            head = tail;
        }
        size++;// 마지막에 한개 추가됐으니까 사이즈 1 증가

    }
};

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
        else if (str == "showList") {
            list.showList();
        }
        else if (str == "addBack") {
            int X;
            cin >> X;
            list.addBack(X);
        }
    }
    return 0;
}





//클래스 안에서 함수 안하는 방법

/*#include<iostream>
#include<string>

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
    void showList();
    void addBack(int X);
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

void LinkedList::showList()
{
    if (head == NULL) {
        cout << -1 << "\n";
    }
    else
    {
        Node* scan = head;
        while (scan != NULL) {
            cout << scan->data << " ";
            scan = scan->next;
        }
        cout << "\n";
    }
}

void LinkedList::addBack(int X)
{
    Node* node = new Node(X);
    tail->next = node;
    tail = node;
    if (size == 0) {
        head = tail;
    }
    size++;

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
        else if (str == "showList") {
            list.showList();
        }
        else if (str == "addBack") {
            int X;
            cin >> X;
            list.addBack(X);
        }
    }
    return 0;
}
*/