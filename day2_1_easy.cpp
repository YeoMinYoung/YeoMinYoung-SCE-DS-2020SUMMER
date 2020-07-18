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
    void at(int idx) {
        cout << arr[idx] << "\n";
    }
    void set(int idx, int x) {
        if (arr[idx] == 0)
            cout << "0" << "\n";
        else
            arr[idx] = x;
    }
    void add(int idx, int x) {
        if (arr[idx] == 0)
            arr[n] = x;
        else {
            for (int i = n; i > idx; i--)
                arr[i] = arr[i - 1];
            arr[idx] = x;
        }
        n++;
    }

};


int main()
{
    string str;
    Array arr(10000);
    int test_case;
    cin >> test_case;
    int idx, x;
    for (int i = 0; i < test_case; i++) {
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

    }
    return 0;
}