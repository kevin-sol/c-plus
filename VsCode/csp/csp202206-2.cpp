#include <iostream>
using namespace std;
#define MAX 5001




int Map(int l[][MAX], int s[][51], int L, int S)
{
	int ret = 0;
	for (int i = 0; i < L - S+1; ++i)
	{
		for (int j = 0; j < L - S+1; ++j)
		{
			int flag = 1;
			if (l[i][j] == 1)
			{
				for (int k = 0; k < S + 1; ++k)
				{
					for (int m = 0; m < S + 1; ++m)
					{
						if (s[k][m] != l[i + k][j + m])
						{
							flag = 0;
						}
					}
				}
			}
			else
			{
				continue;
			}

			if (flag == 1)
			{
				ret++;
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	long long n, L, S;
	cin >> n >> L >> S;
	/*int **l = new int *[L + 1];
	for (int i = 0; i < L + 1; i++)
	{
		l[i] = new int[MAX];
	}*/
	int l[L+1][MAX];
	int s[S + 1][51];
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		l[x][y] = 1;
	}
	for (int i = S; i >= 0; --i)
	{
		for (int j = 0; j < S + 1; ++j)
		{
			cin >> s[i][j];
		}
	}
	printf("%d\n", Map(l, s, L, S));
	system("pause");
	return 0;
}
/*
5 100 2
0 0
1 1
2 2
3 3
4 4
0 0 1
0 0 0
1 0 0
*/