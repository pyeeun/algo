#include <iostream>
#include <string.h>
using namespace std;
int matrix[4][8][8];

int main()
{
	int t;
	scanf("%d", &t);
	int temp = t;
	int n;
	int i, j;
	int x, y;
	int k;

	while (t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &(matrix[0][i][j]));

		printf("#%d\n", temp - t);


		for (k = 0; k < 4; k++)
		{
			y = 0;
			for (i = 1; i <= n; i++)
			{
				y++;
				x = 0;
				for (j = n; j >= 1; j--)
				{
					x++;
					matrix[k + 1][y][x] = matrix[k][j][i];
				}
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (k = 1; k < 4; k++)
			{
				for (j = 1; j <= n; j++)
				{
					printf("%d", matrix[k][i][j]);
				}
				printf(" ");
			}
			printf("\n");
		}
	
	}
	memset(matrix, 0, sizeof(matrix));
	return 0;
}