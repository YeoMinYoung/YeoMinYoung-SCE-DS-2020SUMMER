#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ntree
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    void preorder(vector<vector<int>>& v, int n)
    {
        cout << n << ' ';
        for (int p : v[n])
        {
            preorder(v, p);
        }
    }
    void postorder(vector<vector<int>>& v, int n)
    {
        for (int p : v[n])
        {
            postorder(v, p);
        }
        cout << n << ' ';
    }
};

int main()
{
    int time;
    cin >> time;
    while (time--)
    {
        ntree t;
        vector<vector<int>> a(100001);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            a[t1].push_back(t2);
        }
        t.preorder(a, 1);
        cout << '\n';
        t.postorder(a, 1);
        cout << '\n';


    }
}