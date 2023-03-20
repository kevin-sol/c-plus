#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[4] = {0};
    int k = 1;
    for (int i = 0; i < n; i++) {
        if (k % 7 == 0 || to_string(k).find('7') < to_string(k).size()) {
            i--;
            a[(k - 1) % 4]++;
        }
        k++;
    }
    for (auto &&it : a) {
        printf("%d\n", it);
    }
    system("pause");
    return 0;
}
