#include <iostream>
#include <vector>
#include <string>
using namespace std;

class tree
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int depth(vector<vector<int>>& v, int start, int h)
    {
        if (v[start].size() == 0)
            return h;
        int d = 0;
        for (int p : v[start])
        {
            d = max(depth(v, p, h + 1), d);
        }
        return d;
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
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        tree t;
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
        cout << t.depth(a, 1, 0) << '\n';

    }
}