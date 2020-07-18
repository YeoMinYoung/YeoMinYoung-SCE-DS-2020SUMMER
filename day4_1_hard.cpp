#include <iostream>
#include <string>
#define MAX 10001
using namespace std;

class stack {
public:
    int length;
    int arr[MAX];

    stack() : length(0) {}

    int empty() {
        if (length) return 0;
        else return 1;
    }

    int top() {
        if (empty())	return -1;
        else return arr[length];
    }

    void push(int x) {
        arr[++length] = x;
    }

    int pop() {
        if (empty())	return -1;
        else return arr[length--];
    }

    int size() {
        return length;
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
        else if (str == "pop") {
            cout << s.pop() << endl;
        }
        else if (str == "size") {
            cout << s.size() << endl;
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