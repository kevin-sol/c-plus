#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    int a[n],b[n],c[n+1];
    c[0]=1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i < n+1; i++)
    {
        c[i]=1;
        for (int j = 0; j < i; j++)
        {
            c[i]*=a[j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        b[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        
    }
    
    
    system("pause");
    return 0;
}
