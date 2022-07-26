#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Isprime(int n)//判断素数
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    double m = sqrt(n);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void Luan(long int n)
{
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        //判断i和i+1是否为素数且i+1不超出n 或者 判断i和i+2是否为素数且i+2不超出
        if ((Isprime(i) && Isprime(i + 1) && i + 1 <= n) || (Isprime(i) && Isprime(i + 2) && i + 2 <= n))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
}
int main()
{
    long int n;
    scanf("%d", &n);
    Luan(n);
    return 0;
}
