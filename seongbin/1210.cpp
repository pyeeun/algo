#include <iostream>
using namespace std;

int matrix[100][100];

int main()
{
	int n;
	int i, j;
	int x, y;
	int nx, ny;
	for (int k = 0; k < 10; k++)
	{
		scanf("%d", &n);
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
			{
				scanf("%d", &(matrix[i][j]));
				if (matrix[i][j] == 2)
				{
					x = j, y = i;
				}
			}
		}

		y--;
		while (y != 0)
		{
			if (x - 1 >= 0 && matrix[y][x - 1] == 1)
			{
				while (x - 1 >= 0 && matrix[y][x - 1] == 1)
				{
					x = x - 1;
				}
				y = y - 1;
			}
			else if (x + 1 < 100 && matrix[y][x + 1] == 1)
			{
				while (x + 1 < 100 && matrix[y][x + 1] == 1)
				{
					x = x + 1;
				}
				y = y - 1;
			}
			else
				y = y - 1;
		}
		printf("#%d %d\n", n, x);
	}
	return 0;
}