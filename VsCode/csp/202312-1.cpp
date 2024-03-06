#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < m; k++) {
                if (s[i][k] >= s[j][k]) {
                    flag = false;
                }
            }
            if (flag) {
                cout << j + 1 << endl;
                break;
            }
        }
        if (j == n) {
            cout << 0 << endl;
        }
    }
}