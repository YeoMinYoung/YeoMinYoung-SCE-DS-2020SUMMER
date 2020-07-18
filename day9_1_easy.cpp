#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap {
public:
    int heapsize;
    int direction;
    vector<int> v;
    Heap(int d) {
        heapsize = 0;
        direction = d;
        v.push_back(-1);
    }
    void swap(int x, int y) {
        int tmp = v[x];
        v[x] = v[y];
        v[y] = tmp;
    }
    void upHeap() {
        int idx = heapsize;
        while (idx > 1) {
            if (v[idx] * direction < v[idx / 2] * direction) {
                swap(idx, idx / 2);
                idx = idx / 2;
            }
            else break;
        }
    }
    void insert(int x) {
        v.push_back(x);
        heapsize++;
        upHeap();
    }
    bool isEmpty() {
        return heapsize == 0;
    }
    int size() {
        return heapsize;
    }
    void print() {
        if (heapsize == 0) cout << 0;
        else {
            for (int i = 1; i <= heapsize; i++) {
                cout << v[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    int test_case;
    cin >> test_case;
    int x;
    string str;
    Heap h(1);
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        if (str == "insert") {
            cin >> x;
            h.insert(x);
        }
        else if (str == "size") {
            cout << h.size() << "\n";
        }
        else if (str == "isEmpty") {
            cout << h.isEmpty() << "\n";
        }
        else if (str == "print")
            h.print();
    }
    return 0;
}