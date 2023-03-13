#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
}
