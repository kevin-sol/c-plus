#include <iostream>
#include <algorithm>
using namespace std;
/*dp*/
#define maxn 300010
int dp[40][maxn] = {{0}};
int a[40] = {0};
int main(int argc, char const *argv[])
{
    int n, x;
    scanf("%d %d", &n, &x);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    int m = sum - x;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (j < a[i]) {
                dp[i][j] = dp[i - 1][j];
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
        }
    }
    printf("%d\n", sum - dp[n][m]);
    system("pause");
    return 0;
}

/* dfs
int n, x;
int mins = 3e5;
vector<int> a;
vector<int> b;
void dfs(int i, int sum)
{
    if (i > n) {
        return;
    }
    if (sum + b[n] - b[i] < x) {
        return;
    } else if (sum >= x) {
        mins = min({mins, sum});
    }
    dfs(i + 1, sum + a[i]);
    dfs(i + 1, sum);
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &x);
    b.push_back(0);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a.push_back(num);
        b.push_back(num + b[i]);
    }
    dfs(0, 0);
    printf("%d", mins);
    system("pause");
    return 0;
}*/
