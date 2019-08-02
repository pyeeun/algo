#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int check[11];
int matrix[11][11];
int n, m;
int maxnum;
void solve(int a, int answer)
{
	if (maxnum < answer)
		maxnum = answer;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (matrix[a][i] == 1 && check[i] == 0)
		{
			check[i] = 1;
			solve(i, answer + 1);
			check[i] = 0;
		}
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int i;
	int a, b;
	while (t--)
	{
		maxnum = 0;
		memset(check, 0, sizeof(check));
		memset(matrix, 0, sizeof(matrix));
		scanf("%d %d", &n, &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			matrix[a][b] = 1;
			matrix[b][a] = 1;
		}
		for (i = 1; i <= n; i++)
		{
			check[i] = 1;
			solve(i, 1);
			check[i] = 0;
		}
		printf("#%d %d\n", temp - t, maxnum);
	}
}