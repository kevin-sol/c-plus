
#include <stdio.h>
#include <stdlib.h>

bool Runyear(int year)//判断是否为闰年
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}
void caldate(int days)
{
    // 1777年4月30日。
    int year = 1777, mon = 4, day = 30;
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //非闰年时天数

    while (days != 0)//从出生日期开始，每次days减一直到为零
    {
        if (Runyear(year))//若是闰年，二月为29天
        {
            d[1] = 29;
        }
        else{//不是闰年，二月为28天
            d[1]=28;
        }
        day++;
        days--;
        if (day > d[mon - 1])//超出这个月天数，天数归1，月份加一
        {
            day = 1;
            mon++;
            if (mon > 12)//超出12月，年数加一，月份归一
            {
                mon = 1;
                year++;
            }
        }
    }
    printf("%d-0%d-%d",year,mon,day);
}
int main(void)
{
    // 5343，因此可算出那天是：1791年12月15日
    // 8113
    caldate(8113-1);
    //因为这里1777年4月30日这一天算第一天，所以运算时会多一天，我们在这里减一天
    return 0;
}