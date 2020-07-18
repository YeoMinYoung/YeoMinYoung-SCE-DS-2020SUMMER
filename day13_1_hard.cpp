#include<iostream>
#include<vector>
using namespace std;

bool vertex[2001];
int mat[2001][2001];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int vcnt, ecnt;
    vcnt = ecnt = 0;
    int x,y;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!vertex[x]) {
            vertex[x] = true;
            vcnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (!vertex[x] || !vertex[y]) cout << -1 << "\n";
        else if (mat[x][y] != 0 || mat[y][x] != 0) cout << "-1\n";
        else {
            mat[x][y] = 1;
            mat[y][x] = 1;
            ecnt++;
        }
    }
    cout << vcnt << " " << ecnt << "\n";
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        if (!vertex[x] || !vertex[y]) cout << "-1\n";
        else if (mat[x][y] == 0 || mat[y][x] == 0) cout << 0 << "\n";
        else if (mat[x][y] == 1 || mat[y][x] == 1) cout << 1 << "\n";
    }
    return 0;
}