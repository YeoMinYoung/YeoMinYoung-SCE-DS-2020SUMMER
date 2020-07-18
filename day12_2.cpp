#include<iostream>
#include<vector>
#include<string>
#define MAX 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class item {
public:
    int key;
    int value;
    int flag;
    item() {
        key = value = flag = 0;
    }
};
item hashtable[MAX];
int hashfunc1(int x) {
    return x % MAX;
}
int hashfunc2(int x) {
    return 17 - (x % 17);
}
void insert(int x) {
    int idx = hashfunc1(x);
    int i = idx;
    int k = hashfunc2(x);
    int probing = 1;
    while (hashtable[i].flag == ISITEM) {
        i = (i + k) % MAX;
    }
    hashtable[i].key = x;
    hashtable[i].flag = ISITEM;
}
void search(int x) {
    int idx = hashfunc1(x);
    int k = hashfunc2(x);
    int i = idx;
    int probing = 1;
    while (hashtable[i].flag != NOITEM) {
        if (hashtable[i].key == x) {
            break;
        }
        i = (i + k) % MAX;
        probing++;
    }
    if (hashtable[i].key == x)
        cout << 1 << " " << probing << "\n";

    else cout << 0 << " " << probing << "\n";
}
void clear() {
    for (int i = 0; i < MAX; i++) {
        hashtable[i].key = 0;
        hashtable[i].flag = NOITEM;
    }
}
int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, m, x;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            insert(x);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x;
            search(x);
        }
        clear();
    }

    return 0;
}