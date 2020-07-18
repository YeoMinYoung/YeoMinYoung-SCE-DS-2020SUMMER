#include<iostream>
#include<vector>
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
    void downHeap() {
        int idx = 1;
        int t_idx;
        while (idx * 2 <= heapsize) {
            int left = 2 * idx;
            int right = 2 * idx + 1;
            if (right <= heapsize) {
                if (v[left] * direction <= v[right] * direction)
                    t_idx = left;
                else t_idx = right;
            }
            else t_idx = left;

            if (v[idx] * direction > v[t_idx] * direction) {
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
};
int main() {
    int test_case;
    cin >> test_case;
    int n, x, p;
    Heap h(1);

    for (int i = 0; i < test_case; i++) {
        cin >> n >> p;
        for (int j = 0; j < n; j++) {
            cin >> x;
            h.insert(x);
        }
        cout << h.v[p] << "\n";
        for (int j = 1; j < p; j++)
            h.pop();
        cout << h.v[1] << "\n";
    }
    return 0;
}