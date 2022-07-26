#include <iostream>
using namespace std;

void compare(int grade[][2], char s[][15], int n);

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)//输入0结束输入
            break;
        int grade[n][2];//表示分数和AC题数
        char s[n][15];//表示用户名
        for (int i = 0; i < n; i++)
        {
            cin >> grade[i][0] >> grade[i][1];
            cin.get();//消除回车
            cin.getline(s[i], 15);
        }
        compare(grade, s, n);
        cout<<endl;
    }
    return 0;
}

void compare(int grade[][2], char s[][15], int n)
{
    int index[n]; //用来存放顺序
    for (int i = 0; i < n; i++)
    {
        index[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (grade[index[i]][0] < grade[index[j]][0]) //比较第一个数并重新排序
            {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
            else if (grade[index[i]][0] == grade[index[j]][0])//第一个数相等
            {
                if (grade[index[i]][1] < grade[index[j]][1]) //比较第二个数并排序
                {
                    int temp = index[i];
                    index[i] = index[j];
                    index[j] = temp;
                }
                else if (grade[index[i]][1] == grade[index[j]][1]) //比较缩写字符
                {
                    string s1, s2;
                    s1 += s[index[i]][0];
                    s2 += s[index[j]][0];
                    for (int k = 0; k < sizeof(s[index[i]]) / sizeof(char); k++) //计算缩写
                    {
                        if (s[index[i]][k] == ' ')
                            s1 += s[index[i]][k + 1];
                    }
                    for (int k = 0; k < sizeof(s[index[j]]) / sizeof(char); k++)//计算另一个缩写
                    {
                        if (s[index[j]][k] == ' ')
                            s2 += s[index[j]][k + 1];
                    }
                    if (s1 < s2)//比较缩写并排序
                    {
                        int temp = index[i];
                        index[i] = index[j];
                        index[j] = temp;
                    }
                    else if (s1 == s2) //比较整体字符
                    {
                        s1 = s2 = "";
                        for (int k = 0; k < sizeof(s[index[i]]) / sizeof(char); k++) //除去空格
                        {
                            if (s[index[i]][k] == '\0')
                                break;
                            if (s[index[i]][k] == ' ')
                                continue;
                            s1 += s[index[i]][k];
                        }
                        for (int k = 0; k < sizeof(s[index[i]]) / sizeof(char); k++)//除去空格
                        {
                            if (s[index[j]][k] == '\0')
                                break;
                            if (s[index[j]][k] == ' ')
                                continue;
                            s2 += s[index[j]][k];
                        }
                        if (s1 > s2)//比较除去空格的字符并排序
                        {
                            int temp = index[i];
                            index[i] = index[j];
                            index[j] = temp;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)//输出
    {
        for (int j = 0; j < 2; j++)
        {
            cout << grade[index[i]][j] << " ";
        }
        cout << s[index[i]] << endl;
    }
}