#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    string m,n;
    cin>>m;
    cin.get();//消除回车
    cin>>n;
    if (m[0]=='0'||n[0]=='0')//有一个为0则乘积为0
    {
        cout<<0<<endl;
        return 0;
    }
    int a[10000]={0};
    //反转数字字符方便相乘
    reverse(m.begin(),m.end());
    reverse(n.begin(),n.end());
    int k=0,t=0;
    for (int i = 0; i < m.length(); i++)
    {
        for (int  j = 0; j < n.length(); j++)
        {
            //两个数相乘，从最低为开始，个位保存在对应的位置，进位存在下一个位置
            a[k]+=(int)(m[i]-'0')*(int)(n[j]-'0');
            a[k+1]+=a[k]/10;
            a[k]=a[k]%10;
            k++;
        }
        t++;
        k=t;
    }
    //最终结果是倒着的字符串，因为最大位不是0，所以跳过这些后面的0
    int i=9999;
    while (a[i]==0)
    {
        i--;
    }
    for (; i >=0; i--)//倒着输出字符串
    {
        cout<<a[i];
    }
    return 0;
}