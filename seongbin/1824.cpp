#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

//»óÇÏÁÂ¿ì
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int check[20][20][4][16]; //check[i][j][dindex][memeory];
char matrix[20][20];
int r, c;
int f = 0;
int solve(int i, int j, int mem, int d)
{
	if (check[i][j][d][mem] == 1)
		return 0;
	else
		check[i][j][d][mem] = 1;

	if (matrix[i][j] == '<')
		d = 2;
	else if (matrix[i][j] == '>')
		d = 3;
	else if (matrix[i][j] == '^')
		d = 0;
	else if (matrix[i][j] == 'v')
		d = 1;
	else if (matrix[i][j] == '_')
	{
		if (mem == 0)
			d = 3;
		else
			d = 2;
	}
	else if (matrix[i][j] == '|')
	{
		if (mem == 0)
			d = 1;
		else
			d = 0;
	}
	else if (matrix[i][j] == '@')
		return 1;
	else if (matrix[i][j] >= '0' && matrix[i][j] <= '9')
		mem = (int)matrix[i][j] - 48;
	else if (matrix[i][j] == '+')
		mem = (mem + 1) % 16;
	else if (matrix[i][j] == '-')
		mem = (mem + 15) % 16;

	if (matrix[i][j] != '?')
	{
		i = i + dy[d];
		j = j + dx[d];
		if (i == -1)
			i = r - 1;
		else if (i == r)
			i = 0;
		else if (j == -1)
			j = c - 1;
		else if (j == c)
			j = 0;
		
		return max(0, solve(i, j, mem, d));
	}
	else
	{
		int tempi, tempj;
		int ans = 0;
		for (d = 0; d < 4; d++)
		{
			tempi = i + dy[d];
			tempj = j + dx[d];
			if (tempi == -1)
				tempi = r - 1;
			else if (tempi == r)
				tempi = 0;
			else if (tempj == -1)
				tempj = c - 1;
			else if (tempj == c)
				tempj = 0;
			ans = max(ans, solve(tempi, tempj, mem, d));
		}
		return ans;
	}
	
}
int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;


	int i, j;
	int memory;
	int dindex;
	int stop;
	int answer;
	while (t--)
	{
		answer = 0;
		dindex = 3;
		memory = 0;
		memset(check, 0, sizeof(check));
		scanf("%d %d", &r, &c);
		stop = 0;
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				scanf("%c", &(matrix[i][j]));
				if (matrix[i][j] == '@')
					stop++;
				if (matrix[i][j] == '\n')
					j--;
			}

		}

		if (stop == 0)
		{
			printf("#%d NO\n", temp - t);
			continue;
		}
		
		answer = solve(0, 0, 0, 3);
		if (answer == 1)
			printf("#%d YES\n", temp - t);
		else
			printf("#%d NO\n", temp - t);
	}
	return 0;
}