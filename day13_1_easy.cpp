#include<iostream>
#include<vector>
using namespace std;

bool vertex[2001];
int matrix[2001][2001];

int main() {
    int n, m;
    cin >> n >> m;
    int x;
    int y;
    int vcnt = 0;
    int ecnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vertex[x] = true;
        vcnt++;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (!vertex[x] || !vertex[y]) cout << -1 << "\n";
        else if (matrix[x][y] != 0 ||  matrix[y][x] != 0) cout << -1 << "\n";
        else {
            matrix[x][y] = 1;
            matrix[y][x] = 1;
            ecnt++;
        }
    }
    cout << vcnt << " " << ecnt << "\n";
    return 0;
}