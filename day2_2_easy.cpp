
//Array 클래스에서 set at 함수
//메인에서 Array arr(100)과 ans(3)을 만들어줌.

#include<iostream>
using namespace std;

class Array {
public:
    int* arr;
    Array(int size) {
        arr = new int[size];
    }

    void set(int idx, int x) {
        arr[idx] = x;
    }

    int at(int idx) {
        if (arr[idx] == NULL) return  0; // 여기선 빈칸 체크할 떄 null

        return arr[idx];
    }
};

int main()
{
    int test_case;
    int cnt;
    int x;

    cin >> test_case;

    Array arr(100);
    Array ans(3);

    for (int i = 0; i < test_case; i++) {

        for (int i = 0; i < 3; i++) {
            ans.set(i, 0);
        }

        cin >> cnt;

        for (int i = 0; i < cnt; i++) {
            cin >> x;
            arr.set(i, x);
            if (i % 3 == 0) ans.set(0, ans.at(0) + x);
            else if (i % 3 == 1) ans.set(1, ans.at(1) + x);
            else if (i % 3 == 2) ans.set(2, ans.at(2) + x);
        }

        for (int i = 0; i < 3; i++) {
            cout << ans.at(i) << " ";
        }
        cout << "\n";
    }

    return 0;
}