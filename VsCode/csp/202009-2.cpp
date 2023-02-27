#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k, t, xl, yd, xr, yu;
    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);
    int x[t], y[t];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            scanf("%d %d", x + j, y + j);
        }
        int point = 0;
        int lianxu = 0;
        for (int j = 0; j < t; j++) {
            if (x[j] >= xl && x[j] <= xr && y[j] >= yd && y[j] <= yu) {
                point++;
                lianxu = point > lianxu ? point : lianxu;
            } else {
                point = 0;
            }
        }
        if (lianxu > 0) {
            cnt1++;
        }
        if (lianxu >= k) {
            cnt2++;
        }
    }
    printf("%d\n%d\n", cnt1, cnt2);
    system("pause");
    return 0;
}
