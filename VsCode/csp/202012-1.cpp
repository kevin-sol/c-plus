#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> score(n), w(n);
    for (int i = 0; i < n; i++) {
        int wi, scorei;
        scanf("%d %d", &wi, &scorei);
        w[i] = wi;
        score[i] = scorei;
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += w[i] * score[i];
    }
    printf("%d\n", total > 0 ? total : 0);
    return 0;
}
