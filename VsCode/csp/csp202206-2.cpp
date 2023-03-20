#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*100*/
int main(int argc, char const *argv[])
{
    int n, L, S;
    scanf("%d %d %d", &n, &L, &S);
    vector<vector<int>> B(S + 1, vector<int>(S + 1));
    vector<pair<int, int>> tree(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        tree[i].first = x;
        tree[i].second = y;
        mp[tree[i]] = 1;
    }
    int cnt = n;

    for (int i = S; i >= 0; i--) {
        for (int j = 0; j < S + 1; ++j) {
            scanf("%d", &B[i][j]);
        }
    }
    vector<int> treeexist(n, 1);
    for (int i = 0; i < S + 1; i++) {
        for (int j = 0; j < S + 1; j++) {
            for (int k = 0; k < n; k++) {
                pair<int, int> p(tree[k].first + i, tree[k].second + j);
                if (treeexist[k] == 1 && (tree[k].first > L - S || tree[k].second > L - S)) {
                    cnt--;
                    treeexist[k] = 0;
                    continue;
                } else if ((treeexist[k] == 1) && (mp.count(p) != B[i][j])) {
                    cnt--;
                    treeexist[k] = 0;
                    continue;
                }
            }
        }
    }
    printf("%d\n", cnt);
    system("pause");
    return 0;
}
/*70
using namespace std;
int main()
{
    int n, L, S;
    scanf("%d %d %d", &n, &L, &S);
    vector<vector<int>> A(L + 1, vector<int>(L + 1, 0));
    vector<vector<int>> B(S + 1, vector<int>(S + 1));
    vector<pair<int, int>> tree(1010);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        A[x][y] = 1;
        tree[i].first = x;
        tree[i].second = y;
    }
    for (int i = S; i >= 0; i--) {
        for (int j = 0; j < S + 1; ++j) {
            scanf("%d", &B[i][j]);
        }
    }
    int ret = 0;
    for (const auto &it : tree) {
        if (it.first > L - S || it.second > L - S) {
            continue;
        }
        int f = 0;
        for (int i = 0; i < S + 1; ++i) {
            if (f == 1) {
                break;
            }
            for (int j = 0; j < S + 1; ++j) {
                if (B[i][j] != A[it.first + i][it.second + j]) {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1)
            continue;
        ret++;
    }
    printf("%d\n", ret);
    system("pause");
    return 0;
}
*/