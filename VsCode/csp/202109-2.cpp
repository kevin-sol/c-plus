#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<pair<int, int>> b;
    int pmax = 0;
    int pmin = 10000;
    b.push_back(pair<int, int>(0, a[0]));
    for (int i = 1; i < n - 1; i++) {
        if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
            b.push_back(pair<int, int>(i, a[i]));
            pmax = pmax < a[i] ? a[i] : pmax;
            pmin = pmin > a[i] ? a[i] : pmin;
        }
    }
    b.push_back(pair<int, int>(n - 1, a[n - 1]));
    int max = 1;
    for (int p = pmax; p >= pmin; p--) {
        int cnt = 0;
        cnt = a[0] < p ? 0 : 1;
        for (int i = 1; i < n; i++) {
            if (a[i] >= p && a[i - 1] < p) {
                cnt++;
            }
        }
        max = cnt > max ? cnt : max;
    }
    printf("%d\n", max);
    system("pause");
    return 0;
}
