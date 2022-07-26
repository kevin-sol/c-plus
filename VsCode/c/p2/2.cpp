#include <stdio.h>
#include <stdlib.h>

bool Runyear(int year)//判断闰年
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

void caldays(int y,int m,int d){
//2014年6月2日也是小粽子同学的18岁生日。
//可以推算出小粽子同学出生于星期日，经历了6575天（出生当天也算1天）
    int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //非闰年时天数
    int days=1;
    while (y!=2014||m!=6||d!=2)//从输入日期那天计算，days++，直到日期为2014.6.2
    {
        if (Runyear(y))//闰年29天
        {
            day[1] = 29;
        }
        else{//非闰年28天
            day[1]=28;
        }
        d++;
        days++;
        if (d > day[m - 1])//天数超出，d归一，月份+1
        {
            d = 1;
            m++;
            if (m > 12)//月份超出，year++，月份归一
            {
                m = 1;
                y++;
            }
        }
    }
    printf("%d\n",days);//计算出天数
    int n=(6575-1+7)%7;//计算出2014年6月2日是星期几
    printf("%d",(n-((days-1)%7)+7)%7);
    //(days-1)%7求与星期n差几天,n-((days-1)%7)则拿星期n减去天数，为了防止天数大于n，则再加7再mod7就可以
}
int main(){
    int y,m,d;
    scanf("%d-%d-%d",&y,&m,&d);
    caldays(y,m,d);
    return 0;
}