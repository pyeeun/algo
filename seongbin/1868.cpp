#include <iostream>
using namespace std;
//상 에서 부터 시작하여 시계방향
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int mine;
char matrix[300][300];
int n;

int near_mine_num(int i, int j)
{
	int m = 0;
	int d, nx, ny;
	for (d = 0; d < 8; d++)
	{
		nx = j + dx[d];
		ny = i + dy[d];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (matrix[ny][nx] == '*')
				m++;
		}
	}
	return m;
}
void solve(int i, int j)
{
	int m = 0;
	int d;
	int nx, ny;
	m = near_mine_num(i, j);
	matrix[i][j] = (char)(m + 48);
	mine++;
	if (m == 0)
	{
		for (d = 0; d < 8; d++)
		{
			nx = j + dx[d];
			ny = i + dy[d];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (matrix[ny][nx] == '.')
					solve(ny, nx);
			}
		}
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int answer = 0;
	int i, j;
	
	while (t--)
	{
		mine = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%c", &(matrix[i][j]));
				if (matrix[i][j] == '\n')
					j--;
				else if (matrix[i][j] == '*')
					mine++;
			}
		}
		i = 0, j = 0;
		for(i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] == '.')
				{
					if (near_mine_num(i, j) == 0)
					{
						solve(i, j);
						answer++;
					}
				}
			}
		}
		answer += (n * n - mine);
		printf("#%d %d\n", temp - t, answer);
		answer = 0;
	}
	return 0;
}