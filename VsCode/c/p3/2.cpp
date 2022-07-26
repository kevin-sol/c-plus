#include<stdio.h>
#include<stdlib.h>
void cal(int l){
    int a,b,c;
    int sum=0;
    for ( a = l/2; a >=l/3; a--)//a为最大边，大于l/3小于l/2
    {
        for(b=a;b>0;b--){//b为第二大，小于等于a
            c=l-a-b;
            if (b>=c&&c>0)//c为最小
            {
                if(b*b+c*c==a*a){//判断是否为直角三角形
                    sum++;
                }
            }
        }
    }
    printf("%d\n",sum);
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int l;
        scanf("%d",&l);
        cal(l);
    }
    return 0;
}