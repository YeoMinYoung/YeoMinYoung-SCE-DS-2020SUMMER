//2-2-2  set at 추가 !!!! 함수로.
//메인에서 ans, cnt 배열
#include<iostream>
#include<cmath>
using namespace std;

class Array
{
public:
    int * arr;
    Array(int size) {
        arr = new int[size];
    }
    void set(int i, int x) {
        arr[i] = x;
    }
    int at(int i) {
        return arr[i];
    }
};

int main()
{
    int test_case;
    cin >> test_case;
    int m, x;
    double p;
    for (int i = 0; i < test_case; i++)
    {
        Array cnt(3);
        Array ans(3);
        cin >> m;
        for (int i = 0; i < 3; i++)
        {
            cnt.set(i, 0);
            ans.set(i, 0);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (i % 3 == 0) {
                ans.set(0, ans.at(0) + x);//easy와 같이.
                if (x != 0)
                    cnt.set(0, cnt.at(0) + 1); 
                //cnt배열은 우리가 지금 나라당 평균금액을 알아야 하므로
                // 금고가 빈 거 빼고 갯수를 세서 나라마다 합의 배열인 ans을
                // 빈 금고 제외한 숫자로 나눠줘야함.
                //그래서 x=0이면 빈금고 이므로 이거 제외하고( x!=0)
                //x가 0 아닐 때 마다 배열의 원소에다가 카운팅을 +1해준다.
            }
            else if (i % 3 == 1) {
                ans.set(1, ans.at(1) + x);
                if (x != 0)
                    cnt.set(1, cnt.at(1) + 1);
            }
            else if (i % 3 == 2) {
                ans.set(2, ans.at(2) + x);
                if (x != 0)
                    cnt.set(2, cnt.at(2) + 1);
            }
        }
        for (int i = 0; i < 3; i++)
            cout << ans.at(i) << " ";
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            if (cnt.at(i) == 0)
                cout << "0" << " ";
            else {
                p = ans.at(i) / cnt.at(i);
                cout << floor(p) << " ";
            }
        }
        cout << "\n";

    }

    return 0;
}