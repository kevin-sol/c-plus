#include <bits/stdc++.h>
using namespace std;
struct state
{
    int type, id;
};

int main(int argc, char const *argv[])
{
    int T, n;
    scanf("%d %d", &T, &n);
    getchar();
    string str;
    bool judge = true;
    while (T--)
    {
        judge=true;
        queue<state> q[n];
        for (int i = 0; i < n; i++)
        {
            getline(cin, str);
            for (int j = 0; j < str.length(); j++)
            {
                state process;
                process.type = str[j] == 'S' ? 1 : 0;
                int id = 0;
                j++;
                while (str[j] != ' ' && j < str.length())
                {
                    id = id * 10 + (str[j++] - '0');
                }
                process.id = id;
                q[i].push(process);
            }
        }
        while (judge)
        {
            int failcnt = 0;
            int emptycnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (q[i].empty())
                {
                    emptycnt++;
                }
                else
                {
                    int next = q[i].front().id;
                    if (q[next].empty())
                    {
                        printf("1\n");
                        judge = false;
                        break;
                    }
                    else if (q[next].front().id == i && q[next].front().type != q[i].front().type)
                    {
                        q[i].pop();
                        q[next].pop();
                    }
                    else
                    {
                        failcnt++;
                    }
                }
            }
            if (emptycnt == n)
            {
                printf("0\n");
                break;
            }
            if (failcnt==n-emptycnt)
            {
                printf("1\n");
                break;
            }
            
        }
    }
    return 0;
}
