#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int matrix[20][20];
int n;
int up_diagonal, down_diagonal;
int dx[4] = { 1, -1, -1, 1 };
int dy[4] = { 1, 1, -1, -1 };
int dessert[101] = { 0 };

int check()
{
	int k = 0;
	int a, b; //ÁÂÇ¥
	int x, y; //tempÁÂÇ¥
	int i;
	int alright;
	int dindex;

	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			if (up_diagonal > b || down_diagonal > n - 1 - b)
				continue;
			if (up_diagonal + down_diagonal > n - 1 - a)
				continue;

			alright = 1;
			x = b, y = a;
			memset(dessert, 0, sizeof(dessert));
			//dessert[matrix[a][b]] = 1;

			for (dindex = 0; dindex < 4; dindex++)
			{
				if (dindex % 2 == 0)
				{
					for (i = 0; i < down_diagonal; i++)
					{
						x += dx[dindex];
						y += dy[dindex];
						if (dessert[matrix[y][x]] == 1)
						{
							alright = 0;
							break;
						}
						else
							dessert[matrix[y][x]] = 1;
					}
				}
				else
				{
					for (i = 0; i < up_diagonal; i++)
					{
						x += dx[dindex];
						y += dy[dindex];
						if (dessert[matrix[y][x]] == 1)
						{
							alright = 0;
							break;
						}
						else
							dessert[matrix[y][x]] = 1;
					}
				}
				if (alright == 0)
					break;
			}
			if (alright == 1)
				break;
		}
		if (alright == 1)
			break;
	}

	return alright;
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int answer;
	int i, j;
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &(matrix[i][j]));
		
		answer = -1;
		for (up_diagonal = 1; up_diagonal < n; up_diagonal++)
		{
			for (down_diagonal = 1; down_diagonal < n; down_diagonal++)
			{
				if (up_diagonal + down_diagonal >= n)
					break;

				if (check() == 1)
					answer = max(answer, 2 * (up_diagonal + down_diagonal));
			}
		}
		printf("#%d %d\n", temp - t, answer);
	}

	return 0;
}