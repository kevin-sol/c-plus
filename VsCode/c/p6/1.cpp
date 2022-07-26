#include<stdio.h>
#include<stdlib.h>

int DG(int n,int sum){
    if (n==0)//为零说明这种组合结束，组合数+1
    {
        return sum+1;
    }
    else if (n==1)//为1也是下面只能为1，组合数+1
    {
        return sum+1;
    }
    else{//只有1和2两种，所以n的下一步就是n-1和n-2两种，任何n-1和n-2再依次递归下去
        return DG(n-1,sum)+ DG(n-2,sum);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",DG(n,0));
    return 0;
}