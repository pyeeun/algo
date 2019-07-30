#include <iostream>
using namespace std;

int matrix[100][100];

int main()
{
	int n;
	int i, j;
	int x, y;
	int startx[100];
	int starty[100];
	int startindex;
	int mintimes;
	int min_x;
	int times;
	for (int k = 0; k < 10; k++)
	{
		scanf("%d", &n);
		startindex = 0;
		mintimes = 0;
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
			{
				scanf("%d", &(matrix[i][j]));
				if (i == 0 && matrix[i][j] == 1)
				{
					startx[startindex] = j;
					starty[startindex++] = i;
				}
			}
		}
		
		for (i = 0; i < startindex; i++)
		{
			x = startx[i];
			y = starty[i];
			y++;
			times = 1;
			while (y < 100)
			{
				if (x - 1 >= 0 && matrix[y][x - 1] == 1)
				{
					while (x - 1 >= 0 && matrix[y][x - 1] == 1)
					{
						x = x - 1;
						times++;
					}
					y = y + 1;
				}
				else if (x + 1 < 100 && matrix[y][x + 1] == 1)
				{
					while (x + 1 < 100 && matrix[y][x + 1] == 1)
					{
						x = x + 1;
						times++;
					}
					y = y + 1;
				}
				else
					y = y + 1;
				times++;
			}

			if (mintimes == 0)
			{
				mintimes = times;
				min_x = startx[i];
			}
			else if (mintimes > times)
			{
				mintimes = times;
				min_x = startx[i];
			}
		}
		printf("#%d %d\n", n, min_x);
	}
	return 0;
}