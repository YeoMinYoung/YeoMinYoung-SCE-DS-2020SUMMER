#include<iostream>
#include<vector>
using namespace std;

class Heap {
public:
    int heapsize;
    int dir;
    vector<int> v;
    Heap(int d) {
        heapsize = 0;
        dir = d;
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
            if (v[idx] * dir < v[idx / 2] * dir) {
                swap(idx, idx / 2);
                idx = idx / 2;
            }
            else break;
        }
    }
    void downHeap() {
        int idx = 1;
        int t_idx;
        while (2 * idx <= heapsize) {
            int left = 2 * idx;
            int right = 2 * idx + 1;
            if (right <= heapsize) {
                if (v[left] * dir <= v[right] * dir) t_idx = left;
                else t_idx = right;
            }
            else t_idx = left;

            if (v[idx] * dir > v[t_idx] * dir) {
                swap(idx, t_idx);
                idx = t_idx;
            }
            else break;
        }
    }
    void insert(int x) {
        v.push_back(x);
        heapsize++;
        upHeap();
    }
    void pop() {
        v[1] = v[heapsize];
        heapsize--;
        v.pop_back();
        downHeap();
    }
    int top() {
        return v[1];
    }
};

int main() {
    int test_case;
    cin >> test_case;
    int n, p, x;
    for (int i = 0; i < test_case; i++) {
        cin >> n >> p;
        Heap min(1);
        Heap max(-1);
        for (int j = 0; j < n; j++) {
            cin >> x;
            min.insert(x);
            max.insert(x);
        }
        cout << min.v[p] << "\n";
        for (int j = 1; j < p; j++)
            min.pop();
        cout << min.top() << "\n";
        cout << max.v[p] << "\n";
        for (int j = 1; j < p; j++)
            max.pop();
        cout << max.top() << "\n";
    }
    return 0;
}