#include <iostream>
#include <math.h>
int main(int argc, char const *argv[])
{
    int n;
    double j;
    scanf("%d %lf", &n, &j);
    int income[n + 1];
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", income + i);
    }
    double total = 0;
    for (int i = 0; i < n + 1; i++) {
        total += income[i] * pow(1 + j, -i);
    }
    printf("%lf", total);
    system("pause");
    return 0;
}
