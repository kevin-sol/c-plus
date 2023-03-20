#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> vp(n);
    vector<int> v(n, 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        pair<int, int> p(x, y);
        vp[i] = p;
        mp[p] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x = vp[i].first;
        int y = vp[i].second;
        pair<int, int> p1(x + 1, y);
        pair<int, int> p2(x - 1, y);
        pair<int, int> p3(x, y + 1);
        pair<int, int> p4(x, y - 1);
        if (mp.count(p1) && mp.count(p2) && mp.count(p3) && mp.count(p4)) {
            continue;
        }
        v[i] = 0;
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (v[i] == 0) {
            vp.erase(vp.begin() + j);
            j--;
        }
        j++;
    }
    int a[5] = {0};
    for (int i = 0; i < vp.size(); i++) {
        int x = vp[i].first;
        int y = vp[i].second;
        pair<int, int> p1(x + 1, y + 1);
        pair<int, int> p2(x - 1, y + 1);
        pair<int, int> p3(x + 1, y - 1);
        pair<int, int> p4(x - 1, y - 1);
        int cnt = 0;
        if (mp.count(p1)) {
            cnt++;
        }
        if (mp.count(p2)) {
            cnt++;
        }
        if (mp.count(p3)) {
            cnt++;
        }
        if (mp.count(p4)) {
            cnt++;
        }
        a[cnt]++;
    }
    for (auto &&i : a) {
        printf("%d\n", i);
    }

    system("pause");
    return 0;
}
/*7
1 2
2 1
0 0
1 1
1 0
2 0
0 1*/