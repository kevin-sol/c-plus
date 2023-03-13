#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> t(n), c(n), q(m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &t[i], &c[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &q[i]);
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (q[i] + k <= t[j] && t[j] < q[i] + k + c[j]) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    system("pause");
    return 0;
}
