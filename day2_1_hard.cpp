#include<iostream>
#include<string>
using namespace std;

class Array
{
public:
    int n;
    int* arr;
    Array(int size) {
        n = 0;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }
    void at(int i) {
        cout << arr[i] << "\n";
    }
    void set(int i, int x) {
        if (arr[i] == 0)
            cout << "0" << "\n";
        else
            arr[i] = x;
    }
    void add(int idx, int x) {
        if (arr[idx] == 0)
            arr[n] = x;
        else
        {
            for (int i = n; i > idx; i--)
                arr[i] = arr[i - 1];
            arr[idx] = x;
        }
        n++;
    }
    void remove(int idx) {
        if (arr[idx] == 0)
            cout << "0\n";
        else {
            cout << arr[idx] << "\n";
            for (int i = idx; i < n; i++)
                arr[i] = arr[i + 1];
            n--; ///포문안에 안들어가게 조심조심조심조심조심.
        }
    }
    void printArray() {
        if (n == 0)
            cout << "0\n";
        else {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }


};

int main()
{
    string str;
    Array arr(10000);
    int m;
    cin >> m;
    int idx, x;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str == "at") {
            cin >> idx;
            arr.at(idx);
        }
        else if (str == "set") {
            cin >> idx >> x;
            arr.set(idx, x);
        }
        else if (str == "add") {
            cin >> idx >> x;
            arr.add(idx, x);
        }
        else if (str == "remove") {
            cin >> idx;
            arr.remove(idx);
        }
        else if (str == "printArray")
            arr.printArray();

    }

    return 0;
}