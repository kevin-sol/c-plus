#include <iostream>
using namespace std;

int Isprime(long int n)//判断素数
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char ch[100];//单词
    cin.getline(ch, 100);
    int max = 0, min = 100;
    int arr[26] = {0};//表示26个字母的个数
    for (int i = 0; i < 100; i++)
    {
        if (ch[i] == '\0')//表示字符结束
            break;
        arr[ch[i] - 'a']++;//字符的个数+1
    }
    for (int i = 0; i < 26; i++)//求最大字符个数和最小字符个数
    {
        if (arr[i] == 0)
            continue;
        ;
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    if (Isprime(max - min))
    {
        cout << "Lucky Word" << endl;
        cout << max - min << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}