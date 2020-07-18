#include<iostream>
#include<vector>
#include<string>
using namespace std;

enum direction { Max = -1, Min = 1 };
class Heap {
public:
    vector<int> v;
    int heap_size;
    int direction;
    Heap(int dir) {
        heap_size = 0;
        v.push_back(-1);
        direction = dir;
    }
    bool isEmpty() {
        return heap_size == 0;
    }
    int size() {
        return heap_size;
    }
    int top() {
        if (!isEmpty()) return v[1];
        else return -1;
    }
    void swap(int x, int y) {
        int tmp = v[x];
        v[x] = v[y];
        v[y] = tmp;
    }
    void upHeap() {
        int idx = heap_size;
        while (idx > 1) {
            if (v[idx] * direction < v[idx / 2] * direction) {
                swap(idx, idx / 2);
                idx = idx / 2;
            }
            else break;
        }
    }
    void downHeap() {
        int idx = 1;
        int t_idx;
        while (2 * idx <= heap_size) {
            int left = 2 * idx;
            int right = (2 * idx) + 1;
            if (right <= heap_size) {
                if (v[left] * direction <= v[right] * direction)
                    t_idx = left;
                else t_idx = right;
            }
            else t_idx = left;

            if (v[t_idx] * direction < v[idx] * direction) {
                swap(t_idx, idx);
                idx = t_idx;
            }
            else break;
        }
    }

    void insert(int x) {
        v.push_back(x);
        heap_size++;
        upHeap();
    }
    int remove() {
        int t = top();
        if (!isEmpty()) {
            v[1] = v[heap_size];
            heap_size--;
            v.pop_back();
            downHeap();
        }
        return t;
    }
    void print() {
        if (isEmpty())
            cout << -1 << "\n";
        else {
            for (int i = 1; i <= heap_size; i++)
                cout << v[i] << " ";
            cout << "\n";
        }
    }
};
int main() {

    int test_case;
    cin >> test_case;
    string str;
    Heap h(1);
    int x;
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        if (str == "insert") {
            cin >> x;
            h.insert(x);
        }
        else if (str == "pop") {
            x = h.remove();
            cout << x << "\n";
        }
        else if (str == "isEmpty")
            cout << h.isEmpty() << "\n";
        else if (str == "size")
            cout << h.size() << "\n";
        else if (str == "top")
            cout << h.top() << "\n";
        else if (str == "print")
            h.print();
    }
    return 0;
}