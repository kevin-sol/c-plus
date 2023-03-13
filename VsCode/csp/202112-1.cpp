#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, N;
    scanf("%d %d", &n, &N);
    vector<int> A(n + 1);
    A[0] = 0;
    int f[N];
    for (int i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    f[0] = 0;
    for (int i = 1; i < N; i++) {
        int j = f[i - 1];
        for (; j < n + 1; j++) {
            if (j == n && A[n] <= i) {
                f[i] = j;
                break;
            } else if (A[j] <= i && A[j + 1] > i) {
                f[i] = j;
                break;
            }
        }
    }
    int sum = 0;
    for (auto &&i : f) {
        sum += i;
    }
    printf("%d", sum);
    system("pause");
    return 0;
}
