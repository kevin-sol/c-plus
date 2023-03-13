#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int max = 0, min = 0;
    int last = 0;
    for (const auto &i : b) {
        if (i != last) {
            min += i;
        }
        max += i;
        last = i;
    }
    printf("%d\n%d\n", max, min);
    system("pause");
    return 0;
}
