#include<iostream>
using namespace std;

string DdaoB(long int n,int b){//第二题已经说明
    if (n==0)//比第二题不同的是可能输入为0，则输出"0"
    {
        return "0";
    }
    
    string str;
    while (n!=0)
    {
        int m=n%b;
        char c;
        if(m<10){
            c=m+'0';
        }
        else{
            c=m+'A'-10;
        }
            str=c+str;
        n/=b;
    }
    return str;
}
int main(){
    long int n;
    cin>>n;
    cout<<DdaoB(n,16)<<endl;
    return 0;
}