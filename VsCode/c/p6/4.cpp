#include<stdio.h>
#include<stdlib.h>

int Martix(int m,int n){
    if (m>n)//m>n,矩形变成（m-n）*n，个数加一
    {
        return Martix(m-n,n)+1;
    }
    else if (m<n)
    {
        return Martix(m,n-m)+1;//m<n,矩形变成m*(n-m)，个数加一
    }
    //m=n 只能分出一个，个数+1
    else return 1;
}


int main(){
    int m,n;
    scanf("%d %d",&m,&n);//一个m*n的矩形
    printf("%d",Martix(m,n));
    return 0;
}