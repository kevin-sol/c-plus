#include <iostream>

bool finish(int n, int m, int t[], int date[])
{
    for (int i = 1; i < m + 1; i++) {
        if (t[i] + date[i] - 1 > n) {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    int p[m + 1] = {0};  // 只可能依赖前面的项目
    for (int i = 1; i < m + 1; i++) {
        scanf("%d", p + i);
    }
    int t[m + 1];
    for (int i = 1; i < m + 1; i++) {
        scanf("%d", t + i);
    }
    int date[m + 1];
    for (int i = 1; i < m + 1; i++) {
        if (p[i] == 0) {
            date[i] = 1;
        } else {
            int pre = 0;
            int j = p[i];
            do {
                pre += t[j];
                j = p[j];
            } while (j != 0);
            date[i] = 1 + pre;
        }
    }
    for (int i = 1; i < m + 1; i++) {
        printf("%d ", date[i]);
    }
    printf("\n");
    if (finish(n, m, t, date)) {
        int maxday[m + 1] = {0};
        for (int i = 1; i < m + 1; i++) {
            maxday[i] = t[i];
        }
        for (int i = m; i > 0; i--) {
            int j = p[i];
            while (j != 0) {
                if (maxday[j] < maxday[i] + t[j]) {
                    maxday[j] = maxday[i] + t[j];
                }
                j = p[j];
            }
        }
        // 输出
        for (int i = 1; i < m + 1; i++) {
            printf("%d ", n - maxday[i] + 1);
        }
    }
    system("pause");
    return 0;
}
