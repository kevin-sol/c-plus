#include <iostream>
using namespace std;

int BdaoD(int b, string n)//从b进制转换到十进制
{
    int  num = 0,B=1;
    for (int i = n.size() - 1; i >= 0; i--,B*=b )//从n的最后一位开始，B为b进制对应的次幂
    {
        int k;//k为字符表示的十进制大小
        if (n[i] >= 'A')//判断是否为大写字符
        {
            k = n[i] - 'A' + 10;//计算表示的十进制大小
        }
        else
            k = n[i] - '0';
        //总数+=k*（b进制的对应次幂）
        num += k * B;
    }
    return num;
}
int main()
{
    string n;
    cin >> n;
    printf("%ld", BdaoD(16, n));
    return 0;
}
