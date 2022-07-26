#include<iostream>
#include<algorithm>
using namespace std;

string DdaoB(int n,int b){
//从十进制转换到b进制，转换原理是n一直除以b 得出的余数的倒叙就是对应的b进制下表示
    string str;
    while (n!=0)
    {
        int m=n%b;
        char c;
        if(m<10){//小于是是10以下的字符
            c=m+'0';
        }
        else{//大于等于10为字母代替
            c=m+'A'-10;
        }
            //新得出的字符加在左边从而实现倒叙
            str=c+str;
        n/=b;
    }
    return str;
}

int main()
{
    int b;
    scanf("%d",&b);

    for (int i = 1; i <= 300; i++)
    {
        string str1,str2;
        int x=i*i;//求平方
        str1=str2=DdaoB(x,b);
        reverse(str2.begin(),str2.end());//reveser函数，反转
        if (str1==str2)//相等即对称
        {
            cout<<DdaoB(i,b)<<" "<<str1<<endl;
        }
        
    }
    
    return 0;
}