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
    int flag;
    item() {
         key = flag = 0;
    }
};

item hashtable[MAX];

int hashfunc(int x) {
    return x % MAX;
}

void insert(int x) {
    int idx = hashfunc(x);
    int i = idx;
    int probing = 1;
    while (hashtable[i].flag == ISITEM) {
        i = (i + 1) % MAX;
        probing++;
    }
    hashtable[i].key = x;
    hashtable[i].flag = ISITEM;
}
void delhash(int x) {
    int idx = hashfunc(x);
    int i = idx;
    int probing = 1;
    while (hashtable[i].flag != NOITEM) {
        if (hashtable[i].key == x) {
            break;
        }
        i = (i + 1) % MAX;
        probing++;
    }
    if (hashtable[i].key == x) {
        hashtable[i].key = 0;
        hashtable[i].flag = AVAILABLE;
        cout << 1 << " " << probing << "\n";
    }
    else {
        cout << 0 << " " << probing << "\n";
    }
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
            delhash(x);
        }
        clear();
    }

    return 0;
}