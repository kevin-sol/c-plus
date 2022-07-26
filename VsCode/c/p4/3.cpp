#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Isprime(int n)//与前面相同判断素数的函数
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

void Tongtong(int n){
    for (int i = 2; i *i<= n; i++)
    {
        int m=n/i;
        //这里因为可能n/i不是整数，但是m是整数就不是准确结果了
        //所以下面再添加一个条件判断m是不是因数
        if(Isprime(i)&&Isprime(m)&&m*i==n){
            printf("It's a Tongtong number.\n");
            return;
        }
    }
    printf("It's not a Tongtong number.\n");
}
int main(){
    int n;
    scanf("%d",&n);
    Tongtong(n);
    return 0;
}