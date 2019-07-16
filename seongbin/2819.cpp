#include <iostream>
#include <string.h>
using namespace std;

//»óÇÏÁÂ¿ì
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int matrix[4][4];
int num[10000000] = { 0 };
int answer = 0;

void solve(int x, int y, int n, char str[8])
{
	str[n] = ((char)matrix[y][x] + 48);
	if (n < 6)
	{
		int d;
		int nx, ny;
		for (d = 0; d < 4; d++)
		{
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
				solve(nx, ny, n + 1, str);
		}
	}
	else
	{
		int k = 1;
		int n = 0;
		int d;
		for (d = 6; d >= 0; d--)
		{
			n += k * ((int)str[d] - 48);
			k *= 10;
		}

		if (num[n] == 0)
		{
			num[n] = 1;
			answer++;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	int i, j;
	int temp = t;
	char str[8];
	str[7] = '\0';
	while (t--)
	{
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &(matrix[i][j]));
		
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				solve(j, i, 0, str);

		printf("#%d %d\n", temp - t, answer);
		answer = 0;
		memset(num, 0, sizeof(num));
	}
	
	return 0;
}