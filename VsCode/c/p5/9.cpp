#include <iostream>
using namespace std;

long int BdaoD(int b, long int n)//第一题已经说明，不同的是结果b<=10
{
    int num = 0, B = 1;
    while (n != 0)
    {
        int k= n % 10;
        num += k * B;
        n /= 10;
        B = B * b;
    }
    return num;
}

string DdaoB(long int n,int b){//第二题已经说明
    if (n==0)
    {
        return "0";
    }
    
    string str;
    while (n!=0)
    {
        int m=n%b;
        char c=m+'0';
        str=c+str;
        n/=b;
    }
    return str;
}

int main()
{
    int n, B, b;
    scanf("%d<%d>%d", &n, &B, &b);
    int m = BdaoD(B, n);
    cout<<n<<"<"<<B<<">="<<DdaoB(m,b)<<"<"<<b<<">"<<endl;
    return 0;
}
