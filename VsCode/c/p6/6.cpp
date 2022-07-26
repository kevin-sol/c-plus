#include <iostream>
using namespace std;
int a[4][4] = {0};//最大为4x4

void input(int n)//输入
{
    for (int i = 0; i < n; i++)
    {
        char ch[5];
        cin.getline(ch, 5); //这个地方get和getline的区别
        for (int j = 0; j < n; j++)
        //若是'.'就令其为0，若是'X'令值为-1
        {
            if (ch[j] == 'X')
            {
                a[i][j] = -1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
}

void Martix(int n)//计算最多摆放的个数
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        //从左向右从上到下依次检查矩阵
        {
            if (a[i][j] == 0)
            //为零表示可以摆放，并且向上下左右扩散为1表示不可摆放直至遇到-1即X或超出
            {
                for (int k = j + 1; k < n; k++)//向右扩散
                {
                    if (a[i][k] == -1)
                        break;
                    if (a[i][k] == 0)
                        a[i][k] = 1;
                }
                for (int k = j - 1; k >= 0; k--)//向左
                {
                    if (a[i][k] == -1)
                        break;
                    if (a[i][k] == 0)
                        a[i][k] = 1;
                }
                for (int k = i + 1; k < n; k++)//向下
                {
                    if (a[k][j] == -1)
                        break;
                    if (a[k][j] == 0)
                        a[k][j] = 1;
                }
                for (int k = i - 1; k >= 0; k--)向上
                {
                    if (a[k][j] == -1)
                        break;
                    if (a[k][j] == 0)
                        a[k][j] = 1;
                }
            }
        }
    }
}

void output(int n)//输出
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)//为0表示表示摆放的位置，为1表示不可摆放，为-1表示X
            {
                cnt++;
            }
        }
    }
    /*这个地方主要排除一种特殊情况，就是放在a[0][0]的位置
    第一行和第一列没有X都不可以摆放，但是第二行或者第二列存在至少一个X时
    第一行与第二列可以存放两个，但是计算只有一个，所以在这里进行检测更正*/
    int ret =1;
    for (int i = 1; i < n; i++)//检测是否有X
    {
        if (a[1][i]==-1||a[i][1]==-1)
        {
            ret=1;
            break;
        }
        else ret=0;
    }
    for (int i = 1; i < n; i++)//检测第一行与第二行是否全为1
    {
        if (a[0][i]==0||a[i][0]==0)
        {
            ret=0;
            break;
        }
        
    }
    
    if (ret==1)//若满足，则应该再添加一个
    {
        cnt++;
    }
    
    
    printf("%d\n", cnt);
}
int main()
{
    int n;
    while (true)
    {
        cin >> n;
        cin.get();//消去回车的影响
        if (n==0)break;//停止
        input(n);
        Martix(n);
        output(n);
    }
    return 0;
}