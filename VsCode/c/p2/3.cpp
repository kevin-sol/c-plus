
#include <stdio.h>
#include <stdlib.h>

bool Runyear(int year)//判断闰年
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}
void caldate(int year,int mon,int day,int days)
{
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //非闰年时天数

    while (days != 0)
    {
        if (Runyear(year))//闰年29
        {
            d[1] = 29;
        }
        else{//非闰年28
            d[1]=28;
        }
        day++;
        days--;
        if (day > d[mon - 1])
        {
            day = 1;
            mon++;
            if (mon > 12)
            {
                mon = 1;
                year++;
            }
        }
    }
    printf("%d.%d.%d\n",year,mon,day);
}
int main(){
    int y,m,d,days;
    while(~scanf("%d %d %d %d",&y,&m,&d,&days)){
        caldate(y,m,d,days);
    }
    return 0;
}