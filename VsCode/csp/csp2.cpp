#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define MOD 998244353
using namespace std;
int cnt = 0;
int ch[60][26];		//用于AC自动机的字典树
int fail[60];		//AC自动机fail
bool mark[60];		//自动机的终止状态
int n, m, K;
int Out[60][26];	//明文->密文
int Next[60][26];	//转换页数
char s[60][60];		//词典
int Len[60];		//词典中单词长度
int Q[60];			//建立AC自动机fail时BFS使用的队列
long long F[1010][51][51];//F[i][j][k]代表长度为i，密文匹配在第j个节点，且正在查看解密码本第k页的铭文个数
long long Ans[1010];
void newnode(int x)
{
	int i;
	for (i = 0; i < 26; i++) ch[x][i] = 0;
	fail[x] = 0;
	mark[x] = false;
}
void insert(char *s)
{
	int i, k;
	int len = strlen(s);
	int x = 0;
	for (i = 0; i < len; i++)
	{
		k = s[i] - 'a';
		if (ch[x][k] == 0)
		{
			cnt++;
			ch[x][k] = cnt;
			newnode(ch[x][k]);
		}
		x = ch[x][k];
	}
	mark[x] = true;
}
void build()
{
	int i;
	int L = 0, R = 0;
	for (i = 0; i < 26; i++)
	{
		if (ch[0][i])
		{
			R++;
			Q[R] = ch[0][i];
		}
	}
	while (L < R)
	{
		L++;
		int x = Q[L];
		for (i = 0; i < 26; i++)
		{
			if (ch[x][i])
			{
				fail[ch[x][i]] = ch[fail[x]][i];
				mark[ch[x][i]] |= mark[fail[ch[x][i]]];
				R++;
				Q[R] = ch[x][i];
			}
			else {
				ch[x][i] = ch[fail[x]][i];
			}
		}
	}
}
void solve()
{
	int i, j, k, l, ll;
	F[0][0][1] = 1;
	for (i = 0; i <= m; i++)  //长度为1-m
	{
		for (j = 0; j <= cnt; j++)  //遍历AC自动机所有节点
		{
			for (k = 1; k <= n; k++)  //遍历所有页
			{
				if (F[i][j][k])
				{
					F[i][j][k] = F[i][j][k] % MOD;
					Ans[i] = Ans[i] + F[i][j][k];
					bool flag = false;
					int tj, tk, x;
					for (l = 0; l < K; l++)   //遍历所有词典里面的语句
					{
						if (i + Len[l] > m) continue;
						flag = true;
						tj = j;
						tk = k;
						for (ll = 0; ll < Len[l]; ll++)
						{
							x = Out[tk][s[l][ll]];
							tk = Next[tk][s[l][ll]];
							tj = ch[tj][x];
							if (mark[tj])
							{
								flag = false; break;
							}
						}
						if (flag) F[i + Len[l]][tj][tk] = F[i + Len[l]][tj][tk] + F[i][j][k];
					}
				}
			}
		}
	}
	for (i = 1; i <= m; i++)
	{
		Ans[i] = Ans[i] % MOD;
		cout << Ans[i] << endl;
	}
}
int main()
{
	int i, j;
	cnt = 0;
	newnode(0);
	cin >> n >> m;              //输入n，m
	for (i = 0; i < 26; i++)    //输入解密密码本
	{
		for (j = 1; j <= n; j++)    //n 页
		{
			char S[1010];
			scanf("%s", S);
			Out[j][S[0] - 'a'] = i;   //提取出密文字母
			int len = strlen(S);
			int v = 0;                //提取出对应的跳转的页数
			if (len == 2) v = S[1] - '0';
			else v = (S[1] - '0') * 10 + S[2] - '0';
			Next[j][S[0] - 'a'] = v;  //提取出密文对应的跳转的页数  
		}
	}
	K = 0;
	while (scanf("%s", s[K]) != EOF)   //输入词典
	{
		insert(s[K]);
		Len[K] = strlen(s[K]);         //AC自动机的模板串的建立
		for (i = 0; i < Len[K]; i++)
			s[K][i] = s[K][i] - 'a';
		K++;
	}
	build();           //AC自动机的fail指针的建立
	solve();           //求解过程，包括动态规划以及字符串匹配
	return 0;
}
