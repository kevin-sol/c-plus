#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int Isprime(int n)//判断素数，和第一题相同
{
    if (n < 2)return 0;
    if (n==2)return 1;
    double m=sqrt(n);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main(){
    int num=1;
    for (int i = 3;; i+=2)//这里+=2是因为偶数除了2都不是素数
    {
        if (Isprime(i))
        {
            num++;
        }
        if (num==100002)
        {
            printf("%d\n",i);
            break;
        }
    }
    system("pause");
    return 0;
}
