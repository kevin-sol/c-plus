#include<stdio.h>
#include<stdlib.h>

int judge(int a,int b){
    int arr[10]={0};//判断两个数是否有重复数字
    for (int i = 0; i < 5; i++)
    {
        int n=a%10;
        arr[n]=1;//若是有某个数字，则数组arr对应的位置值为1
        a=a/10;
    }
    for (int i = 0; i < 5; i++)//与a操作相同
    {
        int n=b%10;
        arr[n]=1;
        b=b/10;
    }
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]==0)//等于零，说明有至少一个数没用到，也就是有重复数字
            return 0;
    }
    //没有重复数字
    return 1;
}
int main(void)
{
    int sum=0;
    for(int i=2;i<=98765/1234;i++){//因为是整数倍，所以倍数最大也就是 98765/01234
        for (int j = 1234; j*i < 98765; j++)
        {
            if (judge(j,j*i))//如果j和j*i不重复，组合数+1
            {
                sum++;
            }
        }
        
    }
    printf("%d",sum);
    return 0;
}