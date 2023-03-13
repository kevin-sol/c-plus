#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> x(k), y(k), state(n, 0);
    state[0] = 1;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 0; i < k; i++) {
        if (state[y[i]] == 0) {
            cnt++;
        }
        state[x[i]] = 1;
    }
    printf("%d", cnt);
    system("pause");
    return 0;
}
