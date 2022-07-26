#include <stdio.h>
int main()
{
    int F = 1, yixiang = 1, c = 0, a = 0, b = 0;
    // a为变量系数，b为常量,c记录每一个输入的数字，F记录符号
    char ch, x;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            x = ch; //用x记录变量名
            if (c == 0)
                c = 1;            //前面如果没有系数，则系数是1
            a += F * c * yixiang; //含参变量
            c = 0;                //让c重置
        }
        //是数字，用c记录值
        else if (ch >= '0' && ch <= '9')
            c = c * 10 + ch - '0';
        //否则是运算符号
        else
        {
            b += F * yixiang * c; //数字总和
            c = 0;       //归0
            F=1;//F归正为1
            if (ch == '=')
                yixiang = -1; //等号右边移到左边
            else if (ch == '-')
                F = -1;
        }
    }
    printf("%c=%.3f", x, -(float)b / (float)a); // ax+b=0;则x=-b/a;
    return 0;
}