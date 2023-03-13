#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n + 1], b[n + 1], c[n + 1];
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        c[i] = c[i - 1] * a[i];
    }
    for (int i = n; i > 0; i--) {
        b[i] = m / c[i - 1];
        m -= b[i] * c[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    system("pause");
    return 0;
}
