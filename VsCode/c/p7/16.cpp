#include <iostream>
using namespace std;

int main(){
    string C,K;
    cin>>K;//密钥
    cin>>C;//密文
    string M;//明文
    for (int i = 0; i < C.length(); i++)
    {
        //发现密文=明文+（密钥-（A或a））
        //明文=密文-（密钥-（A或a））
        //超出字母表则循环下去
        int k=i%K.length();//使密钥一直循环
        int sub;  
        if(K[k]>='a')sub=K[k]-'a';//计算（密钥-（A或a））
        else sub=K[k]-'A';
        if(C[i]>='a'){//使之对应大小写
            M+=(C[i]-'a'-sub+26)%26+'a';
            //C[i]-'a'-sub为距离'a'的位置，防止为负数，所以+26后再%26最后再加上'a'
        }
        else
        {
            //与上面相同
            M+=(C[i]-'A'-sub+26)%26+'A';
        }
        
    }
    cout<<M<<endl;
    return 0;
}