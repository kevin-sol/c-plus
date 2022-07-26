#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Isprime(long int n)//判断素数
{
    if (n < 2)return 0;//即1
    if (n==2)return 1;
    double m=sqrt(n);//这个地方考虑算法的时间复杂度只用检测到sqrt（n）就可以了
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)//如果能够除尽，说明不是素数
        {
            return 0;
        }
    }
    //为素数
    return 1;
}
int main()
{
    long int n;
    scanf("%d", &n);
    if(Isprime(n))printf("Yes");
    else   printf("No");
    return 0;
}