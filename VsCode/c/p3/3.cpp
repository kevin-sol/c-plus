#include<stdio.h>
#include<stdlib.h>

void Fnum(int *arr){
    int num=0;//记录组数
    int sum=0;
    for(int i=0;i<8;i++){
        sum+=arr[i];
    }
    sum=sum/2;//总和的一半，因为要大于剩下四队，也就是大于一半
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            for(int k=j+1;k<8;k++){
                for (int l = k+1; l < 8; l++)//四个循环表示四个不同的队的排列组合
                {
                    if(arr[i]+arr[j]+arr[k]+arr[l]>sum){//大于一半，num+1
                        num++;
                    }
                }
                
            }
        }
    }
    printf("%d\n",num);
}
int main(){
    int arr[8];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            scanf("%d",&arr[j]);
        }
        Fnum(arr);
    }
    return 0;
}