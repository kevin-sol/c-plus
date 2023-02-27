#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    vector<pair<int, int>> d_i(n);
    for (int i = 0; i < n; i++) {
        d_i[i].first = pow(X[i] - x, 2) + pow(Y[i] - y, 2);
        d_i[i].second = i;
    }
    sort(d_i.begin(), d_i.end());
    for (int i = 0; i < 3; i++) {
        printf("%d\n", 1 + d_i[i].second);
    }
    system("pause");
    return 0;
}
